/*
** mobius.c for rt in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Apr 16 15:11:17 2016 Arthur Josso
** Last update Mon Apr 18 16:06:53 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"
#include "solver.h"

static void	get_coef(t_ray *ray, t_mobius *mobius, double c[])
{
  double	a[6];
  double	r;

  r = mobius->radius;
  a[0] = ray->alpha.x;
  a[1] = ray->beta.x;
  a[2] = ray->alpha.y;
  a[3] = ray->beta.y;
  a[4] = ray->alpha.z;
  a[5] = ray->beta.z;
  c[0] = -2 * pow(a[1], 2) * a[5] + pow(a[3], 3) - 2 * pow(a[3], 2) * a[5]
    + a[3] * pow(a[5], 2) + pow(a[1], 2) * a[3];
  c[1] = 2 * a[0] * a[1] * a[3] - 4 * a[0] * a[1] * a[5] + pow(a[1], 2) *
    a[2] - 2 * pow(a[1], 2) * a[4] - 2 * a[1] * a[5] * r + 3 * a[2] *
    pow(a[3], 2) - 4 * a[2] * a[3] * a[5] + a[2] * pow(a[5], 2) - 2 *
    pow(a[3], 2) * a[4] + 2 * a[3] * a[4] * a[5];
  c[2] = pow(a[0], 2) * a[3] - 2 * pow(a[0], 2) * a[5] + 2 * a[0] * a[1] *
        a[2] - 4 * a[0] * a[1] * a[4] - 2 * a[0] * a[5] * r - 2 * a[1] * a[4] *
    r + 3 * pow(a[2], 2) * a[3] - 2 * pow(a[2], 2) * a[5] - 4 * a[2] * a[3] *
    a[4] + 2 * a[2] * a[4] * a[5] + a[3] * pow(a[4], 2) - a[3] * pow(r, 2);
  c[3] = pow(a[0], 2) * a[2] - 2 * pow(a[0], 2) * a[4] - 2 * a[0] * a[4] * r
    + pow(a[2], 3) - 2 * pow(a[2], 2) * a[4] + a[2] * pow(a[4], 2) -
    a[2] * pow(r, 2);
}

static int	get_sol(t_ray *ray, t_mobius *mobius, double sol[])
{
  t_cplx	coef[4];
  t_cplx	roots[3];
  double	c[4];
  int		nb_sol;

  get_coef(ray, mobius, c);
  coef[0] = new_c(c[0], 0);
  coef[1] = new_c(c[1], 0);
  coef[2] = new_c(c[2], 0);
  coef[3] = new_c(c[3], 0);
  nb_sol = solv_deg_3(coef, roots);
  return (get_real_c(nb_sol, roots, sol));
}

static float	get_hit_norm(t_vec *pt, t_vec *dir, t_mobius *mobius)
{
  t_vec		proj;
  t_vec		vec;
  float		norm;

  proj = *pt;
  proj.z = mobius->meta.pos.z;
  *dir = get_uni_vec(&mobius->meta.pos, &proj);
  mult_vec(mobius->radius, dir);
  vec = get_vec(dir, pt);
  norm = get_norm(1, &vec);
  return (norm);
}

static float    get_hit(t_ray *ray, t_mobius *mobius, t_vec *n)
{
  double	sol[3];
  int		nb_sol;
  int		i;
  float		min;
  t_vec		pt;
  t_vec		dir;

  nb_sol = get_sol(ray, mobius, sol);
  min = VIEW_RANGE;
  i = 0;
  while (i < nb_sol)
    {
      pt = get_pt_with_k(sol[i], ray);
      if (sol[i] > 0 && sol[i] < min && get_hit_norm(&pt, &dir, mobius) < 1)
	{
	  min = sol[i];
	  *n = get_mobius_n(&pt, &mobius->meta.pos, &dir);
	}
      i++;
    }
  return (min);
}

void	find_k_mobius(t_ray *ray, t_obj *obj, t_hit *hit)
{
  float	k;
  int	i;
  t_ray	trans_ray;

  i = 0;
  while (i < obj->nb.mobius)
    {
      trans_ray = *ray;
      trans_ray.alpha.x -= obj->mobius[i].meta.pos.x;
      trans_ray.alpha.y -= obj->mobius[i].meta.pos.y;
      trans_ray.alpha.z -= obj->mobius[i].meta.pos.z;
      k = get_hit(&trans_ray, &obj->mobius[i], &hit->n);
      if (k < hit->k && k >= 0)
	{
	  hit->k = k;
	  hit->obj = (void*)&obj->mobius[i];
	  hit->obj_type = MOBIUS;
	  hit->meta = obj->mobius[i].meta;
	}
      i++;
    }
}
