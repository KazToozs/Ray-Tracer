/*
** algo_rt.c for  in /home/belfio_u/rendu/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sun Feb  8 16:18:36 2015 ugo belfiore
** Last update Tue May 19 13:10:52 2015 pallua
*/

#include "mini.h"

/*
** fonction qui permet de calculer les intersections
** entre chaque objet
*/

static void	multi_light(t_st *s)
{
  t_cam		*tmp_l;

  tmp_l = s->l;
  while (tmp_l != NULL)
    {
      light(s, tmp_l);
      tmp_l = tmp_l->next;
    }
  if (s->d.nb_spots != 0)
    my_change_color_bis(s);
}

static void	calc(t_st *s)
{
  t_cone	*tmp_c;
  t_cyl		*tmp_cy;
  t_sph		*tmp_s;

  tmp_c = s->co;
  tmp_cy = s->cy;
  tmp_s = s->s;
  while (tmp_cy != NULL)
    {
      inter_cyl(&s->c, tmp_cy);
      tmp_cy = tmp_cy->next;
    }
  while (tmp_c != NULL)
    {
      inter_cone(&s->c, tmp_c);
      tmp_c = tmp_c->next;
    }
  while (tmp_s != NULL)
    {
      inter_sphere(&s->c, tmp_s);
      tmp_s = tmp_s->next;
    }
  inter_plan(s, &s->c);
  calculate_k(s);
  //light(s, s->l);
  multi_light(s);
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
	  s->d.nb_spots = 0;
	  s->d.colo = COLOR_BLACK;
	  s->x.k = 10000000;
	  s->c.v.vx = 1000;
	  s->c.v.vy = (s->d.x_max / 2) - i;
	  s->c.v.vz = (s->d.y_max / 2) - j;
	  rotate(&s->c.rot, &s->c);
	  calc(s);
	  aff_pix_img(s, i, j, s->d.bigData);
	  j += 5;
	}
      j = flew2;
      i += 5;
    }
  mlx_put_image_to_window(s->d.mlx_ptr, s->d.win_ptr, s->d.img_ptr, 0, 0);
}
