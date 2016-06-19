/*
** torus.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Apr 12 17:42:54 2016 Arthur Josso
** Last update Thu Apr 14 17:34:37 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"
#include "solver.h"

static void	solv_4th_deg(t_4th_deg *e)
{
  t_cplx	roots[4];
  t_cplx	coef[5];
  int		nb_roots;

  coef[0] = new_c(e->a4, 0);
  coef[1] = new_c(e->a3, 0);
  coef[2] = new_c(e->a2, 0);
  coef[3] = new_c(e->a1, 0);
  coef[4] = new_c(e->a0, 0);
  nb_roots = solv_deg_4(coef, roots);
  e->nb_sol = get_real_c(nb_roots, roots, e->x);
}

static void     set_coef(t_ray *r, t_torus *t, t_4th_deg *e)
{
  double        g;
  double        h;
  double        i;
  double        j;
  double        k;
  double        l;

  g = 4 * POW(t->radius) * (POW(r->beta.x) + POW(r->beta.y));
  h = 8 * POW(t->radius) * (r->alpha.x * r->beta.x + r->alpha.y * r->beta.y);
  i = 4 * POW(t->radius) * (POW(r->alpha.x) + POW(r->alpha.y));
  j = POW(get_norm(1, &r->beta));
  k = 2 * get_dot(&r->beta, &r->alpha);
  l = POW(get_norm(1, &r->alpha)) + (POW(t->radius) - POW(t->width));
  e->a4 = POW(j);
  e->a3 = 2 * j * k;
  e->a2 = 2 * j * l + POW(k) - g;
  e->a1 = 2 * k * l - h;
  e->a0 = POW(l) - i;
}

static float	get_hit(t_ray *ray, t_torus *torus)
{
  t_4th_deg	eq;
  float		min;
  int		i;
  t_ray		trans_ray;

  trans_ray = *ray;
  trans_ray.alpha.x -= torus->meta.pos.x;
  trans_ray.alpha.y -= torus->meta.pos.y;
  trans_ray.alpha.z -= torus->meta.pos.z;
  set_coef(&trans_ray, torus, &eq);
  min = VIEW_RANGE;
  solv_4th_deg(&eq);
  i = 0;
  while (i < eq.nb_sol)
    {
      if (eq.x[i] > 0 && eq.x[i] < min)
	min = eq.x[i];
      i++;
    }
  return (min);
}

void	find_k_torus(t_ray *ray, t_obj *obj, t_hit *hit)
{
  float	k;
  int	i;
  t_ray	rot_ray;

  i = 0;
  while (i < obj->nb.torus)
    {
      rot_ray = get_rot_ray(*ray, &obj->torus[i].meta.rot);
      k = get_hit(&rot_ray, &obj->torus[i]);
      if (k < hit->k)
	{
	  hit->k = k;
	  hit->obj = (void*)&obj->torus[i];
	  hit->obj_type = TORUS;
	  hit->meta = obj->torus[i].meta;
	}
      i++;
    }
}
