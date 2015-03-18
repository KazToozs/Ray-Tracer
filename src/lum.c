/*
** lum.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Mar  6 12:51:45 2015 ugo belfiore
** Last update Wed Mar 18 16:27:35 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** décalage de bit avec un systeme d'union pour multiplier la couleur
** par le coef
*/

void	my_change_color(t_data *d)
{
  int	R;
  int	G;
  int	B;

  R = d->o.cal.cosy * (d->colo & 0xFF);
  if (R > 255)
    R = 255;
  G = d->o.cal.cosy * ((d->colo >> 8) & 0xFF);
  if (G > 255)
    G = 255;
  B = d->o.cal.cosy * ((d->colo >> 16) & 0xFF);
  if (B > 255)
    B = 255;
  d->colo = (R) + (G * 0x100) + (B * 0x10000);
}

/*
** fonction de la luminosité
*/

void	lum(t_data *d, int i)
{
  d->o.lum.px = d->o.view.x_eyes + (d->k * d->o.view.vx);
  d->o.lum.py = d->o.view.y_eyes + (d->k * d->o.view.vy);
  d->o.lum.pz = d->o.view.z_eyes + (d->k * d->o.view.vz);
  d->o.lum.lx = d->o.lum.px - d->o.lum.x_lum[i];
  d->o.lum.ly = d->o.lum.py - d->o.lum.y_lum[i];
  d->o.lum.lz = d->o.lum.pz - d->o.lum.z_lum[i];
  d->o.cal.sca = (d->o.lum.px * d->o.lum.lx)
    + (d->o.lum.py * d->o.lum.ly) + (d->o.lum.pz * d->o.lum.lz);
  d->o.cal.norm = sqrt(pow(d->o.lum.px, 2) + pow(d->o.lum.py, 2)
		       + pow(d->o.lum.pz, 2));
  d->o.cal.norl = sqrt(pow(d->o.lum.lx, 2) + pow(d->o.lum.ly, 2)
		       + pow(d->o.lum.lz, 2));
  d->o.cal.cosy = (d->o.cal.sca / (d->o.cal.norm * d->o.cal.norl));
  d->o.cal.cosy = 1 - d->o.cal.cosy;
  if (d->o.cal.cosy <= 0)
    d->colo = 0;
  else
    my_change_color(d);
}
