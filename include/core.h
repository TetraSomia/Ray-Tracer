/*
** core.h for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Feb 20 15:23:59 2016 Arthur Josso
** Last update Sat May 21 16:41:40 2016 Arthur Josso
*/

#ifndef CORE_H_
# define CORE_H_

# include <lapin.h>
# include "jif.h"

# define MAP(x, ba, ea, bb, eb) ((((ba - x) / (ba - ea)) * (eb - bb)) + bb)
# define ABS(x)			((x) < 0 ? -(x) : (x))

typedef struct	s_vec
{
  float		x;
  float		y;
  float		z;
}		t_vec;

typedef struct	s_ray
{
  t_vec		alpha;
  t_vec		beta;
}		t_ray;

/*
** t_data
*/

typedef struct	s_cam
{
  t_vec		pos;
  t_vec		rot;
} __attribute__((__packed__)) t_cam;

typedef struct	s_cam_path
{
  t_jif_mode	mode;
  int		fd;
}		t_cam_path;

typedef struct	s_refrac
{
  float		ratio;
  float		indice;
}		t_refrac;

typedef struct	s_perlin
{
  float		ratio;
  float		persis;
  int		*tab;
  char		type;
}		t_perlin;

typedef struct		s_meta
{
  t_vec			pos;
  t_vec			rot;
  t_color		color;
  float			reflec;
  t_refrac		refrac;
  t_perlin		perlin;
  float			mirroring;
  t_bunny_pixelarray	*tex;
}			t_meta;

typedef struct	s_vertex
{
  t_vec         *pos;
  t_vec         *n;
  t_vec         *t;
}		t_vertex;

typedef struct	s_tri_mesh
{
  t_vertex	vert[3];
}		t_tri_mesh;

typedef struct	s_mesh
{
  t_vec		**v;
  t_vec		**vn;
  t_vec		**vt;
  t_tri_mesh	**tri;
  int		fd;
  t_meta	meta;
}		t_mesh;

typedef struct	s_plan
{
  int		ground;
  t_meta	meta;
}		t_plan;

typedef struct	s_sphere
{
  float         radius;
  t_meta	meta;
}		t_sphere;

typedef struct	s_cylinder
{
  float         radius;
  t_meta	meta;
}		t_cylinder;

typedef struct	s_cone
{
  float         angle;
  t_meta	meta;
}		t_cone;

typedef struct	s_torus
{
  float		radius;
  float		width;
  t_meta        meta;
}		t_torus;

typedef struct	s_mobius
{
  float		radius;
  t_meta	meta;
}		t_mobius;

typedef struct	s_light
{
  t_vec		pos;
  float		power;
}		t_light;

typedef struct	s_nb_item
{
  int		light;
  int		sphere;
  int		cylinder;
  int		cone;
  int		torus;
  int		mobius;
  int		plan;
  int		mesh;
}		t_nb_item;

typedef struct	s_obj
{
  t_nb_item     nb;
  t_plan	*plan;
  t_sphere      *sphere;
  t_cylinder    *cylinder;
  t_cone        *cone;
  t_torus	*torus;
  t_mobius	*mobius;
  t_light       *light;
  t_mesh	*mesh;
  t_cam         cam;
}		t_obj;

typedef struct		s_data
{
  t_bunny_window        *win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray    *big;
  t_bunny_pixelarray    *small;
  t_obj                 obj;
  unsigned char         gen_type;
  t_cam_path		*path;
  t_jif			*jif;
  const bool		*keys;
}			t_data;

typedef enum    e_exit
  {
    SUCCESS     = 0,
    ERROR       = 1
  }             t_exit;

#endif
