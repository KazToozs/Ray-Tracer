/*
** shadow.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue May 12 11:16:50 2015 ugo belfiore
** Last update Sat May 16 17:22:22 2015 ugo belfiore
*/

#include "mini.h"

int	shadow(t_data *d)
{
  int	i;

  d->k = 10000;
  part_sph_shadow(d);
  part_cyl_shadow(d);
  part_cone_shadow(d);
  i = -1;
  while (++i < d->o.pl.check)
    plan_shadow(d, i);
  if (d->k > 0.001 && d->k < 1)
    {
      d->colo = COLOR_PURPLE;
      return (-1);
    }
  return (0);
}
