/*
** light_control.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/sources
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Mar 10 14:49:31 2015 cristopher toozs-hobson
** Last update Wed Mar 11 11:01:20 2015 cristopher toozs-hobson
*/

#include "rt.h"
#include "mlx.h"

void		light_xy(t_st *s, int keycode)
{
  if (keycode == 105)
    {
      s->l.p.x += 25;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
  else if (keycode == 107)
    {
      s->l.p.x -= 25;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
  else if (keycode == 106)
    {
      s->l.p.y += 25;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
  else if (keycode == 108)
    {
      s->l.p.y -= 25;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
}

void		light_z(t_st *s, int keycode)
{
  if (keycode == 112)
    {
      s->l.p.z += 25;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
  else if (keycode == 109)
    {
      s->l.p.z -= 25;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
}

void		light_control(t_st *s, int keycode)
{
  light_xy(s, keycode);
  light_z(s, keycode);
}
