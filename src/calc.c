/*
** calc.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Jun  5 16:43:55 2015 ugo belfiore
** Last update Fri Jun  5 16:49:25 2015 ugo belfiore
*/

#include "mini.h"

/*
** fonction qui permet de calculer les intersections
** entre chaque objet
*/

static int	multi_light(t_st *s)
{
  t_cam		*tmp_l;
  int		colo;

  s->x.c.p.x = s->c.p.x + (s->x.k * s->c.v.vx);
  s->x.c.p.y = s->c.p.y + (s->x.k * s->c.v.vy);
  s->x.c.p.z = s->c.p.z + (s->x.k * s->c.v.vz);
  calculate_n(s);
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

static void	calc_obj(t_st *s, t_sph *tmp_s, t_cyl *tmp_cy, t_cone *tmp_c)
{
  while (tmp_s != NULL)
    {
      inter_sphere(&s->c, tmp_s);
      tmp_s = tmp_s->next;
    }
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
}

int		calc(t_st *s)
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
      inter_plan(&s->c, tmp_pl);
      tmp_pl = tmp_pl->next;
    }
  calc_obj(s, tmp_s, tmp_cy, tmp_c);
  calculate_k(s);
  colo = multi_light(s);
  return (colo);
}
