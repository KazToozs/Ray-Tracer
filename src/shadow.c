/*
** shadow.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue May 12 11:16:50 2015 ugo belfiore
** Last update Mon May 18 14:30:21 2015 ugo belfiore
*/

#include "mini.h"

static void	check_shadow(t_st *s, t_x *x)
{
  if ((x->x1 < x->x2) && (x->x1 < s->x.k) && (x->x1 > 0.000001)
      && (x->x2 < 1))
    s->x.k = x->x1;
  else if ((x->x2 < x->x1) && (x->x2 < s->x.k) && (x->x2 > 0.000001)
        && (x->x2 < 1))
    s->x.k = x->x2;
}

static int	shadow_k(t_st *s)
{
  s->x.k = 10000;
  check_shadow(s, &s->s->x);
  check_shadow(s, &s->co->x);
  check_shadow(s, &s->cy->x);
  if (s->pl->k < s->x.k && s->pl->k > 0.000001)
    s->x.k = s->pl->k;
  if (s->x.k > 0.000001 && s->x.k < 1 &&  s->x.k != 10000)
    {
      s->d.colo = COLOR_BLACK;
      return (-1);
    }
  return (0);
}

int	shadow(t_st *s)
{
  inter_cyl(&s->x.c, s->cy);
  inter_cone(&s->x.c, s->co);
  inter_sphere(&s->x.c, s->s);
  inter_plan(s, &s->x.c);
  if (shadow_k(s) == -1)
    return (-1);
  return (0);
}
