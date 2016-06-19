/*
** utils.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Apr 13 19:36:11 2016 Arthur Josso
** Last update Fri Apr 15 20:01:17 2016 Arthur Josso
*/

#include <math.h>
#include "solver.h"

int	is_zero(t_cplx x)
{
  return (fabs(x.real) < TOL && fabs(x.img) < TOL);
}

t_cplx		new_c(double real, double img)
{
  t_cplx	z;

  z.real = real;
  z.img = img;
  return (z);
}

int	get_real_c(int nb_cplx, t_cplx in[], double out[])
{
  int	nb_real;
  int	i;

  nb_real= 0;
  i = 0;
  while (i < nb_cplx)
    {
      if (fabs(in[i].img) < IMG_TOL)
	out[nb_real++] = in[i].real;
      i++;
    }
  return (nb_real);
}

t_cplx		m_cbrt (t_cplx a, int n)
{
  double	pi_2;
  double	rho;
  double	theta;
  t_cplx	ret;

  pi_2 = 2.0 * M_PI;
  rho = pow(c_abs(a), 1.0 / 3.0);
  theta = ((pi_2 * n) + c_arg(a)) / 3.0;
  ret = new_c(rho * cos(theta), rho * sin(theta));
  return (ret);
}
