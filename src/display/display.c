/*
** display.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Feb 20 15:52:49 2016 Arthur Josso
** Last update Sun Feb 21 18:12:26 2016 Arthur Josso
*/

#include "rt.h"

t_color         get_pix(t_data *data, t_vec *pos)
{
  t_ray         ray;
  t_hit         hit;

  get_ray(data, &data->obj.cam, pos, &ray);
  find_hit(data, &ray, &hit);
  if (hit.obj_type != NONE)
    {
      light(data, &hit);
      if (data->gen_type & IS_PHONG)
	phong(data, &hit);
      if (data->gen_type & IS_REFLEC)
	reflect(data, &hit);
      if (hit.meta.refrac.ratio && data->gen_type & IS_REFRAC)
	refract(data, &hit);
    }
  else
    hit.meta.color.full = BLACK;
  return (hit.meta.color);
}

static void             set_pix(t_data *data, t_bunny_position *pos)
{
  t_color               color;
  t_vec                 p;

  p.x = pos->x;
  p.y = pos->y;
  if (data->gen_type & IS_AA)
    color = anti_aliasing(data, &p);
  else
    color = get_pix(data, &p);
  tekpixel(data->pix, pos, &color);
}

void			gen_slice(t_data *data, int min, int max)
{
  t_bunny_position      pos;

  pos.x = 0;
  pos.y = min;
  while (pos.y < max)
    {
      set_pix(data, &pos);
      pos.x += 1;
      if (pos.x > data->pix->clipable.clip_width)
	{
	  pos.y += 1;
	  pos.x = 0;
	}
    }
}
