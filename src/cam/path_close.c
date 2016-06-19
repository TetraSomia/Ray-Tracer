/*
** path_close.c for close in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 19:23:14 2016 alies_a
** Last update Fri May 13 14:52:59 2016 alies_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "jif.h"
#include "cam.h"

void    cam_path_close(t_cam_path *path)
{
  close(path->fd);
  bunny_free(path);
}
