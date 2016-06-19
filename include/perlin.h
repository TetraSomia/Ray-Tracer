/*
** perlin.h for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Feb 20 15:06:36 2016 Arthur Josso
** Last update Sat May 21 16:38:48 2016 Arthur Josso
*/

#ifndef PERLIN_H_
# define PERLIN_H_

# include "core.h"

# define OCTAVES	(8)
# define SIZE		(256)

typedef struct	s_cube_corner
{
  int		c0;
  int		c1;
  int		c2;
  int		c3;
  int		c4;
  int		c5;
  int		c6;
  int		c7;
}		t_cube_corner;

typedef struct	s_int_pt
{
  int		x;
  int		y;
  int		z;
}		t_int_pt;

typedef struct	s_perlin_data
{
  t_cube_corner hash;
  t_int_pt      cube;
  t_vec         ratio;
  t_vec         vec;
  t_vec         v1;
  t_vec         v2;
}		t_perlin_data;

float   grad(int h, float x, float y, float z);
float   lerp(float x, float a, float b);
float   fade(float x);

#endif
