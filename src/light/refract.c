/*
** refract.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Feb 18 12:57:22 2016 Arthur Josso
** Last update Sat Apr 16 16:32:05 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

static t_vec	get_refract_vec(t_vec *v, t_vec *n, float indice)
{
  t_vec		r;
  float		n_mult;

  r.x = 0;
  r.y = 0;
  r.z = 0;
  n_mult = 1 - POW(indice) * (1 - POW(get_dot(v, n)));
  if (n_mult < 0)
    return (r);
  n_mult = (get_dot(v, n) * indice) - sqrt(n_mult);
  r.x = n_mult * n->x - indice * v->x;
  r.y = n_mult * n->y - indice * v->y;
  r.z = n_mult * n->z - indice * v->z;
  return (r);
}

static int	get_refract_hit(t_data *data,
				t_hit *prev_hit,
				t_hit *hit,
				float indice)
{
  t_ray		ray;
  t_vec		v;

  ray.alpha = prev_hit->pt;
  v = get_uni_vec(&prev_hit->pt, &data->obj.cam.pos);
  if (indice > 1)
    inv_vec(&prev_hit->n);
  set_uni_vec(&prev_hit->n);
  ray.beta = get_refract_vec(&v, &prev_hit->n, indice);
  if (ray.beta.x == 0 && ray.beta.y == 0 && ray.beta.z == 0)
    return (1);
  set_uni_vec(&ray.beta);
  ray.alpha.x += PREC * ray.beta.x;
  ray.alpha.y += PREC * ray.beta.y;
  ray.alpha.z += PREC * ray.beta.z;
  find_hit(data, &ray, hit);
  return (0);
}

static void	get_reflec_color(t_color *dest, t_color *src, float coef)
{
  dest->argb[RED_CMP] = (1 - coef) * dest->argb[RED_CMP]
    + coef * src->argb[RED_CMP];
  dest->argb[GREEN_CMP] = (1 - coef) * dest->argb[GREEN_CMP]
    + coef * src->argb[GREEN_CMP];
  dest->argb[BLUE_CMP] = (1 - coef) * dest->argb[BLUE_CMP]
    + coef * src->argb[BLUE_CMP];
}

void	refract(t_data *data, t_hit *vision_hit)
{
  t_hit	first_hit;
  t_hit	second_hit;

  if (get_refract_hit(data, vision_hit, &first_hit,
		      I_AIR / vision_hit->meta.refrac.indice) == 1)
    second_hit.meta.color.full = BLACK;
  else if (get_refract_hit(data, &first_hit, &second_hit,
			   vision_hit->meta.refrac.indice / I_AIR) == 1)
    second_hit.meta.color.full = BLACK;
  else if (second_hit.obj_type != NONE)
    {
      light(data, &second_hit);
      if (data->gen_type & IS_PHONG)
	phong(data, &second_hit);
      if (data->gen_type & IS_REFLEC)
	reflect(data, &second_hit);
    }
  else
    second_hit.meta.color.full = BLACK;
  get_reflec_color(&vision_hit->meta.color, &second_hit.meta.color,
		   vision_hit->meta.refrac.ratio);
}
