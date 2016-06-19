/*
** cam.c for cam in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 19:01:16 2016 alies_a
** Last update Wed Apr 20 19:02:06 2016 alies_a
*/

#include "core.h"
#include "rt.h"

int	key_record(t_data *data)
{
  data->gen_type ^= IS_RECORD;
  return (0);
}
