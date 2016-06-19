/*
** gen_tab.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Feb 19 12:47:46 2016 Arthur Josso
** Last update Sat Feb 20 17:28:38 2016 Arthur Josso
*/

#include "perlin.h"

static void	fill_values(int *values)
{
  int		i;

  i = 0;
  while (i < SIZE)
    {
      values[i] = i;
      i++;
    }
}

static int	get_val(int *values, int max)
{
  int		curs;
  int		i;
  int		add;

  curs = rand() % max;
  add = 0;
  i = 0;
  while (add <= curs)
    {
      if (values[i] != -1)
	add++;
      i++;
    }
  i--;
  add = values[i];
  values[i] = -1;
  return (add);
}

static void	get_tab(int *tab, int *values)
{
  int		i;

  i = 0;
  while (i < SIZE)
    {
      tab[i] = get_val(values, SIZE - i);
      i++;
    }
}

int	gen_perlin_tab(t_perlin *perlin)
{
  int	*values;

  if ((perlin->tab = bunny_malloc(sizeof(int) * SIZE)) == NULL)
    return (1);
  if ((values = bunny_malloc(sizeof(int) * SIZE)) == NULL)
    return (1);
  fill_values(values);
  get_tab(perlin->tab, values);
  bunny_free(values);
  return (0);
}
