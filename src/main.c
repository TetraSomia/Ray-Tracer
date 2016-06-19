/*
** main.c for rt in /home/josso/en_cours/rt
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Fri Jan 29 18:33:22 2016 Arthur Josso
** Last update Sat May 21 15:46:14 2016 Arthur Josso
*/

#include "rt.h"
#include "keys.h"
#include "cam.h"

t_bunny_response        mainloop(void *pt_data)
{
  t_data		*data;
  t_bunny_position	origin;

  origin.x = 0;
  origin.y = 0;
  data = (t_data*)pt_data;
  earth_rot(1);
  data->pix = (data->gen_type & IS_PREVIEW ? data->small : data->big);
  data->gen_type |= IS_PREVIEW;
  gen_scene(data);
  if (cam_record(data))
    return (EXIT_ON_ERROR);
  manage_keys(data);
  bunny_blit(&data->win->buffer, &data->big->clipable, &origin);
  bunny_blit(&data->win->buffer, &data->small->clipable, &origin);
  bunny_display(data->win);
  return (GO_ON);
}

static int	setup(int ac, char **av, t_data *data)
{
  if (ac >= 2)
    {
      if (init(data, av[1]) == ERROR)
	return (ERROR);
      if (ac == 3)
	{
	  if ((data->path = cam_path_open(av[2], J_READ)) == NULL)
	    return (ERROR);
	  if ((data->jif = jif_new("gen.jif", W_X, W_Y, 10)) == NULL)
	    return (ERROR);
	}
    }
  else
    {
      if (init(data, "./demo/demo1.ini") == ERROR)
	return (ERROR);
    }
  return (SUCCESS);
}

int		main(int ac, char **av)
{
  t_data	data;

  bunny_set_maximum_ram(1e8);
  data.path = NULL;
  data.jif = NULL;
  if (setup(ac, av, &data) == ERROR)
    return (ERROR);
  if (data.path == NULL)
    {
      if ((data.path = cam_path_open("camera.path", J_WRITE)) == NULL)
	return (ERROR);
    }
  if (data.jif != NULL)
    cam_gen(&data);
  bunny_set_key_response(&update_keys);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(data.win, FPS, &data);
  exit_prog(&data);
  bunny_set_memory_check(true);
  return (SUCCESS);
}
