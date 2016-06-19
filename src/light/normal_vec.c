/*
** normal_vec.c for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Jan 31 20:07:50 2016 Arthur Josso
** Last update Thu Apr 28 13:37:30 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

static t_vec    get_cylinder(t_hit *hit)
{
  t_vec		n;
  t_vec		center;

  center = hit->meta.pos;
  center.z = hit->rot_pt.z;
  rot_vec_inv(&n, &hit->meta.rot);
  n = get_uni_vec(&center, &hit->rot_pt);
  return (n);
}

static t_vec    get_sphere(t_hit *hit)
{
  t_vec         n;

  n = get_uni_vec(&hit->meta.pos, &hit->pt);
  return (n);
}

static t_vec    get_cone(t_hit *hit)
{
  t_vec		n;
  t_vec		center;
  float		add;
  t_cone	*cone;

  cone = hit->obj;
  center = hit->meta.pos;
  n = get_vec(&center, &hit->rot_pt);
  add = get_norm(1, &n) / cos(cone->angle);
  if (hit->rot_pt.z > center.z)
    center.z += add;
  else
    center.z -= add;
  n = get_uni_vec(&center, &hit->rot_pt);
  rot_vec_inv(&n, &hit->meta.rot);
  return (n);
}

t_vec   get_normal_vec(t_hit *hit)
{
  t_vec n;

  if (hit->obj_type == TORUS)
    n = get_torus_n(hit);
  else if (hit->obj_type == SPHERE)
    n = get_sphere(hit);
  else if (hit->obj_type == CYLINDER)
    n = get_cylinder(hit);
  else if (hit->obj_type == CONE)
    n = get_cone(hit);
  else if (hit->obj_type == PLAN)
    n = hit->meta.rot;
  if (hit->obj_type != NONE && hit->meta.perlin.ratio
      && hit->meta.perlin.type == 2)
    n = bump_vec(hit, n);
  return (n);
}
