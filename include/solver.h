/*
** solver.h for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Apr 13 17:53:18 2016 Arthur Josso
** Last update Sat May 21 16:44:59 2016 Arthur Josso
*/

#ifndef SOLVER_H
# define SOLVER_H

# define TOL		(0.0000000000001)
# define IMG_TOL	(0.00001)

typedef	struct	s_cplx
{
  double	real;
  double	img;
}		t_cplx;

typedef struct	s_4th_deg
{
  double	a0;
  double	a1;
  double	a2;
  double	a3;
  double	a4;
  int		nb_sol;
  double	x[4];
}		t_4th_deg;

/*
** Quartic equation
*/

typedef struct	s_deg4_utils
{
  t_cplx	b2;
  t_cplx	b3;
  t_cplx	b4;
  t_cplx	alpha;
  t_cplx	beta;
  t_cplx	gamma;
  t_cplx	alpha2;
  t_cplx	t;
  t_cplx	rad;
  t_cplx	r1;
  t_cplx	r2;
  t_cplx	alpha3;
  t_cplx	p;
  t_cplx	q;
  t_cplx	r;
  t_cplx	u;
  t_cplx	y;
  t_cplx	w;
}		t_deg4_utils;

int	solv_deg_4(t_cplx coef[5], t_cplx roots[4]);

/*
** Cubic equation
*/

int	solv_deg_3(t_cplx coef[4], t_cplx roots[3]);

/*
** Quadratic equation
*/

int	solv_deg_2(t_cplx a, t_cplx b, t_cplx c, t_cplx roots[2]);

/*
** op for complex
*/

t_cplx	add(t_cplx a, t_cplx b);
t_cplx  sub(t_cplx a, t_cplx b);
t_cplx  divi(t_cplx a, t_cplx b);
t_cplx  mult(t_cplx a, t_cplx b);
t_cplx	neg(t_cplx x);

/*
** math.h extension
*/

double	c_arg(t_cplx x);
double	c_abs(t_cplx x);
t_cplx	c_sqrt(t_cplx x);

/*
** Utils
*/

t_cplx	new_c(double real, double img);
int	is_zero(t_cplx x);
int	get_real_c(int nb_cplx, t_cplx in[], double out[]);
t_cplx	m_cbrt (t_cplx a, int n);

#endif
