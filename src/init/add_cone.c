/*
** add_cone.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Feb 15 19:47:26 2016 Arthur Josso
** Last update Thu Apr 14 14:43:43 2016 Arthur Josso
*/

#include <math.h>
#include "init.h"

static int	add(t_cone **item, int *nb_item, t_cone new_item)
{
  t_cone	*new;
  int		i;

  if ((new = bunny_malloc((*nb_item + 1) * sizeof(t_cone))) == NULL)
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

int             add_cone(t_obj *obj, t_bunny_ini_scope *scope)
{
  t_cone	cone;

  if (get_ini_size(scope, "angle", &cone.angle) == 1)
    return (1);
  if (cos(cone.angle) == 0)
    return (1);
  if (get_ini_meta(scope, &cone.meta) == 1)
    return (1);
  if (add(&obj->cone, &obj->nb.cone, cone) == 1)
    return (1);
  return (0);
}
