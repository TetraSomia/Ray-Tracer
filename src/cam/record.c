/*
** record.c for rec in /home/alies_a/rendu/gfx_raytracer2/src/cam
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 19:12:54 2016 alies_a
** Last update Wed Apr 20 19:41:32 2016 alies_a
*/

#include "core.h"
#include "rt.h"
#include "jif.h"
#include "cam.h"

static void             red_surround(t_bunny_pixelarray *pix)
{
  t_bunny_position      pos;
  t_color               c;

  c.full = RED;
  pos.x = 0;
  pos.y = 0;
  while (pos.x++ < pix->clipable.clip_width)
    tekpixel(pix, &pos, &c);
  pos.x -= 2;
  while (pos.y++ < pix->clipable.clip_height)
    tekpixel(pix, &pos, &c);
  pos.y -= 2;
  while (pos.x-- > 0)
    tekpixel(pix, &pos, &c);
  pos.x += 1;
  while (pos.y-- > 0)
    tekpixel(pix, &pos, &c);
}

int     cam_record(t_data *data)
{
  if (!(data->gen_type & IS_RECORD))
    return (0);
  if (cam_path_write(data->path, &(data->obj.cam)))
    return (1);
  red_surround(data->pix);
  return (0);
}
