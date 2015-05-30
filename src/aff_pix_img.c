/*
** aff_pix_img.c for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 31 16:36:46 2014 ugo belfiore
** Last update Sun May 31 00:53:49 2015 ugo belfiore
*/

#include "mini.h"

/*
** affiche un pixel à l'écran aux position x et y.
** (gère l'endian pour afficher la couleur en RGB ou BGR).
*/

void	aff_pix_img_zero(t_wild *w, int x, int y, char *img)
{
  int	i;

  if (x < 0 || x >= w->d.x_max)
    return;
  if (y < 0 || y >= w->d.y_max)
    return;
  i = (w->d.sizeline * y) + (x * (w->d.bpp / 8));
  img[i] = mlx_get_color_value(w->d.mlx_ptr, w->s[0].colo);
  img[i + 1] = mlx_get_color_value(w->d.mlx_ptr, w->s[0].colo >> 8);
  img[i + 2] = mlx_get_color_value(w->d.mlx_ptr, w->s[0].colo >> 16);
}

void	aff_pix_img_one(t_wild *w, int x, int y, char *img)
{
  int	i;

  if (x < 0 || x >= w->d.x_max)
    return;
  if (y < 0 || y >= w->d.y_max)
    return;
  i = (w->d.sizeline * y) + (x * (w->d.bpp / 8));
  img[i] = mlx_get_color_value(w->d.mlx_ptr, w->s[1].colo);
  img[i + 1] = mlx_get_color_value(w->d.mlx_ptr, w->s[1].colo >> 8);
  img[i + 2] = mlx_get_color_value(w->d.mlx_ptr, w->s[1].colo >> 16);
}

void	aff_pix_img_two(t_wild *w, int x, int y, char *img)
{
  int	i;

  if (x < 0 || x >= w->d.x_max)
    return;
  if (y < 0 || y >= w->d.y_max)
    return;
  i = (w->d.sizeline * y) + (x * (w->d.bpp / 8));
  img[i] = mlx_get_color_value(w->d.mlx_ptr, w->s[2].colo);
  img[i + 1] = mlx_get_color_value(w->d.mlx_ptr, w->s[2].colo >> 8);
  img[i + 2] = mlx_get_color_value(w->d.mlx_ptr, w->s[2].colo >> 16);
}

void	aff_pix_img_tree(t_wild *w, int x, int y, char *img)
{
  int	i;

  if (x < 0 || x >= w->d.x_max)
    return;
  if (y < 0 || y >= w->d.y_max)
    return;
  i = (w->d.sizeline * y) + (x * (w->d.bpp / 8));
  img[i] = mlx_get_color_value(w->d.mlx_ptr, w->s[3].colo);
  img[i + 1] = mlx_get_color_value(w->d.mlx_ptr, w->s[3].colo >> 8);
  img[i + 2] = mlx_get_color_value(w->d.mlx_ptr, w->s[3].colo >> 16);
}

void	aff_pix_img_four(t_wild *w, int x, int y, char *img)
{
  int	i;

  if (x < 0 || x >= w->d.x_max)
    return;
  if (y < 0 || y >= w->d.y_max)
    return;
  i = (w->d.sizeline * y) + (x * (w->d.bpp / 8));
  img[i] = mlx_get_color_value(w->d.mlx_ptr, w->s[4].colo);
  img[i + 1] = mlx_get_color_value(w->d.mlx_ptr, w->s[4].colo >> 8);
  img[i + 2] = mlx_get_color_value(w->d.mlx_ptr, w->s[4].colo >> 16);
}
