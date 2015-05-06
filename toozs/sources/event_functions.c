/*
** event_functions.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/sources
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Sun Mar  1 11:30:25 2015 cristopher toozs-hobson
** Last update Wed Mar 11 13:56:32 2015 cristopher toozs-hobson
*/

#include <stdlib.h>
#include "mlx.h"
#include "rt.h"

int		manage_expose(void *param)
{
  t_data	*d;

  d = (t_data *)(param);
  mlx_put_image_to_window(d->mlx_pt, d->win_pt, d->img_pt, 0, 0);
  return (0);
}

int		manage_key(int keycode, void *param)
{
  t_st		*s;

  s = (t_st *)(param);
  if (keycode == 65307)
    exit(0);
  camera_control(s, keycode);
  light_control(s, keycode);
  sphere_control(s, keycode);
  cone_control(s, keycode);
  cylinder_control(s, keycode);
  return (0);
}

void		manage_events(t_st *strct)
{
  t_data	*d;

  d = &strct->d;
  mlx_key_hook(d->win_pt, &manage_key, (void *)(strct));
  mlx_expose_hook(d->win_pt, &manage_expose, (void *)(d));
}
