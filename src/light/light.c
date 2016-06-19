/*
** light.c for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Jan 31 19:55:37 2016 Arthur Josso
** Last update Sat Apr 16 16:30:34 2016 Arthur Josso
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

static float	color_after_light(t_data *data, t_hit *hit, int light)
{
  t_ray		l;
  float		coef;
  t_hit		light_hit;

  l = get_light_ray(&data->obj.light[light].pos, &hit->pt);
  find_hit(data, &l, &light_hit);
  coef = get_dot(&hit->n, &l.beta) * data->obj.light[light].power
    * hit->meta.reflec;
  if (coef >= 0 || hit->obj != light_hit.obj)
    return (0);
  else
    {
      coef *= -1;
      if (coef > 1)
	coef = 1;
      return (coef);
    }
}

void		light(t_data *data, t_hit *hit)
{
  int		i;
  float		coef;

  i = 0;
  coef = 0;
  while (i < data->obj.nb.light)
    {
      coef += color_after_light(data, hit, i);
      i++;
    }
  if (coef > 1)
  coef = 1;
  if (coef < AMBIENT)
    coef = AMBIENT;
  hit->meta.color = get_color(&hit->meta.color, coef);
}
