/*
** calculate_k.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/sources
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Sun Mar  8 20:24:43 2015 cristopher toozs-hobson
** Last update Fri May 29 12:34:10 2015 ugo belfiore
*/

#include "mini.h"

static void	check(t_st *s, t_x *x)
{
  if (x->x1 > 0.0000001 && x->x1 < s->x.k &&
      (x->x1 < x->x2 || x->x2 < 0.0000001))
    {
      s->x.t = x->t;
      s->x.k = x->x1;
      s->x.coef = x->coef;
      s->d.colo = x->color;
    }
  else if (x->x2 > 0.0000001 && x->x2 < s->x.k &&
	   (x->x2 < x->x1 || x->x1 < 0.0000001))
    {
      s->x.t = x->t;
      s->x.k = x->x2;
      s->x.coef = x->coef;
      s->d.colo = x->color;
    }
}

static void	check_plane(t_st *s, t_plan *pl)
{
  if (pl->k > 0.0000001 && pl->k < s->x.k)
    {
      s->x.t = PLANE;
      s->x.k = pl->k;
      s->x.coef = pl->coef;
      s->d.colo = pl->color;
    }
}

void		calculate_k(t_st *s)
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
      check_plane(s, tmp_pl);
      rotate_inv(&tmp_pl->rot, &s->c);
      tmp_pl = tmp_pl->next;
    }
  while (tmp_s != NULL)
    {
      rotate(&tmp_s->rot, &s->c);
      check(s, &tmp_s->x);
      rotate_inv(&tmp_s->rot, &s->c);
      tmp_s = tmp_s->next;
    }
  while (tmp_cy != NULL)
    {
      rotate(&tmp_cy->rot, &s->c);
      check(s, &tmp_cy->x);
      rotate_inv(&tmp_cy->rot, &s->c);
      tmp_cy = tmp_cy->next;
    }
  while (tmp_c != NULL)
    {
      rotate(&tmp_c->rot, &s->c);
      check(s, &tmp_c->x);
      rotate_inv(&tmp_c->rot, &s->c);
      tmp_c = tmp_c->next;
    }
}
