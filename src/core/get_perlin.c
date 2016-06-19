/*
** texture.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Feb 16 18:33:58 2016 Arthur Josso
** Last update Sat Feb 20 19:20:10 2016 Arthur Josso
*/

#include "rt.h"

t_color			get_perlin_at(t_vec *pt, t_meta *meta)
{
  t_color		color;
  float			coef;

  color = meta->color;
  coef = perlin(meta->perlin.tab, pt, meta->perlin.persis);
  if (meta->perlin.type == 1)
    {
      coef *= 10;
      coef = coef - (int)coef;
      coef += 0.4;
      if (coef > 1)
	coef = 1;
    }
  color = get_color(&color, coef);
  return (color);
}
