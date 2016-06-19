/*
** deg_2.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Apr 14 12:58:23 2016 Arthur Josso
** Last update Thu Apr 14 13:05:35 2016 Arthur Josso
*/

#include <math.h>
#include "solver.h"

static int	common_case(t_cplx a, t_cplx b, t_cplx c, t_cplx roots[2])
{
  t_cplx	radicand;
  t_cplx	r;
  t_cplx	d;

  radicand = sub(mult(b, b), mult(mult(new_c(4, 0), a), c));
  if (is_zero(radicand))
    {
      roots[0] = divi(neg(b), mult(new_c(2, 0), a));
      return (1);
    }
  else
    {
      r = new_c(sqrt(radicand.real), 0);
      d = mult(new_c(2, 0), a);
      roots[0] = divi((sub(r, b)), d);
      roots[1] = divi((add(r, b)), d);
      return (2);
    }
}

int	solv_deg_2(t_cplx a, t_cplx b, t_cplx c, t_cplx roots[2])
{
  if (is_zero(a))
    {
      if (is_zero(b))
	return (0);
      else
	{
	  roots[0] = divi(neg(c), b);
	  return (1);
	}
    }
  else
    return (common_case(a, b, c, roots));
}
