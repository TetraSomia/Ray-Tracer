/*
** find_k.c for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Jan 30 19:51:49 2016 Arthur Josso
** Last update Wed Apr 27 13:33:55 2016 Arthur Josso
*/

#include <stdlib.h>
#include "rt.h"

void    find_hit(t_data *data, t_ray *ray, t_hit *hit)
{
  hit->k = VIEW_RANGE;
  hit->obj = NULL;
  hit->obj_type = NONE;
  find_k_sphere(ray, &data->obj, hit);
  find_k_cylinder(ray, &data->obj, hit);
  find_k_cone(ray, &data->obj, hit);
  find_k_torus(ray, &data->obj, hit);
  find_k_plan(ray, &data->obj, hit);
  find_k_mobius(ray, &data->obj, hit);
  find_k_mesh(ray, &data->obj, hit);
  hit->pt = get_pt_with_k(hit->k, ray);
  if (hit->obj_type != NONE)
    hit->rot_pt = get_rot_vec(hit->pt, &hit->meta.rot);
  if (hit->obj_type != NONE && hit->meta.perlin.ratio
      && hit->meta.perlin.type != 2)
    hit->meta.color = get_perlin_at(&hit->pt, &hit->meta);
  if (hit->obj_type != MOBIUS && hit->obj_type != MESH)
    hit->n = get_normal_vec(hit);
}
