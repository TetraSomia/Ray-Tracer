/*
** my_memset.c for memset in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 11:47:38 2016 alies_a
** Last update Wed Apr 20 11:48:00 2016 alies_a
*/

#include <stddef.h>

void            my_memset(void *s, char c, size_t n)
{
  size_t        x;

  x = 0;
  while (x < n)
    {
      ((char*)s)[x] = c;
      x += 1;
    }
}
