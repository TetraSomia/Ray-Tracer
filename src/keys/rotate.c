/*
** rotate.c for rotate in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 16:43:59 2016 alies_a
** Last update Wed Apr 20 16:48:53 2016 alies_a
*/

#include "rt.h"
#include "core.h"

int	key_left_rotate(t_data *data)
{
  (data->obj.cam).rot.z += ROT;
  return (0);
}

int	key_right_rotate(t_data *data)
{
  (data->obj.cam).rot.z -= ROT;
  return (0);
}

int	key_up_rotate(t_data *data)
{
  (data->obj.cam).rot.y -= ROT;
  return (0);
}

int	key_down_rotate(t_data *data)
{
  (data->obj.cam).rot.y += ROT;
  return (0);
}
