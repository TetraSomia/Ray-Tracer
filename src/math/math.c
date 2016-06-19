/*
** math.c for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jan 29 21:06:49 2016 Arthur Josso
** Last update Mon Feb 15 19:33:12 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

t_vec	get_pt_with_k(float k, t_ray *ray)
{
  t_vec sol;

  sol.x = ray->alpha.x + k * ray->beta.x;
  sol.y = ray->alpha.y + k * ray->beta.y;
  sol.z = ray->alpha.z + k * ray->beta.z;
  return (sol);
}
