/*
** calculate_k.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/sources
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Sun Mar  8 20:24:43 2015 cristopher toozs-hobson
** Last update Tue May 26 17:10:30 2015 pallua_j
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

static void	check_plane(t_st *s)
{
  if (s->pl->k > 0.0000001 && s->pl->k < s->x.k)
    {
      s->x.t = PLANE;
      s->x.k = s->pl->k;
      s->x.coef = s->pl->coef;
      s->d.colo = s->pl->color;
    }
}

void		calculate_k(t_st *s)
{
  t_cone	*tmp_c;
  t_cyl		*tmp_cy;
  t_sph		*tmp_s;

  tmp_c = s->co;
  tmp_cy = s->cy;
  tmp_s = s->s;
  while (tmp_s != NULL)
    {
      check(s, &tmp_s->x);
      tmp_s = tmp_s->next;
    }
  while (tmp_c != NULL)
    {
      check(s, &tmp_c->x);
      tmp_c = tmp_c->next;
    }
  while (tmp_cy != NULL)
    {
      check(s, &tmp_cy->x);
      tmp_cy = tmp_cy->next;
    }
  if (s->pl != NULL)
    check_plane(s);
}
