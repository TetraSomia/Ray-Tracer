/*
** new.c for new in /home/alies_a/rendu/gfx_raytracer2/gif/src/jif
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 13 17:18:37 2016 alies_a
** Last update Fri May 13 14:49:08 2016 alies_a
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "jif.h"

static int      jif_write_header(int fd, t_jif_header *header)
{
  if (write(fd, header, sizeof(t_jif_header)) != sizeof(t_jif_header))
    return (1);
  return (0);
}

t_jif   *jif_new(const char *file, int width, int height, int delay)
{
  t_jif	*res;

  if ((res = bunny_malloc(sizeof(t_jif))) == NULL)
    return (NULL);
  res->mode = J_WRITE;
  (res->head).width = width;
  (res->head).height = height;
  (res->head).delay = delay;
  if ((res->fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
    {
      bunny_free(res);
      return (NULL);
    }
  if (jif_write_header(res->fd, &(res->head)))
    {
      close(res->fd);
      bunny_free(res);
      return (NULL);
    }
  return (res);
}
