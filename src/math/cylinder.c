/*
** cylinder.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Feb  1 21:01:16 2016 Arthur Josso
** Last update Thu Apr 14 14:37:03 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

static void	get_sol(t_ray *r, t_cylinder *c, float *sol)
{
  t_vec		cst;
  float		delta;

  cst.x = POW(r->beta.x) + POW(r->beta.y);
  cst.y = 2 * (r->beta.x * (r->alpha.x - c->meta.pos.x)
	       + r->beta.y * (r->alpha.y - c->meta.pos.y));
  cst.z = -2 * (c->meta.pos.x * r->alpha.x
		+ c->meta.pos.y * r->alpha.y)
    + POW(c->meta.pos.x) + POW(c->meta.pos.y) - POW(c->radius)
    + POW(r->alpha.x) + POW(r->alpha.y);
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

static float	get_hit(t_ray *ray, t_cylinder *cylinder)
{
  float		sol[2];

  get_sol(ray, cylinder, sol);
  if (sol[0] < 0 && sol[1] < 0)
    return (-1);
  if (sol[0] < 0)
    return (sol[1]);
  if (sol[1] < 0)
    return (sol[0]);
  return (sol[0] < sol[1] ? sol[0] : sol[1]);
}

void	find_k_cylinder(t_ray *ray, t_obj *obj, t_hit *hit)
{
  float	k;
  int	i;
  t_ray	rot_ray;

  i = 0;
  while (i < obj->nb.cylinder)
    {
      rot_ray = get_rot_ray(*ray, &obj->cylinder[i].meta.rot);
      k = get_hit(&rot_ray, &obj->cylinder[i]);
      if (k < hit->k && k != -1)
	{
	  hit->k = k;
	  hit->obj = (void*)&obj->cylinder[i];
	  hit->obj_type = CYLINDER;
	  hit->meta = obj->cylinder[i].meta;
	}
      i++;
    }
}
