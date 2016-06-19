/*
** phong.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Feb  7 19:45:15 2016 Arthur Josso
** Last update Wed Apr 27 11:55:29 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

static t_ray	get_light_ray(t_vec *light_pos, t_vec *hit_pos)
{
  t_ray		ray;

  ray.alpha = *light_pos;
  ray.beta = get_uni_vec(light_pos, hit_pos);
  return (ray);
}

static t_color	get_complement(t_color *c, float coef)
{
  t_color	add;

  add.argb[RED_CMP] = (255 - c->argb[RED_CMP]) * coef + c->argb[RED_CMP];
  add.argb[BLUE_CMP] = (255 - c->argb[BLUE_CMP]) * coef + c->argb[BLUE_CMP];
  add.argb[GREEN_CMP] = (255 - c->argb[GREEN_CMP]) * coef + c->argb[GREEN_CMP];
  return (add);
}

static t_color	color_after_phong(t_data *data, t_hit *hit, int light)
{
  t_vec		r;
  t_ray		l;
  t_vec		v;
  float		coef;
  t_hit		light_hit;

  v = get_uni_vec(&hit->pt, &data->obj.cam.pos);
  l = get_light_ray(&data->obj.light[light].pos, &hit->pt);
  find_hit(data, &l, &light_hit);
  r = get_reflec_vec(&hit->n, &l.beta);
  coef = get_dot(&v, &r);
  coef *= hit->meta.reflec;
  if (coef > 0 || hit->obj != light_hit.obj)
    return (hit->meta.color);
  else
    {
      coef = coef < -1 ? 1 : -coef;
      coef = pow(coef, PHONG_SIZE);
      return (get_complement(&hit->meta.color, coef));
    }
}

void		phong(t_data *data, t_hit *hit)
{
  int		i;
  t_color	color;
  int		red;
  int		green;
  int		blue;

  i = 0;
  red = 0;
  green = 0;
  blue = 0;
  while (i < data->obj.nb.light)
    {
      color = color_after_phong(data, hit, i);
      red += color.argb[RED_CMP];
      green += color.argb[GREEN_CMP];
      blue += color.argb[BLUE_CMP];
      i++;
    }
  if (hit->obj_type != PLAN)
    {
      color.argb[RED_CMP] = red / data->obj.nb.light;
      color.argb[GREEN_CMP] = green / data->obj.nb.light;
      color.argb[BLUE_CMP] = blue / data->obj.nb.light;
      hit->meta.color = color;
    }
}
