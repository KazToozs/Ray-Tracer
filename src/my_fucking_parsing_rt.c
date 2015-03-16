/*
** my_str_to_wordtab.c for  in /home/belfio_u/rendu/Piscine_C_J08/ex_04
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 24 19:29:19 2014 ugo belfiore
** Last update Mon Mar 16 17:17:49 2015 ugo belfiore
*/

#include "../include/my.h"
#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"

void	my_fucking_parsing_rt(t_data *d, char *av)
{
  
  int	i;

  printf("%d %d %d\n", d->o.view.x_eyes, d->o.view.y_eyes, d->o.view.z_eyes);
  printf("%f %f %f\n", d->o.view.rotangx, d->o.view.rotangy, d->o.view.rotangz);
  i = -1;
  while (++i < 3)
    printf("%f %f %f\n", d->o.lum.x_lum[i], d->o.lum.y_lum[i], d->o.lum.z_lum[i]);
  i = -1;
  while (++i < 3)
    printf("%d %d %d %d %d\n", d->o.sph.x_sphere[i], d->o.sph.y_sphere[i], d->o.sph.z_sphere[i], d->o.sph.r_sh[i], d->o.sph.color_sphere[i]);
  i = -1;
  while (++i < 3)
    printf("%d %d %d %d %d\n", d->o.cy.x_cyl[i], d->o.cy.y_cyl[i], d->o.cy.z_cyl[i], d->o.cy.r_cyl[i], d->o.cy.color_cyl[i]);
  i = -1;
  while (++i < 2)
    printf("%d %d %d %d %d\n", d->o.co.x_cone[i], d->o.co.y_cone[i], d->o.co.z_cone[i], d->o.co.r_cone[i], d->o.co.color_cone[i]);
}
