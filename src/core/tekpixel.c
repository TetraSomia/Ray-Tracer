/*
** tekpixel.c for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jan 29 18:33:34 2016 Arthur Josso
** Last update Fri Jan 29 18:33:34 2016 Arthur Josso
*/

#include <lapin.h>

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *p,
		 t_color *c)
{
  if (p->x >= 0 && p->x < pix->clipable.clip_width &&
      p->y >= 0 && p->y < pix->clipable.clip_height)
  ((unsigned int*)pix->pixels)[p->y * pix->clipable.clip_width + p->x]
    = c->full;
}
