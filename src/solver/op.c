/*
** op.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Apr 13 17:52:45 2016 Arthur Josso
** Last update Wed Apr 13 19:42:42 2016 Arthur Josso
*/

#include <math.h>
#include "solver.h"

t_cplx		add(t_cplx a, t_cplx b)
{
  t_cplx	ret;

  ret.img = a.img + b.img;
  ret.real = a.real + b.real;
  return (ret);
}

t_cplx		sub(t_cplx a, t_cplx b)
{
  t_cplx	ret;

  ret.img = a.img - b.img;
  ret.real = a.real - b.real;
  return (ret);
}

t_cplx		divi(t_cplx a, t_cplx b)
{
  t_cplx	ret;
  double	div;

  div = pow(b.real, 2) + pow(b.img, 2);
  if (div == 0)
    div = TOL;
  ret.real = (a.real * b.real + a.img * b.img) / div;
  ret.img = (b.real * a.img - a.real * b.img) / div;
  return (ret);
}

t_cplx		mult(t_cplx a, t_cplx b)
{
  t_cplx	ret;

  ret.real = a.real * b.real - a.img * b.img;
  ret.img = a.real * b.img + b.real * a.img;
  return (ret);
}

t_cplx		neg(t_cplx x)
{
  x.img = -x.img;
  x.real = -x.real;
  return (x);
}
