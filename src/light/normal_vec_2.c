/*
** normal_vec_hard.c for rt in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Apr 15 13:44:19 2016 Arthur Josso
** Last update Sun Apr 24 18:58:26 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

t_vec		get_torus_n(t_hit *hit)
{
  t_vec		n;
  double	alpha;
  t_torus	*torus;
  t_vec		pt;

  pt = hit->rot_pt;
  pt.x -= hit->meta.pos.x;
  pt.y -= hit->meta.pos.y;
  pt.z -= hit->meta.pos.z;
  torus = hit->obj;
  alpha = torus->radius / sqrt(POW(pt.x) + POW(pt.y));
  alpha = 1 - alpha;
  n.x = alpha * pt.x;
  n.y = alpha * pt.y;
  n.z = pt.z;
  set_uni_vec(&n);
  rot_vec_inv(&n, &hit->meta.rot);
  return (n);
}

t_vec		get_mobius_n(t_vec *hit, t_vec *pt_cen, t_vec *pt_cir)
{
  double        a;
  double        b;
  t_vec         pt_3;
  t_vec         v1;
  t_vec         v2;
  t_vec         n;

  a = pt_cir->y - pt_cen->y;
  if (pt_cir->x - pt_cen->x == 0)
    a /= pt_cir->x - pt_cen->x - 0.0001;
  else
    a /= pt_cir->x - pt_cen->x;
  a = a ? -1 / a : -1 / 0.0001;
  b = pt_cir->y - a * pt_cir->x;
  pt_3.z = pt_cir->z;
  pt_3.x = pt_cir->x - 2;
  pt_3.y = a * pt_3.x + b;
  v1 = get_vec(pt_cir, &pt_3);
  v2 = get_vec(pt_cir, hit);
  n = vec_product(&v1, &v2);
  if (n.z < 0)
    inv_vec(&n);
  set_uni_vec(&n);
  return (n);
}

t_vec		get_mesh_n(t_hit *hit, int n_tri, float u, float v)
{
  t_mesh	*mesh;
  t_vec		n[3];

  mesh = hit->obj;
  n[0] = *mesh->tri[n_tri]->vert[0].n;
  n[1] = *mesh->tri[n_tri]->vert[1].n;
  n[2] = *mesh->tri[n_tri]->vert[2].n;
  hit->n.x = (1 - u - v) * n[0].x + u * n[1].x + v * n[2].x;
  hit->n.y = (1 - u - v) * n[0].y + u * n[1].y + v * n[2].y;
  hit->n.z = (1 - u - v) * n[0].z + u * n[1].z + v * n[2].z;
  return (hit->n);
}
