/*
** exit.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Feb 18 17:59:57 2016 Arthur Josso
** Last update Thu May 19 18:18:44 2016 Arthur Josso
*/

#include <unistd.h>
#include "rt.h"
#include "cam.h"

static void	free_tex(t_data *data)
{
  int		i;

  i = 0;
  while (i < data->obj.nb.sphere)
    {
      if (data->obj.sphere[i].meta.tex)
	bunny_delete_clipable(&data->obj.sphere[i].meta.tex->clipable);
      i++;
    }
}

static void	close_fd(t_data *data)
{
  int		i;

  i = 0;
  while (i < data->obj.nb.mesh)
    close(data->obj.mesh[i++].fd);
}

static void	free_vec_tab(t_vec **v)
{
  int		i;

  i = 0;
  while (v && v[i])
    bunny_free(v[i++]);
  if (v)
    bunny_free(v);
}

static void	free_obj(t_data *data)
{
  int		i;
  int		j;

  i = 0;
  while (i < data->obj.nb.mesh)
    {
      free_vec_tab(data->obj.mesh[i].v);
      free_vec_tab(data->obj.mesh[i].vn);
      free_vec_tab(data->obj.mesh[i].vt);
      j = 0;
      while (data->obj.mesh[i].tri && data->obj.mesh[i].tri[j])
	bunny_free(data->obj.mesh[i].tri[j++]);
      if (data->obj.mesh[i].tri)
	bunny_free(data->obj.mesh[i].tri);
      i++;
    }
}

void	exit_prog(t_data *data)
{
  bunny_delete_clipable(&data->big->clipable);
  bunny_delete_clipable(&data->small->clipable);
  free_tex(data);
  close_fd(data);
  free_obj(data);
  free_objs(data);
  cam_path_close(data->path);
  if (data->jif != NULL)
    jif_close(data->jif);
  bunny_stop(data->win);
}
