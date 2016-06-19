/*
** bump_vec.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Feb 21 12:37:23 2016 Arthur Josso
** Last update Wed Mar 16 11:52:52 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

static float	smooth(float x)
{
  float		t;

  t = 0.5 + 0.5 * sin(2 * M_PI * x * SMOOTH);
  t = t * t - 0.5;
  return (t);
}

static void	smooth_it(float *pt0, t_vec *pt)
{
  *pt0 = smooth(*pt0);
  pt->x = smooth(pt->x);
  pt->y = smooth(pt->y);
  pt->z = smooth(pt->z);
}

t_vec	bump_vec(t_hit *hit, t_vec n)
{
  float	pt0;
  t_vec	pt;
  t_vec	tmp;

  pt0 = perlin(hit->meta.perlin.tab, &hit->pt, hit->meta.perlin.persis);
  tmp = hit->pt;
  tmp.x += EPSILON;
  pt.x = perlin(hit->meta.perlin.tab, &tmp, hit->meta.perlin.persis);
  tmp = hit->pt;
  tmp.y += EPSILON;
  pt.y = perlin(hit->meta.perlin.tab, &tmp, hit->meta.perlin.persis);
  tmp = hit->pt;
  tmp.z += EPSILON;
  pt.z = perlin(hit->meta.perlin.tab, &tmp, hit->meta.perlin.persis);
  smooth_it(&pt0, &pt);
  n.x -= (pt.x - pt0) / EPSILON;
  n.y -= (pt.y - pt0) / EPSILON;
  n.z -= (pt.z - pt0) / EPSILON;
  set_uni_vec(&n);
  return (n);
}
