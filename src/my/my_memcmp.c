/*
** my_memcmp.c for mem in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 11:50:56 2016 alies_a
** Last update Wed Apr 20 11:53:04 2016 alies_a
*/

#include <stddef.h>

int     	my_memcmp(const void *s1, const void *s2, size_t n)
{
  size_t	x;

  x = 0;
  while (x < n)
    {
      if (((char*)s1)[x] != ((char*)s2)[x])
	return (((char*)s1)[x] - ((char*)s2)[x]);
      x += 1;
    }
  return (0);
}
