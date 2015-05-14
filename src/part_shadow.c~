/*
** algo_rt.c for  in /home/belfio_u/rendu/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sun Feb  8 16:18:36 2015 ugo belfiore
** Last update Wed May 13 19:02:59 2015 ugo belfiore
*/

#include "mini.h"

void	part_sph(t_data *d)
{
  int		i;

  i = -1;
  while (++i < d->o.sph.check)
    {
      rotate_x(d, d->o.sph.rotx[i]);
      rotate_y(d, d->o.sph.roty[i]);
      rotate_z(d, d->o.sph.rotz[i]);
      sphere(d, i);
      rotate_x(d, -d->o.sph.rotx[i]);
      rotate_y(d, -d->o.sph.roty[i]);
      rotate_z(d, -d->o.sph.rotz[i]);
    }
}

void	part_cyl(t_data *d)
{
  int		i;

  i = -1;
  while (++i < d->o.cy.check)
    {
      rotate_x(d, d->o.cy.rotx[i]);
      rotate_y(d, d->o.cy.roty[i]);
      rotate_z(d, d->o.cy.rotz[i]);
      cyl(d, i);
      rotate_x(d, -d->o.cy.rotx[i]);
      rotate_y(d, -d->o.cy.roty[i]);
      rotate_z(d, -d->o.cy.rotz[i]);
    }
}

void	part_cone(t_data *d)
{
  int		i;

  i = -1;
  while (++i < d->o.co.check)
    {
      rotate_x(d, d->o.co.rotx[i]);
      rotate_y(d, d->o.co.roty[i]);
      rotate_z(d, d->o.co.rotz[i]);
      cone(d, i);
      rotate_x(d, -d->o.co.rotx[i]);
      rotate_y(d, -d->o.co.roty[i]);
      rotate_z(d, -d->o.co.rotz[i]);
    }
}

/*
** fonction qui permet de calculer les intersections
** entre chaque objet
*/

static void	calc(t_data *d)
{
  int		i;

  d->k = 100000; // distance maximal (sinon les élément infini comme le cone
		 // ou les plan vont boucler infini.
  d->kk = 0;
  d->colo = COLOR_BLACK;	// couleur initiale black.
  part_sph(d);
  part_cyl(d);
  part_cone(d);
  i = -1;
  while (++i < d->o.pl.check)
    plan(d, i);
  i = -1;


  if (d->w == 1)
    lum(d, 0);
  else
    lum(d, 1);
  /* while (++i < d->o.lum.check) */
  /*   lum(d, i); */
}

/*
** algo principal du rt, qui va boucler sur chaque pixel
** (ou plutot tout les 5 pixel, avec un system qui permet d'afficher
** petit à petit la scène
*/

void	algo_rt(t_data *d, int flew, int flew2)
{
  int	i;
  int	j;

  i = flew;
  j = flew2;
  while (i < d->x_max)
    {
      while (j < d->y_max)
	{
	  d->o.view.vx = 1000;
          d->o.view.vy = (d->x_max / 2) - i;
          d->o.view.vz = (d->y_max / 2) - j;
	  rotate_x(d, d->o.view.rotangx);
	  rotate_y(d, d->o.view.rotangy);
	  rotate_z(d, d->o.view.rotangz);
	  calc(d);
	  aff_pix_img(d, i, j, d->bigData);
	  j += 5;
	}
      j = flew2;
      i += 5;
    }
  mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
}
