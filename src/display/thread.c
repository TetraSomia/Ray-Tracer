/*
** thread.c for rt in /home/josso/rendu/gfx/gfx_raytracer1
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Feb 20 15:53:09 2016 Arthur Josso
** Last update Sat Feb 20 15:53:09 2016 Arthur Josso
*/

#include <pthread.h>
#include "rt.h"

static void	*slice_1(void *data_pt)
{
  t_data	*data;

  data = (t_data*)data_pt;
  gen_slice(data, 0, data->pix->clipable.clip_height / 4);
  return (NULL);
}

static void	*slice_2(void *data_pt)
{
  t_data	*data;

  data = (t_data*)data_pt;
  gen_slice(data, data->pix->clipable.clip_height / 4,
	    data->pix->clipable.clip_height / 2);
  return (NULL);
}

static void     *slice_3(void *data_pt)
{
  t_data        *data;

  data = (t_data*)data_pt;
  gen_slice(data, data->pix->clipable.clip_height / 2,
	    (3 * data->pix->clipable.clip_height) / 4);
  return (NULL);
}

static void     *slice_4(void *data_pt)
{
  t_data        *data;

  data = (t_data*)data_pt;
  gen_slice(data, (3 * data->pix->clipable.clip_height) / 4,
	    data->pix->clipable.clip_height);
  return (NULL);
}

int		gen_scene(t_data *data)
{
  pthread_t	thr_1;
  pthread_t	thr_2;
  pthread_t     thr_3;
  pthread_t     thr_4;

  pthread_create(&thr_1, NULL, slice_1, (void*)data);
  pthread_create(&thr_2, NULL, slice_2, (void*)data);
  pthread_create(&thr_3, NULL, slice_3, (void*)data);
  pthread_create(&thr_4, NULL, slice_4, (void*)data);
  pthread_join(thr_1, NULL);
  pthread_join(thr_2, NULL);
  pthread_join(thr_3, NULL);
  pthread_join(thr_4, NULL);
  return (SUCCESS);
}
