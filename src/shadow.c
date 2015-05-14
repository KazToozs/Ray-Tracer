/*
** shadow.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue May 12 11:16:50 2015 ugo belfiore
** Last update Wed May 13 19:55:28 2015 ugo belfiore
*/

#include "mini.h"

int	shadow(t_data *d)
{
  int	i;

  d->k = 100000;
  part_sph(d);
  part_cyl(d);
  part_cone(d);
  i = -1;
  while (++i < d->o.pl.check)
    plan(d, i);
  if (d->k > 0.000001 && d->k < 1 && d->k != 100000)
    {
      //d->colo = COLOR_BLACK;
      //return (-1);
    }
  return (0);
}
