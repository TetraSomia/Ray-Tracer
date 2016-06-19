/*
** toggle.c for toggle stuff in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 17:48:32 2016 alies_a
** Last update Wed Apr 20 18:00:41 2016 alies_a
*/

#include "core.h"
#include "rt.h"

int	key_preview(t_data *data)
{
  data->gen_type ^= IS_PREVIEW;
  return (0);
}

int	key_phong(t_data *data)
{
  data->gen_type ^= IS_PHONG;
  return (0);
}

int	key_refrac(t_data *data)
{
  data->gen_type ^= IS_REFRAC;
  return (0);
}

int	key_reflec(t_data *data)
{
  data->gen_type ^= IS_REFLEC;
  return (0);
}

int	key_aa(t_data *data)
{
  data->gen_type ^= IS_AA;
  return (0);
}
