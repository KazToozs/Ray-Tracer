/*
** lum.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Mar  6 12:51:45 2015 ugo belfiore
** Last update Thu May 14 12:45:07 2015 ugo belfiore
*/

#include "mini.h"

void	translate(t_data *d, int x, int y, int z)
{
  d->o.view.x_eyes += x;
  d->o.view.y_eyes += y;
  d->o.view.z_eyes += z;
}

void	inv_translate(t_data *d, int x, int y, int z)
{
  d->o.view.x_eyes -= x;
  d->o.view.y_eyes -= y;
  d->o.view.z_eyes -= z;
}

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

void	calculate_n(t_data *d, int i)
{
  if (d->kk == SPHERE)
    {
      d->o.lum.sx[i] = d->o.lum.px[i];
      d->o.lum.sy[i] = d->o.lum.py[i];
      d->o.lum.sz[i] = d->o.lum.pz[i];
    }
  else if (d->kk == PLANE)
    {
      d->o.lum.sx[i] = 0;
      d->o.lum.sy[i] = 0;
      d->o.lum.sz[i] = 100;
    }
  else if (d->kk == CYLINDER)
    {
      d->o.lum.sx[i] = d->o.lum.px[i];
      d->o.lum.sy[i] = d->o.lum.py[i];
      d->o.lum.sz[i] = d->o.cy.rotz[i];
    }
  else if (d->kk == CONE)
    {
      d->o.lum.sx[i] = d->o.lum.px[i];
      d->o.lum.sy[i] = d->o.lum.py[i];
      d->o.lum.sz[i] = d->o.co.rotz[i];
    }
}

void	lum(t_data *d, int i)
{
  d->o.lum.px[i] = d->o.view.x_eyes + (d->k * d->o.view.vx);
  d->o.lum.py[i] = d->o.view.y_eyes + (d->k * d->o.view.vy);
  d->o.lum.pz[i] = d->o.view.z_eyes + (d->k * d->o.view.vz);
  d->o.lum.lx[i] = d->o.lum.x_lum[i] - d->o.lum.px[i];
  d->o.lum.ly[i] = d->o.lum.y_lum[i] - d->o.lum.py[i];
  d->o.lum.lz[i] = d->o.lum.z_lum[i] - d->o.lum.pz[i];
  if (shadow(d) == -1)
    return;
  calculate_n(d, i);
  d->o.cal.cosy = (((d->o.lum.sx[i] * d->o.lum.lx[i])
		    + (d->o.lum.sy[i] * d->o.lum.ly[i])
		    + (d->o.lum.sz[i] * d->o.lum.lz[i]))
		   / sqrt((pow(d->o.lum.sx[i], 2)
			   + pow(d->o.lum.sy[i], 2)
			   + pow(d->o.lum.sz[i], 2)) *
			  (pow(d->o.lum.lx[i], 2) + pow(d->o.lum.ly[i], 2)
			   + pow(d->o.lum.lz[i], 2))));
  if (d->o.cal.cosy > 0.000001)
    my_change_color(d);
  else
    d->colo = COLOR_BLACK;
}
