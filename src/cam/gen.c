/*
** gen.c for gen in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 19:24:51 2016 alies_a
** Last update Wed Apr 20 19:27:57 2016 alies_a
*/

#include "rt.h"
#include "core.h"
#include "jif.h"
#include "my.h"
#include "cam.h"

static void     cam_init_gen(t_data *data,
			     t_cam *old,
			     t_bunny_position *origin)
{
  origin->x = 0;
  origin->y = 0;
  my_memset(old, 0, sizeof(t_cam));
  data->gen_type = 255;
  data->gen_type ^= IS_AA;
  data->gen_type ^= IS_PREVIEW;
}

int                     cam_gen(t_data *data)
{
  t_cam                 cam;
  t_cam                 old;
  t_bunny_position      origin;

  cam_init_gen(data, &old, &origin);
  while (cam_path_read(data->path, &cam) == 0)
    {
      data->pix = data->big;
      data->obj.cam = cam;
      if (my_memcmp(&cam, &old, sizeof(t_cam)) != 0)
	gen_scene(data);
      old = cam;
      if (jif_add(data->jif, data->pix))
	return (1);
      bunny_blit(&data->win->buffer, &data->pix->clipable, &origin);
      bunny_display(data->win);
    }
  return (0);
}
