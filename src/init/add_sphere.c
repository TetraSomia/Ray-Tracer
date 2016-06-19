/*
** add_sphere.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Feb 12 17:11:45 2016 Arthur Josso
** Last update Thu Apr 14 14:45:08 2016 Arthur Josso
*/

#include "init.h"

static int	add(t_sphere **item, int *nb_item, t_sphere new_item)
{
  t_sphere	*new;
  int		i;

  if ((new = bunny_malloc((*nb_item + 1) * sizeof(t_sphere))) == NULL)
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

int             add_sphere(t_obj *obj, t_bunny_ini_scope *scope)
{
  t_sphere	sphere;

  if (get_ini_size(scope, "radius", &sphere.radius) == 1)
    return (1);
  if (get_ini_meta(scope, &sphere.meta) == 1)
    return (1);
  if (add(&obj->sphere, &obj->nb.sphere, sphere) == 1)
    return (1);
  return (0);
}
