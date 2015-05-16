/*
** algo_rt.c for  in /home/belfio_u/rendu/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sun Feb  8 16:18:36 2015 ugo belfiore
** Last update Sat May 16 14:41:05 2015 ugo belfiore
*/

#include "mini.h"

void	part_sph_shadow(t_data *d)
{
  int		i;

  i = -1;
  while (++i < d->o.sph.check)
    {
      rotate_x(d, d->o.sph.rotx[i]);
      rotate_y(d, d->o.sph.roty[i]);
      rotate_z(d, d->o.sph.rotz[i]);
      sphere_shadow(d, i);
      rotate_x(d, -d->o.sph.rotx[i]);
      rotate_y(d, -d->o.sph.roty[i]);
      rotate_z(d, -d->o.sph.rotz[i]);
    }
}

void	part_cyl_shadow(t_data *d)
{
  int		i;

  i = -1;
  while (++i < d->o.cy.check)
    {
      rotate_x(d, d->o.cy.rotx[i]);
      rotate_y(d, d->o.cy.roty[i]);
      rotate_z(d, d->o.cy.rotz[i]);
      cyl_shadow(d, i);
      rotate_x(d, -d->o.cy.rotx[i]);
      rotate_y(d, -d->o.cy.roty[i]);
      rotate_z(d, -d->o.cy.rotz[i]);
    }
}

void	part_cone_shadow(t_data *d)
{
  int		i;

  i = -1;
  while (++i < d->o.co.check)
    {
      rotate_x(d, d->o.co.rotx[i]);
      rotate_y(d, d->o.co.roty[i]);
      rotate_z(d, d->o.co.rotz[i]);
      cone_shadow(d, i);
      rotate_x(d, -d->o.co.rotx[i]);
      rotate_y(d, -d->o.co.roty[i]);
      rotate_z(d, -d->o.co.rotz[i]);
    }
}
