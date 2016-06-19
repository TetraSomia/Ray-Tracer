/*
** rt.h for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jan 29 18:34:35 2016 Arthur Josso
** Last update Sun Jun 19 14:16:34 2016 Arthur Josso
*/

#ifndef RT_H_
# define RT_H_

# include "core.h"

# define FULL_SCR	(1)
# define W_X		(1920)
# define W_Y		(1080)
# define FPS		(30)

# define ANTI_ALIASING	(3)

typedef enum    e_is_gen
  {
    IS_PREVIEW	= 1 << 0,
    IS_PHONG	= 1 << 1,
    IS_REFLEC	= 1 << 2,
    IS_REFRAC	= 1 << 3,
    IS_AA	= 1 << 4,
    IS_RECORD	= 1 << 5
  }             t_is_gen;

/*
** Initialization
*/

int	load_scene(t_obj *obj, const char *file);
int     init(t_data *data, const char *file);

/*
** Scene Generation
*/

typedef enum	e_obj_type
  {
    NONE	= 0,
    MESH	= 1,
    SPHERE	= 2,
    CYLINDER	= 3,
    CONE	= 4,
    TORUS	= 5,
    PLAN	= 6,
    MOBIUS	= 7
  }		t_obj_type;

typedef struct s_hit
{
  t_vec		pt;
  t_vec		n;
  t_vec		rot_pt;
  char		obj_type;
  void		*obj;
  float		k;
  t_meta	meta;
}		t_hit;

int     gen_scene(t_data *data);
void	gen_slice(t_data *data, int min, int max);
t_color	get_pix(t_data *data, t_vec *pos);
t_color	anti_aliasing(t_data *data, t_vec *pos);

/*
** Light
*/

# define AMBIENT	(0.1)
# define PREC		(0.01)

typedef struct	s_color_sum
{
  int		red;
  int		green;
  int		blue;
}		t_color_sum;

void    light(t_data *data, t_hit *hit);

/*
** Phong
*/

# define PHONG_SIZE	(32)

void    phong(t_data *data, t_hit *hit);

/*
** Reflection
*/

void    reflect(t_data *data, t_hit *vision_hit);

/*
** Refraction
*/

# define I_AIR	(1.00)

void    refract(t_data *data, t_hit *vision_hit);

/*
** Math - General
*/

# define POW(x)		((x) * (x))

# define VIEW_RANGE	(500)

void    get_ray(t_data *data, t_cam *cam, t_vec *scr, t_ray *ray);
t_vec	get_pt_with_k(float k, t_ray *ray);
t_color	get_tex_at(t_ray *ray, float k, t_sphere *sphere);
float	earth_rot(bool inc);
t_color	get_perlin_at(t_vec *pt, t_meta *meta);

void    rot_vec(t_vec *vec, t_vec *angle);
void	rot_vec_inv(t_vec *vec, t_vec *angle);
t_ray   get_rot_ray(t_ray ray, t_vec *angle);
t_vec   get_rot_vec(t_vec vec, t_vec *angle);
t_ray   get_trans_ray(t_ray ray, t_vec *angle);
t_vec   get_trans_vec(t_vec vec, t_vec *angle);

/*
** Normal vec
*/

t_vec   get_normal_vec(t_hit *hit);
t_vec	get_torus_n(t_hit *hit);
t_vec	get_mobius_n(t_vec *hit, t_vec *pt_cen, t_vec *pt_cir);
t_vec	get_mesh_n(t_hit *hit, int n_tri, float u, float v);

/*
** Math - Vector
*/

void    set_uni_vec(t_vec *v);
float   get_norm(float k, t_vec *vec);
t_vec   get_vec(t_vec *pt1, t_vec *pt2);
t_vec   get_uni_vec(t_vec *pt1, t_vec *pt2);
float   get_dot(t_vec *v1, t_vec *v2);
t_vec	vec_product(t_vec *u, t_vec *v);
t_vec	get_reflec_vec(t_vec *n, t_vec *l);
void    inv_vec(t_vec *v);
void	mult_vec(float x, t_vec *v);

/*
** Bumping
*/

# define EPSILON	(0.001)
# define SMOOTH		(0.1)

t_vec   bump_vec(t_hit *hit, t_vec n);

/*
** Find hit
*/

void	find_hit(t_data *data, t_ray *ray, t_hit *hit);
void    find_k_sphere(t_ray *ray, t_obj *obj, t_hit *hit);
void    find_k_cylinder(t_ray *ray, t_obj *obj, t_hit *hit);
void    find_k_cone(t_ray *ray, t_obj *obj, t_hit *hit);
void    find_k_torus(t_ray *ray, t_obj *obj, t_hit *hit);
void	find_k_plan(t_ray *ray, t_obj *obj, t_hit *hit);
void    find_k_mobius(t_ray *ray, t_obj *obj, t_hit *hit);
void    find_k_mesh(t_ray *ray, t_obj *obj, t_hit *hit);

/*
** Perlin
*/

int     gen_perlin_tab(t_perlin *perlin);
float	perlin(int *tab, t_vec *pt, float persistance);

/*
** Preview
*/

# define MOVE	(0.1)
# define ROT	(M_PI / 128)

void    interact_cam(t_cam *cam);

/*
** Core
*/

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *p,
		 t_color *c);

t_color get_color(t_color *src, float coef);

/*
** Exit
*/

void	exit_prog(t_data *data);
void    free_objs(t_data *data);

/*
** Video jif
*/

int	jif_gen(t_data *data);

#endif
