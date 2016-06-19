/*
** add_mobius.c for rt in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Apr 16 15:08:08 2016 Arthur Josso
** Last update Sat Apr 16 15:08:19 2016 Arthur Josso
*/

#include "init.h"

static int	add(t_mobius **item, int *nb_item, t_mobius new_item)
{
  t_mobius	*new;
  int		i;

  if ((new = bunny_malloc((*nb_item + 1) * sizeof(t_mobius))) == NULL)
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

int             add_mobius(t_obj *obj, t_bunny_ini_scope *scope)
{
  t_mobius	mobius;

  if (get_ini_size(scope, "radius", &mobius.radius) == 1)
    return (1);
  if (get_ini_meta(scope, &mobius.meta) == 1)
    return (1);
  if (add(&obj->mobius, &obj->nb.mobius, mobius) == 1)
    return (1);
  return (0);
}
