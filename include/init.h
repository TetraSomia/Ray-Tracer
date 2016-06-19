/*
** init.h for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Feb 20 15:26:31 2016 Arthur Josso
** Last update Sat May 21 16:42:03 2016 Arthur Josso
*/

#ifndef INIT_H_
# define INIT_H_

# include "core.h"

typedef struct	s_parsing
{
  int		(*func)(t_obj *obj, t_bunny_ini_scope *scope);
  char		*name;
}		t_parsing;

int     get_ini_vec(t_bunny_ini_scope *scope, const char *field, t_vec *vec);
int     get_ini_size(t_bunny_ini_scope *scope, const char *field, float *nb);
int     get_ini_ratio(t_bunny_ini_scope *scope, const char *field, float *nb);
int	get_ini_meta(t_bunny_ini_scope *scope, t_meta *meta);

t_bunny_pixelarray	*get_tex(t_bunny_ini_scope *scope);

int     add_cam(t_obj *obj, t_bunny_ini_scope *scope);
int     add_light(t_obj *obj, t_bunny_ini_scope *scope);
int     add_sphere(t_obj *obj, t_bunny_ini_scope *scope);
int     add_cylinder(t_obj *obj, t_bunny_ini_scope *scope);
int     add_cone(t_obj *obj, t_bunny_ini_scope *scope);
int     add_torus(t_obj *obj, t_bunny_ini_scope *scope);
int     add_plan(t_obj *obj, t_bunny_ini_scope *scope);
int     add_mobius(t_obj *obj, t_bunny_ini_scope *scope);
int     add_mesh(t_obj *obj, t_bunny_ini_scope *scope);

#endif
