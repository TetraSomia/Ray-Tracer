/*
** keys.h for keys management in /home/alies_a/rendu/gfx_raytracer2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 14:09:11 2016 alies_a
** Last update Sat May 21 16:44:11 2016 Arthur Josso
*/

#ifndef KEYS_H_
# define KEYS_H_

# include <lapin.h>

/*
** Every keys have its callback
** Defined by:
** type (key name)
** callback (function called)
** instant, 0/1 (0 if the key is meant to be long pressed)
*/

typedef struct		s_key_callback
{
  t_bunny_keysym	type;
  int			(*callback)(t_data *data);
  int			instant;
}			t_key_callback;

t_bunny_response        update_keys(t_bunny_event_state state,
				    t_bunny_keysym keysym,
				    void *pt_data);
void			manage_keys(t_data *data);

/*
** Callbacks
*/

int     key_esc(t_data *data);

/*
** Camera
*/

int     key_up(t_data *data);
int     key_down(t_data *data);
int     key_forward(t_data *data);
int     key_backward(t_data *data);
int     key_left(t_data *data);
int     key_right(t_data *data);

int     key_left_rotate(t_data *data);
int     key_right_rotate(t_data *data);
int     key_up_rotate(t_data *data);
int     key_down_rotate(t_data *data);

/*
** Toggle effects
*/

int     key_preview(t_data *data);
int     key_phong(t_data *data);
int     key_refrac(t_data *data);
int     key_reflec(t_data *data);
int     key_aa(t_data *data);

int     key_record(t_data *data);

#endif
