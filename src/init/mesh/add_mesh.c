/*
** add_mesh.c for rt in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Apr 21 11:42:17 2016 Arthur Josso
** Last update Sun Apr 24 19:00:02 2016 Arthur Josso
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "init.h"
#include "mesh.h"

static int	add(t_mesh **item, int *nb_item, t_mesh new_item)
{
  t_mesh	*new;
  int		i;

  if ((new = bunny_malloc((*nb_item + 1) * sizeof(t_mesh))) == NULL)
    return (1);
  i = 0;
  while (i < *nb_item)
    {
      new[i] = (*item)[i];
      i++;
    }
  new[*nb_item] = new_item;
  if (*nb_item != 0)
    bunny_free(*item);
  (*item) = new;
  (*nb_item)++;
  return (0);
}

static int	get_fd_file(t_mesh *mesh, t_bunny_ini_scope *scope)
{
  const char	*data;

  if ((data = bunny_ini_scope_get_field(scope, "file", 0)) == NULL)
    return (1);
  if ((mesh->fd = open(data, O_RDONLY)) == -1)
    return (1);
  return (0);
}

int		add_mesh(t_obj *obj, t_bunny_ini_scope *scope)
{
  t_mesh	mesh;

  mesh.v = NULL;
  mesh.vn = NULL;
  mesh.vt = NULL;
  mesh.tri = NULL;
  if (get_fd_file(&mesh, scope) == 1)
    return (1);
  if (mesh_pars(&mesh) == 1)
    return (1);
  if (get_ini_meta(scope, &mesh.meta) == 1)
    return (1);
  if (add(&obj->mesh, &obj->nb.mesh, mesh) == 1)
    return (1);
  return (0);
}
