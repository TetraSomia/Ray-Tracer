/*
** vector2.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Feb 18 14:43:43 2016 Arthur Josso
** Last update Sat Apr 16 17:06:38 2016 Arthur Josso
*/

#include "rt.h"

void	inv_vec(t_vec *v)
{
  v->x *= -1;
  v->y *= -1;
  v->z *= -1;
}

void	mult_vec(float x, t_vec *v)
{
  v->x *= x;
  v->y *= x;
  v->z *= x;
}
