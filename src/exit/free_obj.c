/*
** free_obj.c for rt in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu May 19 18:17:08 2016 Arthur Josso
** Last update Sat May 21 16:20:21 2016 Arthur Josso
*/

#include "rt.h"

static void	free_list(t_data *data)
{
  if (data->obj.nb.light)
    bunny_free(data->obj.light);
  if (data->obj.nb.plan)
    bunny_free(data->obj.plan);
  if (data->obj.nb.sphere)
    bunny_free(data->obj.sphere);
  if (data->obj.nb.cylinder)
    bunny_free(data->obj.cylinder);
  if (data->obj.nb.cone)
    bunny_free(data->obj.cone);
  if (data->obj.nb.torus)
    bunny_free(data->obj.torus);
  if (data->obj.nb.mobius)
    bunny_free(data->obj.mobius);
  if (data->obj.nb.mesh)
    bunny_free(data->obj.mesh);
}

static void	free_perlin_tab(t_data *data)
{
  int		i;

  i = 0;
  while (i < data->obj.nb.sphere)
    {
      if (data->obj.sphere[i].meta.perlin.tab)
	bunny_free(data->obj.sphere[i].meta.perlin.tab);
      i++;
    }
  i = 0;
  while (i < data->obj.nb.cylinder)
    {
      if (data->obj.cylinder[i].meta.perlin.tab)
	bunny_free(data->obj.cylinder[i].meta.perlin.tab);
      i++;
    }
}

void	free_objs(t_data *data)
{
  free_perlin_tab(data);
  free_list(data);
}
