/*
** algo_rt.c for  in /home/belfio_u/rendu/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sun Feb  8 16:18:36 2015 ugo belfiore
** Last update Wed Mar 18 16:21:00 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** fonction qui permet de calculer les intersections
** entre chaque objet
*/

static void	calc(t_data *d)
{
  int		i;

  d->k = 100000; // distance maximal (sinon les élément infini comme le cone
		 // ou les plan vont boucler infini.
  d->colo = COLOR_BLACK;	// couleur initiale black.
  i = -1;
  while (++i < d->o.sph.check)
    sphere(d, i);
  i = -1;
  while (++i < d->o.cy.check)
    {
      if (i == 2)
	rotate_x(d, 40);
      cyl(d, i);
      if (i == 2)
	rotate_x(d, -40);
    }
  i = -1;
  while (++i < d->o.co.check)
    cone(d, i);
  i = -1;
  while (++i < d->o.pl.check)
    plan(d, i);
  i = -1;
  while (++i < d->o.lum.check)
    lum(d, i);
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
