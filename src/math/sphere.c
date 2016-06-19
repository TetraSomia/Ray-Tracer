/*
** sphere.c for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jan 29 21:02:18 2016 Arthur Josso
** Last update Thu Apr 14 14:36:21 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

static void	get_sol(t_ray *r, t_sphere *s, float *sol)
{
  t_vec		cst;
  float		delta;

  cst.x = POW(r->beta.x) + POW(r->beta.y) + POW(r->beta.z);
  cst.y = 2 * (r->beta.x * (r->alpha.x - s->meta.pos.x)
	       + r->beta.y * (r->alpha.y - s->meta.pos.y)
	       + r->beta.z * (r->alpha.z - s->meta.pos.z));
  cst.z = -2 * (s->meta.pos.x * r->alpha.x
		+ s->meta.pos.y * r->alpha.y
		+ s->meta.pos.z * r->alpha.z)
    + POW(s->meta.pos.x) + POW(s->meta.pos.y) + POW(s->meta.pos.z) -
    POW(s->radius)
    + POW(r->alpha.x) + POW(r->alpha.y) + POW(r->alpha.z);
  delta = POW(cst.y) - (4 * cst.x * cst.z);
  if (delta < 0 || cst.x == 0)
    {
      sol[0] = -1;
      sol[1] = -1;
    }
  else
    {
      sol[0] = (-(cst.y) + sqrt(delta)) / (2 * cst.x);
      sol[1] = (-(cst.y) - sqrt(delta)) / (2 * cst.x);
    }
}

static float	get_hit(t_ray *ray, t_sphere *sphere)
{
  float		sol[2];

  get_sol(ray, sphere, sol);
  if (sol[0] < 0 && sol[1] < 0)
    return (-1);
  if (sol[0] < 0)
    return (sol[1]);
  if (sol[1] < 0)
    return (sol[0]);
  return (sol[0] < sol[1] ? sol[0] : sol[1]);
}

void	find_k_sphere(t_ray *ray, t_obj *obj, t_hit *hit)
{
  float	k;
  int	i;

  i = 0;
  while (i < obj->nb.sphere)
    {
      k = get_hit(ray, &obj->sphere[i]);
      if (k < hit->k && k != -1)
	{
	  hit->k = k;
	  hit->obj = (void*)&obj->sphere[i];
	  hit->obj_type = SPHERE;
	  hit->meta = obj->sphere[i].meta;
	  if (obj->sphere[i].meta.tex)
	    hit->meta.color = get_tex_at(ray, k, &obj->sphere[i]);
	}
      i++;
    }
}
