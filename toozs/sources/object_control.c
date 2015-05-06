/*
** object_control.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/sources
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Wed Mar 11 11:05:40 2015 cristopher toozs-hobson
** Last update Wed Mar 11 11:40:42 2015 cristopher toozs-hobson
*/

#include "rt.h"
#include "mlx.h"

void		sphere_control(t_st *s, int keycode)
{
  if (keycode == 114)
    {
      s->s.p.x += 100;
      s->s.p.y += 100;
      s->s.p.z += 100;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
  else if (keycode == 102)
    {
      s->s.p.x -= 100;
      s->s.p.y -= 100;
      s->s.p.z -= 100;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
}

void		cylinder_control(t_st *s, int keycode)
{
  if (keycode == 116)
    {
      s->cy.p.x += 100;
      s->cy.p.y += 100;
      s->cy.p.z += 100;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
  else if (keycode == 103)
    {
      s->cy.p.x -= 100;
      s->cy.p.y -= 100;
      s->cy.p.z -= 100;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
}

void		cone_control(t_st *s, int keycode)
{
  if (keycode == 121)
    {
      s->co.p.x += 100;
      s->co.p.y += 100;
      s->co.p.z += 100;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
  else if (keycode == 104)
    {
      s->co.p.x -= 100;
      s->co.p.y -= 100;
      s->co.p.z -= 100;
      calculate_pixels(s);
      mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
    }
}
