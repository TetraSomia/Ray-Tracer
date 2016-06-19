/*
** path_write.c for write in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 19:20:21 2016 alies_a
** Last update Wed Apr 20 19:40:10 2016 alies_a
*/

#include <unistd.h>
#include "core.h"
#include "jif.h"
#include "cam.h"

int     cam_path_write(t_cam_path *path, const t_cam *cam)
{
  int   w;

  if (path->mode != J_WRITE)
    return (1);
  w = write(path->fd, cam, sizeof(t_cam));
  if (w != sizeof(t_cam))
    return (1);
  return (0);
}
