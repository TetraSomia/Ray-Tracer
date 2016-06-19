/*
** antialiasing.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Feb 16 12:33:30 2016 Arthur Josso
** Last update Wed Mar 16 11:41:35 2016 Arthur Josso
*/

#include "rt.h"

static void	add_c(t_color *color, t_color_sum *c)
{
  c->red += color->argb[RED_CMP];
  c->green += color->argb[GREEN_CMP];
  c->blue += color->argb[BLUE_CMP];
}

static void	div_c(t_color *color, t_color_sum *c)
{
  float		div;

  div = POW(ANTI_ALIASING);
  color->argb[RED_CMP] = c->red / div;
  color->argb[GREEN_CMP] = c->green / div;
  color->argb[BLUE_CMP] = c->blue / div;
}

t_color			anti_aliasing(t_data *data, t_vec *pos)
{
  t_vec			p;
  t_vec			new;
  t_color		color;
  t_color_sum		c;

  c.red = 0;
  c.green = 0;
  c.blue = 0;
  p.y = 0;
  while (p.y < ANTI_ALIASING)
    {
      p.x = 0;
      while (p.x < ANTI_ALIASING)
	{
	  new.x = pos->x + (p.x / ANTI_ALIASING);
	  new.y = pos->y + (p.y / ANTI_ALIASING);
	  color = get_pix(data, &new);
	  add_c(&color, &c);
	  p.x++;
	}
      p.y++;
    }
  div_c(&color, &c);
  return (color);
}
