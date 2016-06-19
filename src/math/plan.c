/*
** plan.c for rt in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Apr 15 17:51:42 2016 Arthur Josso
** Last update Wed Apr 27 13:30:49 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

static float	get_hit(t_ray *r, t_plan *p)
{
  float		c1;
  float		c2;

  c1 = p->meta.rot.x * r->beta.x
    + p->meta.rot.y * r->beta.y
    + p->meta.rot.z * r->beta.z;
  c2 = p->meta.rot.x * (r->alpha.x - p->meta.pos.x)
    + p->meta.rot.y * (r->alpha.y - p->meta.pos.y)
    + p->meta.rot.z * (r->alpha.z - p->meta.pos.z);
  return (-c2 / c1);
}

void	find_k_plan(t_ray *ray, t_obj *obj, t_hit *hit)
{
  float	k;
  int	i;
  char	mod;

  i = -1;
  while (++i < obj->nb.plan)
    {
      k = get_hit(ray, &obj->plan[i]);
      if (k < hit->k && k >= 0)
	{
	  hit->k = k;
	  hit->obj = (void*)&obj->plan[i];
	  hit->obj_type = PLAN;
	  hit->meta = obj->plan[i].meta;
	  if (obj->plan[i].ground)
	    {
	      hit->pt = get_pt_with_k(hit->k, ray);
	      mod = hit->pt.x * hit->pt.y > 0 ? 1 : 0;
	      hit->meta.color.full = ABS((int)hit->pt.x + (int)hit->pt.y)
		% 2 == mod ? WHITE : BLACK;
	      hit->meta.reflec = 1;
	      hit->meta.mirroring = 0.4;
	    }
	}
    }
}
