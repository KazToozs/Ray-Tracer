/*
** main.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/sources
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Sun Mar  1 11:30:13 2015 cristopher toozs-hobson
** Last update Thu Mar 12 11:07:16 2015 cristopher toozs-hobson
*/

#include <stdlib.h>
#include "mlx.h"
#include "rt.h"

int		initialize_structs(t_st *s)
{
  s->p.win_x = 800;
  s->p.win_y = 600;
  if ((s->d.mlx_pt = mlx_init()) == NULL)
    return (1);
  s->d.win_pt = mlx_new_window(s->d.mlx_pt, s->p.win_x, s->p.win_y, "RTV1");
  s->d.img_pt = mlx_new_image(s->d.mlx_pt, s->p.win_x, s->p.win_y);
  s->d.d = mlx_get_data_addr(s->d.img_pt, &s->d.bpp, &s->d.line, &s->d.end);
  s->p.img_start_x = 0;
  s->p.img_start_y = 0;
  s->p.img_x = s->p.win_x;
  s->p.img_y = s->p.win_y;
  return (0);
}

void		init_calc(t_st *s, int x, int y)
{
  s->x.k = 10000000;
  s->d.red = 0;
  s->d.green = 0;
  s->d.blue = 0;
  s->c.v.vx = 1000;
  s->c.v.vy = (s->p.img_x / 2) - x;
  s->c.v.vz = (s->p.img_y / 2) - y;
}

void		calculate_colour(t_st *s, int x, int y)
{
  init_calc(s, x, y);
  rotate(&s->c.rot, &s->c);
  inter_cyl(&s->c, &s->cy);
  inter_cone(&s->c, &s->co);
  inter_sphere(&s->c, &s->s);
  inter_plan(s, &s->c);
  calculate_k(s);
  light(s);
}

void		calculate_pixels(t_st *s)
{
  int		x;
  int		y;

  y = 0;
  while (y < s->p.img_y)
    {
      x = 0;
      while (x < s->p.img_x)
	{
	  calculate_colour(s, x, y);
	  put_pixel(x, y, &s->d, s->p);
	  x++;
	}
      y++;
    }
  mlx_put_image_to_window(s->d.mlx_pt, s->d.win_pt, s->d.img_pt, 0, 0);
}

int		main()
{
  t_st		s;

  if (initialize_structs(&s) == 1)
    return (1);
  else
    {
      init_cam(&s);
      init_sphere(&s);
      init_plan(&s);
      init_cyl(&s);
      init_cone(&s);
      init_lit(&s);
      calculate_pixels(&s);
      manage_events(&s);
      mlx_loop(s.d.mlx_pt);
    }
  return (0);
}
