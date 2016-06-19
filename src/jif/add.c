/*
** add.c for add in /home/alies_a/rendu/gfx_raytracer2/gif
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Apr 14 18:31:33 2016 alies_a
** Last update Fri Apr 15 11:31:41 2016 alies_a
*/

#include <unistd.h>
#include "jif.h"

static int	jif_write(const t_jif *jif, const t_bunny_pixelarray *pix)
{
  int		size;
  unsigned int	w;

  size = (pix->clipable).clip_width * (pix->clipable).clip_height;
  w = write(jif->fd, pix->pixels, sizeof(t_color) * size);
  if (w != sizeof(t_color) * size)
    return (1);
  return (0);
}

int	jif_add(const t_jif *jif, const t_bunny_pixelarray *pix)
{
  if (jif->mode != J_WRITE)
    return (1);
  if ((int)(jif->head).width != (pix->clipable).clip_width ||
      (int)(jif->head).height != (pix->clipable).clip_height)
    return (1);
  if (jif_write(jif, pix))
    return (1);
  return (0);
}
