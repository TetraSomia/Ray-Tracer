/*
** math.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Apr 13 18:41:05 2016 Arthur Josso
** Last update Thu Apr 14 13:49:39 2016 Arthur Josso
*/

#include <math.h>
#include "solver.h"

double	c_abs(t_cplx x)
{
  return (sqrt(pow(x.real, 2) + pow(x.img, 2)));
}

double	c_arg(t_cplx x)
{
  if (x.real > 0)
    return (atan(x.img / x.real));
  else if (x.real < 0)
    return (atan(x.img / x.real) + M_PI);
  return (0);
}

t_cplx		c_sqrt(t_cplx x)
{
  double	tmp;

  tmp = sqrt(x.real * x.real + x.img * x.img);
  tmp = sqrt(ldexp(tmp + fabs(x.real), -1));
  if (tmp == 0.0)
    {
      x.real = 0;
      x.img = 0;
      return (x);
    }
  if (x.real >= 0.0)
    {
      x.real = tmp;
      x.img = ldexp(x.img / tmp, -1);
    }
  else
    {
      x.real = ldexp(fabs(x.img) / tmp, -1);
      if (x.img >= 0.0)
	x.img = tmp;
      else
	x.img = -tmp;
    }
  return (x);
}
