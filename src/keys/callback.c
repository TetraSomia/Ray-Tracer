/*
** callback.c for callback in /home/alies_a/rendu/gfx_raytracer2/src/keys
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 14:07:00 2016 alies_a
** Last update Sat May 21 16:24:14 2016 Arthur Josso
*/

#include "core.h"
#include "keys.h"

static t_key_callback	g_callbacks[] = {
  {BKS_D, &key_backward, 0},
  {BKS_E, &key_forward, 0},
  {BKS_S, &key_left, 0},
  {BKS_F, &key_right, 0},
  {BKS_T, &key_up, 0},
  {BKS_G, &key_down, 0},
  {BKS_UP, &key_up_rotate, 0},
  {BKS_DOWN, &key_down_rotate, 0},
  {BKS_LEFT, &key_left_rotate, 0},
  {BKS_RIGHT, &key_right_rotate, 0},
  {BKS_U, &key_phong, 1},
  {BKS_I, &key_reflec, 1},
  {BKS_O, &key_refrac, 1},
  {BKS_P, &key_aa, 1},
  {BKS_BACKSPACE, &key_record, 1},
  {BKS_SPACE, &key_preview, 1},
  {BKS_ESCAPE, &key_esc, 1},
  {BKS_UNKNOWN, NULL, 0}
};

t_bunny_response	update_keys(t_bunny_event_state state,
				    t_bunny_keysym keysym,
				    void *pt_data)
{
  int			x;

  (void)keysym;
  ((t_data*)pt_data)->keys = bunny_get_keyboard();
  x = 0;
  while (g_callbacks[x].callback != NULL)
    {
      if (g_callbacks[x].instant &&
	  keysym == g_callbacks[x].type && state == GO_DOWN)
	{
	  if (g_callbacks[x].callback((t_data*)pt_data))
	    return (EXIT_ON_SUCCESS);
	}
      x += 1;
    }
  return (GO_ON);
}

void		manage_keys(t_data *data)
{
  int		x;

  if (data->keys == NULL)
    return ;
  x = 0;
  while (g_callbacks[x].callback != NULL)
    {
      if (!g_callbacks[x].instant && data->keys[g_callbacks[x].type])
	g_callbacks[x].callback(data);
      x += 1;
    }
  return ;
}
