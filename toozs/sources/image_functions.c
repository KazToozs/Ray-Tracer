/*
** image_functions.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/sources
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Sun Mar  1 11:30:37 2015 cristopher toozs-hobson
** Last update Thu Mar 12 11:07:48 2015 cristopher toozs-hobson
*/

#include "rt.h"

void		put_pixel(int pos_x, int pos_y, t_data *d, t_pic p)
{
  int		x;
  int		y;
  int		tab;

  if (pos_x <= 0 || pos_x >= p.win_x)
    return ;
  if (pos_y <= 0 || pos_y >= p.win_y)
    return ;
  x = pos_x * (d->bpp / 8);
  y = pos_y * ((d->bpp / 8) * (d->line / 4));
  tab = x + y;
  if (d->end == 0)
    {
      d->d[tab] = d->blue;
      d->d[tab + 1] = d->green;
      d->d[tab + 2] = d->red;
      d->d[tab + 3] = 255;
    }
  else
    {
      d->d[tab] = d->red;
      d->d[tab + 1] = d->green;
      d->d[tab + 2] = d->blue;
      d->d[tab + 3] = 255;
    }
}
