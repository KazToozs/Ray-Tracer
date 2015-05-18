/*
** calculate_k.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/sources
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Sun Mar  8 20:24:43 2015 cristopher toozs-hobson
** Last update Mon May 18 14:10:54 2015 ugo belfiore
*/

#include "mini.h"

static void	check(t_st *s, t_x *x)
{
  if (x->x1 > 0.0000001 && x->x1 < s->x.k &&
      (x->x1 < x->x2 || x->x2 < 0.0000001))
    {
      s->x.t = x->t;
      s->x.k = x->x1;
      s->d.colo = x->color;
    }
  else if (x->x2 > 0.0000001 && x->x2 < s->x.k &&
	   (x->x2 < x->x1 || x->x1 < 0.0000001))
    {
      s->x.t = x->t;
      s->x.k = x->x2;
      s->d.colo = x->color;
    }
}

static void	check_plane(t_st *s)
{
  if (s->pl->k > 0.0000001 && s->pl->k < s->x.k)
    {
      s->x.t = PLANE;
      s->x.k = s->pl->k;
      s->d.colo = s->pl->color;
    }
}

void		calculate_k(t_st *s)
{
  check(s, &s->s->x);
  check(s, &s->co->x);
  check(s, &s->cy->x);
  check_plane(s);
}
