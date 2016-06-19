/*
** add_cylinder.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Feb 12 17:25:48 2016 Arthur Josso
** Last update Thu Apr 14 14:44:59 2016 Arthur Josso
*/

#include "init.h"

static int	add(t_cylinder **item, int *nb_item, t_cylinder new_item)
{
  t_cylinder	*new;
  int		i;

  if ((new = bunny_malloc((*nb_item + 1) * sizeof(t_cylinder))) == NULL)
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

int             add_cylinder(t_obj *obj, t_bunny_ini_scope *scope)
{
  t_cylinder	cylinder;

  if (get_ini_size(scope, "radius", &cylinder.radius) == 1)
    return (1);
  if (get_ini_meta(scope, &cylinder.meta) == 1)
    return (1);
  if (add(&obj->cylinder, &obj->nb.cylinder, cylinder) == 1)
    return (1);
  return (0);
}
