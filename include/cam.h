/*
** cam.h for cam in /home/alies_a/rendu/gfx_raytracer2/src/cam
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Wed Apr 20 19:14:15 2016 alies_a
** Last update Sat May 21 16:39:24 2016 Arthur Josso
*/

#ifndef CAM_H_
# define CAM_H_

# include "jif.h"
# include "core.h"

t_cam_path	*cam_path_open(const char *file, t_jif_mode mode);

int		cam_path_write(t_cam_path *path, const t_cam *cam);
int		cam_path_read(t_cam_path *path, t_cam *cam);

void		cam_path_close(t_cam_path *path);
int		cam_gen(t_data *data);

int		cam_record(t_data *data);

#endif
