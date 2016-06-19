/*
** texture.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Feb 16 18:33:58 2016 Arthur Josso
** Last update Sat May 21 15:47:27 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"
#include "my.h"

float		earth_rot(bool inc)
{
  static float	rot;

  if (inc)
    rot += 0.05;
  return (rot);
}

t_vec	vec_product(t_vec *u, t_vec *v)
{
  t_vec	product;

  product.x = u->y * v->z - u->z * v->y;
  product.y = u->z * v->x - u->x * v->z;
  product.z = u->x * v->y - u->y * v->x;
  return (product);
}

static float	sec(float x)
{
  if (x >= 1)
    return (0.999999);
  if (x <= -1)
    return (-0.999999);
  return (x);
}

static void	get_ratio(t_vec *hit,
			  t_sphere *sphere,
			  float *x,
			  float *y)
{
  t_vec		n;
  t_vec		e;
  t_vec		p;
  t_vec		cross_prod;
  float		phi;
  float		theta;

  p = get_uni_vec(&sphere->meta.pos, hit);
  n.x = 0;
  n.y = 0;
  n.z = 1;
  e.x = cos(earth_rot(0));
  e.y = sin(earth_rot(0));
  e.z = 0;
  phi = acos(sec(-get_dot(&n, &p)));
  *y = 1 - (phi / M_PI);
  theta = (acos(sec(get_dot(&p, &e) / sin(phi)))) / (2 * M_PI);
  cross_prod = vec_product(&n, &e);
  *x = get_dot(&cross_prod, &p) > 0 ? theta : 1 - theta;
}

t_color			get_tex_at(t_ray *ray, float k, t_sphere *sphere)
{
  t_bunny_position	pos;
  float			x;
  float			y;
  t_vec			hit;

  hit = get_pt_with_k(k, ray);
  get_ratio(&hit, sphere, &x, &y);
  pos.x = x * sphere->meta.tex->clipable.clip_width;
  pos.y = y * sphere->meta.tex->clipable.clip_height;
  return (get_pixel(sphere->meta.tex, &pos));
}
