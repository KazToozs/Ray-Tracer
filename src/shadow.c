/*
** shadow.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue May 12 11:16:50 2015 ugo belfiore
** Last update Thu May 21 14:43:24 2015 ugo belfiore
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

static int	shadow_k(t_st *s, t_cam *l)
{
  t_cone	*tmp_c;
  t_cyl		*tmp_cy;
  t_sph		*tmp_s;

  tmp_c = s->co;
  tmp_cy = s->cy;
  tmp_s = s->s;
  s->x.k = 10000;
  while (tmp_s != NULL)
    {
      rotate(&tmp_s->rot, &s->c);
      check_shadow(s, &tmp_s->x);
      rotate_inv(&tmp_s->rot, &s->c);
      tmp_s = tmp_s->next;
    }
  while (tmp_c != NULL)
    {
      rotate(&tmp_c->rot, &s->c);
      check_shadow(s, &tmp_c->x);
      rotate_inv(&tmp_c->rot, &s->c);
      tmp_c = tmp_c->next;
    }
  while (tmp_cy != NULL)
    {
      rotate(&tmp_cy->rot, &s->c);
      check_shadow(s, &tmp_cy->x);
      rotate_inv(&tmp_cy->rot, &s->c);
      tmp_cy = tmp_cy->next;
    }
  if (s->pl->k < s->x.k && s->pl->k > 0.000001)
    s->x.k = s->pl->k;
  if (s->x.k > 0.000001 && s->x.k < 1 && s->x.k != 10000)
    {
      my_change_color(s, 0, l);
      return (-1);
    }
  return (0);
}

int		shadow(t_st *s, t_cam *l)
{
  t_cone	*tmp_c;
  t_cyl		*tmp_cy;
  t_sph		*tmp_s;

  tmp_c = s->co;
  tmp_cy = s->cy;
  tmp_s = s->s;
  while (tmp_cy != NULL)
    {
      inter_cyl(&s->x.c, tmp_cy);
      tmp_cy = tmp_cy->next;
    }
  while (tmp_c != NULL)
    {
      inter_cone(&s->x.c, tmp_c); 
      tmp_c = tmp_c->next;
    }
  while (tmp_s != NULL)
    {
      inter_sphere(&s->x.c, tmp_s);
      tmp_s = tmp_s->next;
    }
  inter_plan(s, &s->x.c);
  if (shadow_k(s, l) == -1)
    return (-1);
  return (0);
}
