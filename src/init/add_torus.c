/*
** add_torus.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Apr 12 17:39:30 2016 Arthur Josso
** Last update Thu Apr 14 14:45:15 2016 Arthur Josso
*/

#include "init.h"

static int	add(t_torus **item, int *nb_item, t_torus new_item)
{
  t_torus	*new;
  int		i;

  if ((new = bunny_malloc((*nb_item + 1) * sizeof(t_torus))) == NULL)
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

int		add_torus(t_obj *obj, t_bunny_ini_scope *scope)
{
  t_torus	torus;

  if (get_ini_size(scope, "radius", &torus.radius) == 1)
    return (1);
  if (get_ini_size(scope, "width", &torus.width) == 1)
    return (1);
  if (torus.radius <= torus.width)
    return (1);
  if (get_ini_meta(scope, &torus.meta) == 1)
    return (1);
  if (add(&obj->torus, &obj->nb.torus, torus) == 1)
    return (1);
  return (0);
}
