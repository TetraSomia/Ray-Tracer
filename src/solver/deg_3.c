/*
** deg_3.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Apr 14 13:06:08 2016 Arthur Josso
** Last update Thu Apr 14 13:20:32 2016 Arthur Josso
*/

#include <math.h>
#include "solver.h"

static int	find_roots(t_cplx f, t_cplx s, t_cplx d, t_cplx roots[3])
{
  t_cplx	g;
  int           i;

  i = 0;
  while (i < 3)
    {
      g = m_cbrt(f, i);
      roots[i] = sub(sub(g, divi(d, g)), s);
      i++;
    }
  return (3);
}

int		solv_deg_3(t_cplx coef[4], t_cplx roots[3])
{
  t_cplx	s;
  t_cplx	d;
  t_cplx	e;
  t_cplx	froot;
  t_cplx	f;

  if (is_zero(coef[0]))
    return (solv_deg_2(coef[1], coef[2], coef[3], roots));
  coef[1] = divi(coef[1], coef[0]);
  coef[2] = divi(coef[2], coef[0]);
  coef[3] = divi(coef[3], coef[0]);
  s = divi(coef[1], new_c(3, 0));
  d = sub(divi(coef[2], new_c(3, 0)), mult(s, s));
  e = add(mult(mult(s, s), s),
	  divi(sub(coef[3], mult(s, coef[2])), new_c(2, 0)));
  froot = c_sqrt(add(mult(e, e), mult(mult(d, d), d)));
  f = sub(neg(froot), e);
  if (is_zero(f))
    f = sub(froot, e);
  return (find_roots(f, s, d, roots));
}
