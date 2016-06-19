/*
** get2.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Feb 20 16:27:02 2016 Arthur Josso
** Last update Thu May 19 17:36:28 2016 Arthur Josso
*/

#include "rt.h"
#include "init.h"
#include "my.h"

static int	get_ini_refraction(t_bunny_ini_scope *scope, t_refrac *refrac)
{
  const char	*data;

  if ((data = bunny_ini_scope_get_field(scope, "refraction", 0)) == NULL)
    refrac->ratio = 0;
  else
    {
      refrac->ratio = get_double((char*)data);
      if (refrac->ratio > 1 || refrac->ratio < 0)
	return (1);
      if ((data = bunny_ini_scope_get_field(scope, "refraction", 1)) == NULL)
	return (1);
      refrac->indice = get_double((char*)data);
    }
  return (0);
}

static int	get_ini_perlin(t_bunny_ini_scope *scope, t_perlin *perlin)
{
  const char	*data;

  if ((data = bunny_ini_scope_get_field(scope, "perlin", 0)) == NULL)
    {
      perlin->ratio = 0;
      perlin->tab = NULL;
      return (0);
    }
  perlin->ratio = get_double((char*)data);
  if (perlin->ratio > 1 || perlin->ratio < 0)
    return (1);
  if ((data = bunny_ini_scope_get_field(scope, "perlin", 1)) == NULL)
    return (1);
  perlin->persis = get_double((char*)data);
  if (perlin->persis > 1 || perlin->persis <= 0)
    return (1);
  if ((data = bunny_ini_scope_get_field(scope, "perlin", 2)) == NULL)
    return (1);
  perlin->type = get_double((char*)data);
  if (perlin->type != 2 && perlin->type != 1 && perlin->type != 0)
    return (1);
  if (gen_perlin_tab(perlin) == 1)
    return (1);
  return (0);
}

static int	get_ini_color(t_bunny_ini_scope *scope, t_color *color)
{
  const char	*data;

  if ((data = bunny_ini_scope_get_field(scope, "color", 0)) == NULL)
    color->argb[RED_CMP] = 255;
  else
    color->argb[RED_CMP] = get_double((char*)data);
  if ((data = bunny_ini_scope_get_field(scope, "color", 1)) == NULL)
    color->argb[GREEN_CMP] = 255;
  else
    color->argb[GREEN_CMP] = get_double((char*)data);
  if ((data = bunny_ini_scope_get_field(scope, "color", 2)) == NULL)
    color->argb[BLUE_CMP] = 255;
  else
    color->argb[BLUE_CMP] = get_double((char*)data);
  if ((data = bunny_ini_scope_get_field(scope, "color", 3)) == NULL)
    color->argb[ALPHA_CMP] = 0;
  else
    color->argb[ALPHA_CMP] = get_double((char*)data);
  return (0);
}

int	get_ini_meta(t_bunny_ini_scope *scope, t_meta *meta)
{
  if ((meta->tex = get_tex(scope)) == NULL)
    {
      if (get_ini_color(scope, &meta->color) == 1)
	return (1);
    }
  if (get_ini_vec(scope, "position", &meta->pos) == 1)
    return (1);
  if (get_ini_vec(scope, "rotation", &meta->rot) == 1)
    {
      meta->rot.x = 0;
      meta->rot.y = 0;
      meta->rot.z = 0;
    }
  if (get_ini_ratio(scope, "reflection", &meta->reflec) == 1)
    meta->reflec = 1;
  if (get_ini_ratio(scope, "mirroring", &meta->mirroring) == 1)
    meta->mirroring = 0;
  if (get_ini_refraction(scope, &meta->refrac) == 1)
    return (1);
  if (get_ini_perlin(scope, &meta->perlin) == 1)
    return (1);
  return (0);
}
