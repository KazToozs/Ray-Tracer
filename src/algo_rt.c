/*
** algo_rt.c for  in /home/belfio_u/rendu/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sun Feb  8 16:18:36 2015 ugo belfiore
** Last update Mon May 18 12:14:17 2015 ugo belfiore
*/

#include "mini.h"

/*
** fonction qui permet de calculer les intersections
** entre chaque objet
*/

static void	calc(t_st *s)
{

}

/*
** algo principal du rt, qui va boucler sur chaque pixel
** (ou plutot tout les 5 pixel, avec un system qui permet d'afficher
** petit à petit la scène
*/

void	algo_rt(t_st *s, int flew, int flew2)
{
  int	i;
  int	j;

  i = flew;
  j = flew2;
  while (i < s->d.x_max)
    {
      while (j < s->d.y_max)
	{
	  /* d->o.view.vx = 1000; */
          /* d->o.view.vy = (d->x_max / 2) - i; */
          /* d->o.view.vz = (d->y_max / 2) - j; */
	  /* rotate_x(s, s->c.rot.x); */
	  /* rotate_y(s, s->c.rot.y); */
	  /* rotate_z(s, s->c.rot.z); */
	  calc(s);
	  aff_pix_img(s, i, j, s->d.bigData);
	  j += 5;
	}
      j = flew2;
      i += 5;
    }
  mlx_put_image_to_window(s->d.mlx_ptr, s->d.win_ptr, s->d.img_ptr, 0, 0);
}
