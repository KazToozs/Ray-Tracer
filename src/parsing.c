/*
** parsing.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Mar 16 10:54:20 2015 ugo belfiore
** Last update Mon Mar 16 16:38:01 2015 ugo belfiore
*/

#include "../include/my.h"
#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"

/*
** initialisation de tout (appelé au début et lors du refresh)
*/

void	parsing(t_data *d)
{
  int	i;

  i = -1;
  d->o.view.x_eyes = -450;
  d->o.view.y_eyes = 0;
  d->o.view.z_eyes = 50;
  d->o.view.rotangx = 0;
  d->o.view.rotangy = 0;
  d->o.view.rotangz = 0;
  init_sphere(d);
  init_cyl(d);
  init_cone(d);
  d->o.pl.high = 10;
  d->o.pl.color_plan = COLOR_BLUE;
  d->o.lum.x_lum = -200;
  d->o.lum.y_lum = 0;
  d->o.lum.z_lum = 0;
  d->timer = 0;
  while (++i < 18)
    d->f[i] = 0;
}

void    init_sphere(t_data *d)
{
  d->o.sph.x_sphere[0] = d->o.view.x_eyes + 200;
  d->o.sph.y_sphere[0] = d->o.view.y_eyes;
  d->o.sph.z_sphere[0] = d->o.view.z_eyes + 0;
  d->o.sph.r_sh[0] = 10;
  d->o.sph.color_sphere[0] = COLOR_YELLOW;
  d->o.sph.x_sphere[1] = d->o.view.x_eyes + 0;
  d->o.sph.y_sphere[1] = d->o.view.y_eyes + 100;
  d->o.sph.z_sphere[1] = d->o.view.z_eyes - 100;
  d->o.sph.r_sh[1] = 20;
  d->o.sph.color_sphere[1] = COLOR_WHITE;
  d->o.sph.x_sphere[2] = d->o.view.x_eyes + 100;
  d->o.sph.y_sphere[2] = d->o.view.y_eyes - 100;
  d->o.sph.z_sphere[2] = d->o.view.z_eyes - 100;
  d->o.sph.r_sh[2] = 30;
  d->o.sph.color_sphere[2] = COLOR_RED;
}

void    init_cyl(t_data *d)
{
  d->o.cy.x_cyl[0] = d->o.view.x_eyes - 30;
  d->o.cy.y_cyl[0] = d->o.view.y_eyes - 15;
  d->o.cy.z_cyl[0] = d->o.view.z_eyes - 10;
  d->o.cy.r_cyl[0] = 20;
  d->o.cy.color_cyl[0] = COLOR_PURPLE;
  d->o.cy.x_cyl[1] = d->o.view.x_eyes + 0;
  d->o.cy.y_cyl[1] = d->o.view.y_eyes + 102;
  d->o.cy.z_cyl[1] = d->o.view.z_eyes - 120;
  d->o.cy.r_cyl[1] = 10;
  d->o.cy.color_cyl[1] = COLOR_WHITE;
  d->o.cy.x_cyl[2] = d->o.view.x_eyes + 105;
  d->o.cy.y_cyl[2] = d->o.view.y_eyes - 100;
  d->o.cy.z_cyl[2] = d->o.view.z_eyes - 10;
  d->o.cy.r_cyl[2] = 15;
  d->o.cy.color_cyl[2] = COLOR_YELLOW;
}

void    init_cone(t_data *d)
{
  d->o.co.x_cone[0] = d->o.view.x_eyes - 75;
  d->o.co.y_cone[0] = d->o.view.y_eyes + 45;
  d->o.co.z_cone[0] = d->o.view.z_eyes + 65;
  d->o.co.r_cone[0] = 120;
  d->o.co.color_cone[0] = COLOR_GREEN;
  d->o.co.x_cone[1] = d->o.view.x_eyes - 75;
  d->o.co.y_cone[1] = d->o.view.y_eyes + 190;
  d->o.co.z_cone[1] = d->o.view.z_eyes - 145;
  d->o.co.r_cone[1] = 100;
  d->o.co.color_cone[1] = COLOR_RED;
}
