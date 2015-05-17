/*
** aff_pix_img.c for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 31 16:36:46 2014 ugo belfiore
** Last update Sun May 17 02:45:33 2015 ugo belfiore
*/

#include "mini.h"

/*
** affiche un pixel à l'écran aux position x et y.
** (gère l'endian pour afficher la couleur en RGB ou BGR).
*/

void	aff_pix_img(t_st *s, int x, int y, char *img)
{
  int	i;

  if (x < 0 || x >= s->d.x_max)
    return;
  if (y < 0 || y >= s->d.y_max)
    return;
  i = (s->d.sizeline * y) + (x * (s->d.bpp / 8));
  img[i] = mlx_get_color_value(s->d.mlx_ptr, s->d.colo);
  img[i + 1] = mlx_get_color_value(s->d.mlx_ptr, s->d.colo >> 8);
  img[i + 2] = mlx_get_color_value(s->d.mlx_ptr, s->d.colo >> 16);
}
