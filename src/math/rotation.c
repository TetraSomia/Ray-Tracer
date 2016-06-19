/*
** rotation.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Mar  7 15:29:32 2016 Arthur Josso
** Last update Sat May 21 17:34:17 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

static void	rot_x(t_vec *vec, float angle)
{
  float		tmp;

  tmp = vec->y;
  vec->y = tmp * cos(angle) + vec->z * -sin(angle);
  vec->z = tmp * sin(angle) + vec->z * cos(angle);
}

static void    rot_y(t_vec *vec, float angle)
{
  float		tmp;

  tmp = vec->x;
  vec->x = tmp * cos(angle) + vec->z * sin(angle);
  vec->z = tmp * -sin(angle) + vec->z * cos(angle);
}

static void    rot_z(t_vec *vec, float angle)
{
  float		tmp;

  tmp = vec->x;
  vec->x = tmp * cos(angle) + vec->y * -sin(angle);
  vec->y = tmp * sin(angle) + vec->y * cos(angle);
}

void	rot_vec(t_vec *vec, t_vec *angle)
{
  rot_x(vec, angle->x);
  rot_y(vec, angle->y);
  rot_z(vec, angle->z);
}

void	rot_vec_inv(t_vec *vec, t_vec *angle)
{
  rot_x(vec, -angle->x);
  rot_y(vec, -angle->y);
  rot_z(vec, -angle->z);
}
