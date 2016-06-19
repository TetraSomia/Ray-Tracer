/*
** reflect.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Feb 11 16:26:07 2016 Arthur Josso
** Last update Sat Apr 16 16:32:48 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

static void	get_reflect_hit(t_data *data, t_hit *prev_hit, t_hit *hit)
{
  t_ray		ray;
  t_vec		v;

  ray.alpha = prev_hit->pt;
  v = get_uni_vec(&prev_hit->pt, &data->obj.cam.pos);
  set_uni_vec(&prev_hit->n);
  ray.beta = get_reflec_vec(&prev_hit->n, &v);
  set_uni_vec(&ray.beta);
  ray.alpha.x += PREC * ray.beta.x;
  ray.alpha.y += PREC * ray.beta.y;
  ray.alpha.z += PREC * ray.beta.z;
  find_hit(data, &ray, hit);
}

static void	get_reflec_color(t_color *dest, t_color *src, float coef)
{
  dest->argb[RED_CMP] = (1 - coef) * dest->argb[RED_CMP]
    + coef *  src->argb[RED_CMP];
  dest->argb[GREEN_CMP] = (1 - coef) * dest->argb[GREEN_CMP]
    + coef *  src->argb[GREEN_CMP];
  dest->argb[BLUE_CMP] = (1 - coef) * dest->argb[BLUE_CMP]
    + coef *  src->argb[BLUE_CMP];
}

void	reflect(t_data *data, t_hit *vision_hit)
{
  t_hit	hit;

  get_reflect_hit(data, vision_hit, &hit);
  if (hit.obj_type != NONE)
    {
      light(data, &hit);
      if (data->gen_type & IS_PHONG)
	phong(data, &hit);
      if (hit.meta.refrac.ratio && data->gen_type & IS_REFRAC)
	refract(data, &hit);
    }
  else
    hit.meta.color.full = BLACK;
  get_reflec_color(&vision_hit->meta.color, &hit.meta.color,
		   vision_hit->meta.mirroring);
}
