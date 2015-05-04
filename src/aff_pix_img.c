/*
** aff_pix_img.c for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 31 16:36:46 2014 ugo belfiore
** Last update Mon May  4 12:58:14 2015 ugo belfiore
*/

#include "mini.h"

/*
** affiche un pixel à l'écran aux position x et y.
** (gère l'endian pour afficher la couleur en RGB ou BGR).
*/

void	aff_pix_img(t_data *d, int x, int y, char *img)
{
  int	i;

  if (x < 0 || x >= d->x_max)
    return;
  if (y < 0 || y >= d->y_max)
    return;
  i = (d->sizeline * y) + (x * (d->bpp / 8));
  img[i] = mlx_get_color_value(d->mlx_ptr, d->colo);
  img[i + 1] = mlx_get_color_value(d->mlx_ptr, d->colo >> 8);
  img[i + 2] = mlx_get_color_value(d->mlx_ptr, d->colo >> 16);
}
