/*
** mesh.c for rt in /home/josso/rendu/gfx/gfx_raytracer2
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Apr 24 16:41:27 2016 Arthur Josso
** Last update Sun Apr 24 18:58:38 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

static float	intersect_tri(t_ray *r, t_tri_mesh *t, float *u, float *v)
{
  t_vec		v1;
  t_vec		v2;
  t_vec		product;
  t_vec		v_t;
  float		angle;

  v1 = get_vec(t->vert[0].pos, t->vert[1].pos);
  v2 = get_vec(t->vert[0].pos, t->vert[2].pos);
  product = vec_product(&r->beta, &v2);
  angle = get_dot(&v1, &product);
  if (fabs(angle) < 0.0000001)
    return (-1);
  angle = 1 / angle;
  v_t = get_vec(t->vert[0].pos, &r->alpha);
  *u = get_dot(&v_t, &product) * angle;
  if (*u < 0 || *u > 1)
    return (-1);
  v_t = vec_product(&v_t, &v1);
  *v = get_dot(&r->beta, &v_t) * angle;
  if (*v < 0 || *v + *u > 1)
    return (-1);
  return (get_dot(&v2, &v_t) * angle);
}

void	find_k_mesh(t_ray *ray, t_obj *obj, t_hit *hit)
{
  float	k;
  int	i;
  int	j;
  float	u;
  float	v;

  i = 0;
  while (i < obj->nb.mesh)
    {
      j = 0;
      while (obj->mesh[i].tri[j])
	{
	  k = intersect_tri(ray, obj->mesh[i].tri[j], &u, &v);
	  if (k < hit->k && k >= 0)
	    {
	      hit->k = k;
	      hit->obj = (void*)&obj->mesh[i];
	      hit->obj_type = MESH;
	      hit->meta = obj->mesh[i].meta;
	      get_mesh_n(hit, j, u, v);
	    }
	  j++;
	}
      i++;
    }
}
