/*
** calculate_k.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/sources
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Sun Mar  8 20:24:43 2015 cristopher toozs-hobson
** Last update Fri Jun  5 17:08:38 2015 ugo belfiore
*/

#include "mini.h"

static void	check_x2(t_st *s, t_x *x)
{
  s->x.t = x->t;
  s->x.k = x->x2;
  s->x.coef = x->coef;
  s->colo = x->color;
  s->x.o.p.x = x->p.x;
  s->x.o.p.y = x->p.y;
  s->x.o.p.z = x->p.z;
  s->x.o.rot.x = x->rot.x;
  s->x.o.rot.y = x->rot.y;
  s->x.o.rot.z = x->rot.z;
  s->x.ref = x->ref;
}

static void	check(t_st *s, t_x *x)
{
  if (x->x1 > 0.0000001 && x->x1 < s->x.k &&
      (x->x1 < x->x2 || x->x2 < 0.0000001))
    {
      s->x.t = x->t;
      s->x.k = x->x1;
      s->x.coef = x->coef;
      s->x.ref = x->ref;
      s->colo = x->color;
      s->x.o.p.x = x->p.x;
      s->x.o.p.y = x->p.y;
      s->x.o.p.z = x->p.z;
      s->x.o.rot.x = x->rot.x;
      s->x.o.rot.y = x->rot.y;
      s->x.o.rot.z = x->rot.z;
    }
  else if (x->x2 > 0.0000001 && x->x2 < s->x.k &&
	   (x->x2 < x->x1 || x->x1 < 0.0000001))
    check_x2(s, x);
}

static void	check_plane(t_st *s, t_plan *pl)
{
  if (pl->k > 0.0000001 && pl->k < s->x.k)
    {
      s->x.t = PLANE;
      s->x.k = pl->k;
      s->x.o.rot.x = pl->rot.x;
      s->x.o.rot.y = pl->rot.y;
      s->x.o.rot.z = pl->rot.z;
      s->x.ref = pl->ref;
      s->x.coef = pl->coef;
      s->colo = pl->color;
    }
}

static void	calculate_k_obj(t_st *s, t_sph *tmp_s,
				t_cyl *tmp_cy, t_cone *tmp_c)
{
  while (tmp_s != NULL)
    {
      check(s, &tmp_s->x);
      tmp_s = tmp_s->next;
    }
  while (tmp_cy != NULL)
    {
      check(s, &tmp_cy->x);
      tmp_cy = tmp_cy->next;
    }
  while (tmp_c != NULL)
    {
      check(s, &tmp_c->x);
      tmp_c = tmp_c->next;
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
      check_plane(s, tmp_pl);
      tmp_pl = tmp_pl->next;
    }
  calculate_k_obj(s, tmp_s, tmp_cy, tmp_c);
}
