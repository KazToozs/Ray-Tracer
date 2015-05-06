/*
** camera_control.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/sources
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Mar 10 14:46:05 2015 cristopher toozs-hobson
** Last update Wed Mar 11 12:44:59 2015 cristopher toozs-hobson
*/

#include "mlx.h"
#include "rt.h"

void		cam_xy(t_st *s, int keycode)
{
  if (keycode == 65362)
    {
      s->c.p.x += 200;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
  else if (keycode == 65364)
    {
      s->c.p.x -= 200;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
  else if (keycode == 65361)
    {
      s->c.p.y += 200;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
  else if (keycode == 65363)
    {
      s->c.p.y -= 200;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
}

void		cam_z(t_st *s, int keycode)
{
  if (keycode == 65507)
    {
      s->c.p.z -= 200;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
  else if (keycode == 32)
    {
      s->c.p.z += 200;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
}

void		rot_xy(t_st *s, int keycode)
{
  if (keycode == 65506)
    {
      s->c.rot.x += 15;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
  else if (keycode == 33)
    {
      s->c.rot.x -= 15;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
  else if (keycode == 113)
    {
      s->c.rot.z += 15;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
  else if (keycode == 100)
    {
      s->c.rot.z -= 15;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
}

void		rot_z(t_st *s, int keycode)
{
  if (keycode == 122)
    {
      s->c.rot.y -= 5;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
  else if (keycode == 115)
    {
      s->c.rot.y += 5;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
}

void		camera_control(t_st *s, int keycode)
{
  cam_xy(s, keycode);
  cam_z(s, keycode);
  rot_xy(s, keycode);
  rot_z(s, keycode);
}

