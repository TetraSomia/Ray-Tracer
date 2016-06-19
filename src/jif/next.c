/*
** next.c for next in /home/alies_a/rendu/gfx_raytracer2/gif
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Apr 14 20:26:14 2016 alies_a
** Last update Fri Apr 15 13:04:55 2016 alies_a
*/

#include <unistd.h>
#include "jif.h"

static int	jif_read(const t_jif *jif, t_bunny_pixelarray *pix)
{
  unsigned int	size;
  unsigned int	r;

  size = (pix->clipable).clip_width * (pix->clipable).clip_height;
  if (size != (jif->head).width * (jif->head).height)
    return (1);
  r = read(jif->fd, pix->pixels, sizeof(t_color) * size);
  if (r != sizeof(t_color) * size)
    return (1);
  return (0);
}

int	jif_next_fill(const t_jif *jif, t_bunny_pixelarray *pix)
{
  if (jif->mode != J_READ)
    return (1);
  if (jif_read(jif, pix))
    return (1);
  return (0);
}

t_bunny_pixelarray	*jif_next_load(const t_jif *jif)
{
  t_bunny_pixelarray	*res;

  if (jif->mode != J_READ)
    return (NULL);
  if ((res = bunny_new_pixelarray((jif->head).width,
				  (jif->head).height)) == NULL)
    return (NULL);
  if (jif_read(jif, res))
    {
      bunny_delete_clipable(&(res->clipable));
      return (NULL);
    }
  return (res);
}
