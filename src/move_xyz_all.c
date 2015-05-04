/*
** move_xyz_all.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon May  4 12:45:16 2015 ugo belfiore
** Last update Mon May  4 13:53:08 2015 ugo belfiore
*/

#include "mini.h"

static void	move_yz(t_data *d, int which, int value, int i)
{
  if (which == 2)
    {
      d->o.view.y_eyes += value;
      while (++i < d->o.sph.check)
	d->o.sph.y_sphere[i] += value;
      i = -1;
      while (++i < d->o.cy.check)
	d->o.cy.y_cyl[i] += value;
      i = -1;
      while (++i < d->o.co.check)
	d->o.co.y_cone[i] += value;
    }
  if (which == 3)
    {
      d->o.view.z_eyes += value;
      while (++i < d->o.sph.check)
	d->o.sph.z_sphere[i] += value;
      i = -1;
      while (++i < d->o.cy.check)
	d->o.cy.z_cyl[i] += value;
      i = -1;
      while (++i < d->o.sph.check)
	d->o.co.z_cone[i] += value;
    }
}

void	move_xyz_all(t_data *d, int which, int value)
{
  int	i;

  i = -1;
  if (which == 1)
    {
      d->o.view.x_eyes += value;
      while (++i < d->o.sph.check)
	d->o.sph.x_sphere[i] += value;
      i = -1;
      while (++i < d->o.cy.check)
	d->o.cy.x_cyl[i] += value;
      i = -1;
      while (++i < d->o.cy.check)
	d->o.co.x_cone[i] += value;
    }
  move_yz(d, which, value, i);
  if (which == 4)
    while (++i < d->o.lum.check)
      d->o.lum.x_lum[i] += value;
  if (which == 5)
    while (++i < d->o.lum.check)
      d->o.lum.y_lum[i] += value;
  if (which == 6)
    while (++i < d->o.lum.check)
      d->o.lum.z_lum[i] += value;
}
