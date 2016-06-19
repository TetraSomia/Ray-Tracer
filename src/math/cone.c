/*
** cone.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Feb 15 19:18:53 2016 Arthur Josso
** Last update Thu Apr 14 14:37:30 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

static void	get_sol(t_ray *r, t_cone *c, float *sol)
{
  t_vec		cst;
  float		delta;
  float		a;

  a = POW(c->angle);
  cst.x = POW(r->beta.x) + POW(r->beta.y) - POW(r->beta.z) * a;
  cst.y = 2 * (r->alpha.x * r->beta.x + r->alpha.y * r->beta.y
	       - c->meta.pos.x * r->beta.x - c->meta.pos.y * r->beta.y
	       + a * r->beta.z * (c->meta.pos.z - r->alpha.z));
  cst.z = 2 * (a * c->meta.pos.z * r->alpha.z
	       - c->meta.pos.x * r->alpha.x
	       - c->meta.pos.y * r->alpha.y)
    + POW(c->meta.pos.x) + POW(c->meta.pos.y) - a * POW(c->meta.pos.z)
    + POW(r->alpha.x) + POW(r->alpha.y) - a * POW(r->alpha.z);
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

static float	get_hit(t_ray *ray, t_cone *cone)
{
  float		sol[2];

  get_sol(ray, cone, sol);
  if (sol[0] < 0 && sol[1] < 0)
    return (-1);
  if (sol[0] < 0)
    return (sol[1]);
  if (sol[1] < 0)
    return (sol[0]);
  return (sol[0] < sol[1] ? sol[0] : sol[1]);
}

void	find_k_cone(t_ray *ray, t_obj *obj, t_hit *hit)
{
  float	k;
  int	i;
  t_ray rot_ray;

  i = 0;
  while (i < obj->nb.cone)
    {
      rot_ray = get_rot_ray(*ray, &obj->cone[i].meta.rot);
      k = get_hit(&rot_ray, &obj->cone[i]);
      if (k < hit->k && k != -1)
	{
	  hit->k = k;
	  hit->obj = (void*)&obj->cone[i];
	  hit->obj_type = CONE;
	  hit->meta = obj->cone[i].meta;
	}
      i++;
    }
}
