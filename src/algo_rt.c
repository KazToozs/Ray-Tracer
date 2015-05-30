/*
** algo_rt.c for  in /home/belfio_u/rendu/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sun Feb  8 16:18:36 2015 ugo belfiore
** Last update Sun May 31 01:25:30 2015 ugo belfiore
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
  if (s->nb_spots != 0)
    my_change_color_bis(s);
  else
    s->colo = COLOR_BLACK;
  tmp_l = s->l;
}

static void	calc(t_st *s)
{
  t_cone	*tmp_c;
  t_cyl		*tmp_cy;
  t_sph		*tmp_s;
  t_plan	*tmp_pl;

  tmp_c = s->co;
  tmp_cy = s->cy;
  tmp_s = s->s;
  tmp_pl = s->pl;
  while (tmp_pl != NULL)
    {
      rotate(&tmp_pl->rot, &s->c);
      inter_plan(&s->c, tmp_pl);
      rotate_inv(&tmp_pl->rot, &s->c);
      tmp_pl = tmp_pl->next;
    }
  while (tmp_s != NULL)
    {
      rotate(&tmp_s->rot, &s->c);
      inter_sphere(&s->c, tmp_s);
      rotate_inv(&tmp_s->rot, &s->c);
      tmp_s = tmp_s->next;
    }
  while (tmp_cy != NULL)
    {
      rotate(&tmp_cy->rot, &s->c);
      inter_cyl(&s->c, tmp_cy);
      rotate_inv(&tmp_cy->rot, &s->c);
      tmp_cy = tmp_cy->next;
    }
  while (tmp_c != NULL)
    {
      rotate(&tmp_c->rot, &s->c);
      inter_cone(&s->c, tmp_c);
      rotate_inv(&tmp_c->rot, &s->c);
      tmp_c = tmp_c->next;
    }
  calculate_k(s);
  multi_light(s);
}

/*
** algo principal du rt, qui va boucler sur chaque pixel
** (ou plutot tout les 5 pixel, avec un system qui permet d'afficher
** petit à petit la scène
*/

void	algo_rt(t_wild *w, t_st *s, int flew, int flew2)
{
  int	i;
  int	j;

  i = flew;
  j = flew2;
  while (i < w->d.x_max)
    {
      while (j < w->d.y_max)
	{
	  s->nb_spots = 0;
	  s->colo = COLOR_BLACK;
	  s->x.k = 10000000;
	  s->c.v.vx = 1000;
	  s->c.v.vy = (w->d.x_max / 2) - i;
	  s->c.v.vz = (w->d.y_max / 2) - j;
	  rotate(&s->c.rot, &s->c);
	  calc(s);
	  (s->tt == 0) ? aff_pix_img_zero(w, i, j, w->d.bigData) : 1;
	  (s->tt == 1) ? aff_pix_img_one(w, i, j, w->d.bigData) : 1;
	  (s->tt == 2) ? aff_pix_img_two(w, i, j, w->d.bigData) : 1;
	  (s->tt == 3) ? aff_pix_img_tree(w, i, j, w->d.bigData) : 1;
	  (s->tt == 4) ? aff_pix_img_four(w, i, j, w->d.bigData) : 1;
	  j += 9;
	}
      j = flew2;
      i += 9;
    }
}
