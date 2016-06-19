/*
** perlin.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Feb 19 12:45:44 2016 Arthur Josso
** Last update Sun Feb 21 12:23:23 2016 Arthur Josso
*/

#include "perlin.h"

static void	get_hash(int *t, t_perlin_data *p)
{
  p->hash.c0 = t[(t[(t[p->cube.x] + p->cube.y) % SIZE]
		  + p->cube.z) % SIZE];
  p->hash.c1 = t[(t[(t[p->cube.x] + p->cube.y + 1) % SIZE]
		  + p->cube.z) % SIZE];
  p->hash.c2 = t[(t[(t[p->cube.x] + p->cube.y) % SIZE]
		  + p->cube.z + 1) % SIZE];
  p->hash.c3 = t[(t[(t[p->cube.x] + p->cube.y + 1) % SIZE]
		  + p->cube.z + 1) % SIZE];
  p->hash.c4 = t[(t[(t[(p->cube.x + 1) % SIZE] + p->cube.y) % SIZE]
		  + p->cube.z) % SIZE];
  p->hash.c5 = t[(t[(t[(p->cube.x + 1) % SIZE] + p->cube.y + 1) % SIZE]
		  + p->cube.z) % SIZE];
  p->hash.c6 = t[(t[(t[(p->cube.x + 1) % SIZE] + p->cube.y) % SIZE]
		  + p->cube.z + 1) % SIZE];
  p->hash.c7 = t[(t[(t[(p->cube.x + 1) % SIZE] + p->cube.y + 1) % SIZE]
		  + p->cube.z + 1) % SIZE];
}

static void	get_pts(t_perlin_data *p, t_vec *pt)
{
  p->cube.x = (int)pt->x & 255;
  p->cube.y = (int)pt->y & 255;
  p->cube.z = (int)pt->z & 255;
  p->ratio.x = pt->x - (int)pt->x;
  p->ratio.y = pt->y - (int)pt->y;
  p->ratio.z = pt->z - (int)pt->z;
  p->vec.x = fade(p->ratio.x);
  p->vec.y = fade(p->ratio.y);
  p->vec.z = fade(p->ratio.z);
}

static float	perlin_calc(int *tab, t_vec *pt)
{
  t_perlin_data	p;

  get_pts(&p, pt);
  get_hash(tab, &p);
  p.v1.x = lerp(p.vec.x, grad(p.hash.c0, p.ratio.x, p.ratio.y, p.ratio.z),
	       grad(p.hash.c4, p.ratio.x - 1, p.ratio.y, p.ratio.z));
  p.v1.y = lerp(p.vec.x, grad(p.hash.c1, p.ratio.x, p.ratio.y - 1, p.ratio.z),
	       grad(p.hash.c5, p.ratio.x - 1, p.ratio.y - 1, p.ratio.z));
  p.v1.z = lerp(p.vec.y, p.v1.x, p.v1.y);
  p.v2.x = lerp(p.vec.x, grad(p.hash.c2, p.ratio.x, p.ratio.y, p.ratio.z - 1),
	      grad(p.hash.c6, p.ratio.x - 1, p.ratio.y, p.ratio.z - 1));
  p.v2.y = lerp(p.vec.x, grad(p.hash.c3, p.ratio.x,
			      p.ratio.y - 1, p.ratio.z - 1),
		grad(p.hash.c7, p.ratio.x - 1, p.ratio.y - 1, p.ratio.z - 1));
  p.v2.z = lerp(p.vec.y, p.v2.x, p.v2.y);
  return ((lerp(p.vec.z, p.v1.z, p.v2.z) + 1) / 2);
}

float	perlin(int *tab, t_vec *pt, float persistance)
{
  t_vec	p;
  float	tot;
  float	max;
  float	freq;
  float	ampl;
  int	i;

  tot = 0;
  max = 0;
  freq = 1;
  ampl = 1;
  i = 0;
  while (i < OCTAVES)
    {
      p.x = ABS(pt->x) * freq;
      p.y = ABS(pt->y) * freq;
      p.z = ABS(pt->z) * freq;
      tot += perlin_calc(tab, &p) * ampl;
      max += ampl;
      ampl *= persistance;
      freq *= 2;
      i++;
    }
  return (tot / max);
}
