/*
** shadow.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue May 12 11:16:50 2015 ugo belfiore
** Last update Fri Jun  5 18:04:08 2015 ugo belfiore
*/

#include "mini.h"

static void	check_shadow(t_st *s, t_x *x)
{
  if ((x->x1 < x->x2) && (x->x1 < s->x.kk) && (x->x1 > 0.000001)
      && (x->x2 < 1))
    s->x.kk = x->x1;
  else if ((x->x2 < x->x1) && (x->x2 < s->x.kk) && (x->x2 > 0.000001)
        && (x->x2 < 1))
    s->x.kk = x->x2;
}

static  void	shadow_k_obj(t_st *s, t_sph *tmp_s,
			     t_cyl *tmp_cy, t_cone *tmp_c)
{
  while (tmp_s != NULL)
    {
      check_shadow(s, &tmp_s->x);
      tmp_s = tmp_s->next;
    }
  while (tmp_cy != NULL)
    {
      check_shadow(s, &tmp_cy->x);
      tmp_cy = tmp_cy->next;
    }
  while (tmp_c != NULL)
    {
      check_shadow(s, &tmp_c->x);
      tmp_c = tmp_c->next;
    }
}

static int	shadow_k(t_st *s)
{
  t_cone	*tmp_c;
  t_cyl		*tmp_cy;
  t_sph		*tmp_s;
  t_plan	*tmp_pl;

  tmp_c = s->co;
  tmp_cy = s->cy;
  tmp_s = s->s;
  tmp_pl = s->pl;
  s->x.kk = 10000000;
  while (tmp_pl != NULL)
    {
      if (tmp_pl->k < s->x.kk && tmp_pl->k > 0.000001)
	s->x.kk = tmp_pl->k;
      tmp_pl = tmp_pl->next;
    }
  shadow_k_obj(s, tmp_s, tmp_cy, tmp_c);
  if (s->x.kk > 0.000001 && s->x.kk < 1.00000000)
    return (-1);
  return (0);
}

static void	shadow_obj(t_st *s, t_sph *tmp_s, t_cyl *tmp_cy, t_cone *tmp_c)
{
  while (tmp_s != NULL)
    {
      inter_sphere(&s->x.c, tmp_s);
      tmp_s = tmp_s->next;
    }
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
}

int		shadow(t_st *s)
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
      inter_plan(&s->x.c, tmp_pl);
      tmp_pl = tmp_pl->next;
    }
  shadow_obj(s, tmp_s, tmp_cy, tmp_c);
  if (shadow_k(s) == -1)
    return (-1);
  return (0);
}
