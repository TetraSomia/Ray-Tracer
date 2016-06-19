/*
** color.c for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Jan 31 21:33:56 2016 Arthur Josso
** Last update Sun Jan 31 21:45:55 2016 Arthur Josso
*/

#include "rt.h"

t_color		get_color(t_color *src, float coef)
{
  t_color	color;

  color.argb[RED_CMP] = src->argb[RED_CMP] * coef;
  color.argb[BLUE_CMP] = src->argb[BLUE_CMP] * coef;
  color.argb[GREEN_CMP] = src->argb[GREEN_CMP] * coef;
  color.argb[ALPHA_CMP] = 0;
  return (color);
}
