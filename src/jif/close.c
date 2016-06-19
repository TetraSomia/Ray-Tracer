/*
** close.c for close in /home/alies_a/rendu/gfx_raytracer2/gif
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Apr 14 18:52:46 2016 alies_a
** Last update Fri May 13 14:56:19 2016 alies_a
*/

#include <stdlib.h>
#include <unistd.h>
#include "jif.h"

void	jif_close(t_jif *jif)
{
  close(jif->fd);
  bunny_free(jif);
}
