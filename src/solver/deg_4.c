/*
** 4th_deg.c for solver in /home/josso/en_cours/degrees4
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Apr 12 14:04:50 2016 Arthur Josso
** Last update Thu Apr 14 13:49:04 2016 Arthur Josso
*/

#include <math.h>
#include "solver.h"

static void	beta_null(t_deg4_utils *u, t_cplx roots[4])
{
  u->rad = c_sqrt(sub(u->alpha2, mult(new_c(4, 0), u->gamma)));
  u->r1 = c_sqrt(divi(sub(u->rad, u->alpha), new_c(2, 0)));
  u->r2 = c_sqrt(divi(sub(neg(u->alpha), u->rad), new_c(2, 0)));
  roots[0] = add(u->t, u->r1);
  roots[1] = sub(u->t, u->r1);
  roots[2] = add(u->t, u->r2);
  roots[3] = sub(u->t, u->r2);
}

static void	beta_not_null(t_deg4_utils *u, t_cplx roots[4])
{
  u->alpha3 = mult(u->alpha, u->alpha2);
  u->p = neg(add(u->gamma, divi(u->alpha2, new_c(12, 0))));
  u->q = sub(add(divi(neg(u->alpha3), new_c(108, 0)),
		divi(mult(u->alpha, u->gamma), new_c(3, 0))),
	    divi(mult(u->beta, u->beta), new_c(8, 0)));
  u->r = add(divi(neg(u->q), new_c(2, 0)),
	    c_sqrt(add(divi(mult(u->q, u->q), new_c(4, 0)),
		       divi(mult(mult(u->p, u->p), u->p), new_c(27, 0)))));
  u->u = m_cbrt(u->r, 0);
  u->y = add(mult(new_c(-5.0 / 6.0, 0), u->alpha), u->u);
  if (is_zero(u->u))
    u->y = sub(u->y, m_cbrt(u->q, 0));
  else
    u->y = sub(u->y, divi(u->p, mult(new_c(3, 0), u->u)));
  u->w = c_sqrt(add(u->alpha, mult(new_c(2, 0), u->y)));
  u->r1 = c_sqrt(neg(add(add(mult(new_c(3, 0), u->alpha),
			    mult(new_c(2, 0), u->y)),
			divi(mult(new_c(2, 0), u->beta), u->w))));
  u->r2 = c_sqrt(neg(sub(add(mult(new_c(3, 0), u->alpha),
			    mult(new_c(2, 0), u->y)),
			divi(mult(new_c(2, 0), u->beta), u->w))));
  roots[0] = add(u->t, divi(sub(u->w, u->r1), new_c(2, 0)));
  roots[1] = add(u->t, divi(add(u->w, u->r1), new_c(2, 0)));
  roots[2] = add(u->t, divi(sub(neg(u->w), u->r2), new_c(2, 0)));
  roots[3] = add(u->t, divi(sub(u->r2, u->w), new_c(2, 0)));
}

int		solv_deg_4(t_cplx coef[5], t_cplx roots[4])
{
  t_deg4_utils	u;

  if (is_zero(coef[0]))
    return (solv_deg_3(coef + 1, roots));
  coef[1] = divi(coef[1], coef[0]);
  coef[2] = divi(coef[2], coef[0]);
  coef[3] = divi(coef[3], coef[0]);
  coef[4] = divi(coef[4], coef[0]);
  u.b2 = mult(coef[1], coef[1]);
  u.b3 = mult(coef[1], u.b2);
  u.b4 = mult(u.b2, u.b2);
  u.alpha = add(mult(new_c(-3.0 / 8.0, 0), u.b2), coef[2]);
  u.beta  = add(sub(divi(u.b3, new_c(8, 0)), divi(mult(coef[1], coef[2]),
						  new_c(2, 0))), coef[3]);
  u.gamma = add(sub(add(mult(new_c(-3.0 / 256.0, 0), u.b4),
			divi(mult(u.b2, coef[2]), new_c(16, 0))),
		    divi(mult(coef[1], coef[3]), new_c(4, 0))), coef[4]);
  u.alpha2 = mult(u.alpha, u.alpha);
  u.t = divi(neg(coef[1]), new_c(4, 0));
  if (is_zero(u.beta))
    beta_null(&u, roots);
  else
    beta_not_null(&u, roots);
  return (4);
}
