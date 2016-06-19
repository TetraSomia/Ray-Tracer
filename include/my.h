/*
** my.h for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Feb 20 15:29:45 2016 Arthur Josso
** Last update Sat Apr 23 15:57:38 2016 Arthur Josso
*/

#ifndef MY_H_
# define MY_H_

# include <lapin.h>

# define BUFF_SIZE	(10)
# define READ_SIZE	(64)

int     my_strcmp(char *s1, char *s2);
int     get_nbr(char *s);
double  get_double(char *s);
t_color get_pixel(t_bunny_pixelarray *pix,
		  t_bunny_position *pos);
void	my_memset(void *s, char c, size_t n);
int	my_memcmp(const void *s1, const void *s2, size_t n);
char	*get_next_line(int fd);
void	my_epurstr(char *s, char sep);
char    **my_str_to_tab(const char *s, char sep);
int	is_float(char const *s);
int	is_number(char const *s);

#endif
