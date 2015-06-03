/*
** reflection.c for rt in /home/pallua_j/rendu/igraph/MUL_2014_rtracer/src
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Tue Jun  2 11:33:35 2015 pallua_j
** Last update Tue Jun  2 11:59:18 2015 pallua_j
*/

#include "mini.h"

void		reflected(t_st *s)
{
  t_pos		c;
  t_vect	v;
  t_vect	ref;
  double	my_dot;

  if (s->ref > 4)
    return ;
  s->ref += 1;
  c.x = s->c.p.x;
  c.y = s->c.p.y;
  c.z = s->c.p.z;
  v.vx = s->c.v.vx;
  v.vy = s->c.v.vy;
  v.vz = s->c.v.vz;
  my_dot = -dotproduct(&s->c.v, &s->n);
  my_br(s, my_dot, &ref);
  s->c.v.vx = ref.vx;
  s->c.v.vy = ref.vy;
  s->c.v.vz = ref.vz;
  s->c.p.x = s->x.c.p.x;
  s->c.p.y = s->x.c.p.y;
  s->c.p.z = s->x.c.p.z;
  s->color_ref = calc(s);
  s->c.v.vx = v.vx;
  s->c.v.vy = v.vy;
  s->c.v.vz = v.vz;
  s->c.p.x = c.x;
  s->c.p.y = c.y;
  s->c.p.z = c.z;
}
