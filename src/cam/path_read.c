/*
** path_read.c for read in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 19:21:55 2016 alies_a
** Last update Wed Apr 20 19:38:45 2016 alies_a
*/

#include <unistd.h>
#include "core.h"
#include "jif.h"
#include "cam.h"

int     cam_path_read(t_cam_path *path, t_cam *cam)
{
  int   r;

  if (path->mode != J_READ)
    return (1);
  r = read(path->fd, cam, sizeof(t_cam));
  if (r != sizeof(t_cam))
    return (1);
  return (0);
}
