/*
** algo_rt.c for  in /home/belfio_u/rendu/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sun Feb  8 16:18:36 2015 ugo belfiore
** Last update Thu Jun  4 11:46:51 2015 msa_m
*/

#include "mini.h"

/*
** fonction qui permet de calculer les intersections
** entre chaque objet
*/

int		multi_light(t_st *s)
{
  t_cam		*tmp_l;
  int		colo;

  s->x.c.p.x = s->c.p.x + (s->x.k * s->c.v.vx);
  s->x.c.p.y = s->c.p.y + (s->x.k * s->c.v.vy);
  s->x.c.p.z = s->c.p.z + (s->x.k * s->c.v.vz);
  calculate_n(s);
  //  reflected(s);
  tmp_l = s->l;
  while (tmp_l != NULL)
    {
      light(s, tmp_l);
      tmp_l = tmp_l->next;
    }
  if (s->nb_spots != 0)
    colo = my_change_color_bis(s);
  else
    colo = COLOR_BLACK;
  tmp_l = s->l;
  return (colo);
}

int	calc(t_st *s)
{
  t_cone	*tmp_c;
  t_cyl		*tmp_cy;
  t_sph		*tmp_s;
  t_plan	*tmp_pl;
  int		colo;

  tmp_c = s->co;
  tmp_cy = s->cy;
  tmp_s = s->s;
  tmp_pl = s->pl;
  while (tmp_pl != NULL)
    {
      rotate(&tmp_pl->rot, &s->c.v, &s->c.p, 3);
      inter_plan(&s->c, tmp_pl);
      rotate_inv(&tmp_pl->rot, &s->c.v, &s->c.p, 3);
      tmp_pl = tmp_pl->next;
    }
  while (tmp_s != NULL)
    {
      /* rotate(&tmp_s->rot, &s->c); */
      inter_sphere(&s->c, tmp_s);
      /* rotate_inv(&tmp_s->rot, &s->c); */
      tmp_s = tmp_s->next;
    }
  while (tmp_cy != NULL)
    {
      /* rotate(&tmp_cy->rot, &s->c); */
      inter_cyl(&s->c, tmp_cy);
      /* rotate_inv(&tmp_cy->rot, &s->c); */
      tmp_cy = tmp_cy->next;
    }
  while (tmp_c != NULL)
    {
      /* rotate(&tmp_c->rot, &s->c); */
      inter_cone(&s->c, tmp_c);
      /* rotate_inv(&tmp_c->rot, &s->c); */
      tmp_c = tmp_c->next;
    }
  calculate_k(s);
  colo = multi_light(s);
  return (colo);
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
	  s->ref = 0;
	  s->nb_spots = 0;
	  s->colo = COLOR_BLACK;
	  s->x.k = 10000000;
	  s->c.v.vx = 1000;
	  s->c.v.vy = (w->d.x_max / 2) - i;
	  s->c.v.vz = (w->d.y_max / 2) - j;
	  rotate(&s->c.rot, &s->c.v, &s->c.p, 2);
	  s->colo = calc(s);
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
