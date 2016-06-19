/*
** reflec_vector.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Feb 18 13:49:59 2016 Arthur Josso
** Last update Thu Feb 18 13:50:20 2016 Arthur Josso
*/

#include "rt.h"

t_vec	get_reflec_vec(t_vec *n, t_vec *l)
{
  float	fac;
  t_vec	r;

  fac = 2 * get_dot(n, l);
  r.x = fac * n->x - l->x;
  r.y = fac * n->y - l->y;
  r.z = fac * n->z - l->z;
  return (r);
}
