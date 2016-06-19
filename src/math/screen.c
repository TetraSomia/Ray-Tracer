/*
** rotate.c for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Jan 30 17:20:25 2016 Arthur Josso
** Last update Mon May  9 15:49:19 2016 Arthur Josso
*/

#include <math.h>
#include "rt.h"

t_ray	get_rot_ray(t_ray ray, t_vec *angle)
{
  rot_vec(&ray.alpha, angle);
  rot_vec(&ray.beta, angle);
  return (ray);
}

t_vec	get_rot_vec(t_vec vec, t_vec *angle)
{
  rot_vec(&vec, angle);
  return (vec);
}

void			get_ray(t_data *data,
				t_cam *cam,
				t_vec *scr,
				t_ray *ray)
{
  t_bunny_position	size;

  size.x = data->pix->clipable.clip_width;
  size.y = data->pix->clipable.clip_height;
  ray->beta.x = sqrt(POW(size.y) + POW(size.x));
  ray->beta.y = size.x / 2 - scr->x;
  ray->beta.z = size.y / 2 - scr->y;
  rot_vec(&ray->beta, &cam->rot);
  ray->alpha.x = cam->pos.x;
  ray->alpha.y = cam->pos.y;
  ray->alpha.z = cam->pos.z;
}
