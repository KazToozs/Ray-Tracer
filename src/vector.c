/*
** vector.c for rt in /home/pallua_j/rendu/prog_test/MUL_2014_rtracer/src
** 
** Made by pallua_j
** Login   <pallua_j@epitech.net>
** 
** Started on  Wed May 27 10:30:09 2015 pallua_j
** Last update Wed May 27 16:28:19 2015 pallua_j
*/

#include "mini.h"

double		length(t_vect *v)
{
  return (sqrtf((v->vx * v->vx) + (v->vy * v->vy) + (v->vz * v->vz)));
}

double		dotproduct(t_vect *v1, t_vect *v2)
{
  double	result;
  double	v1l;
  double	v2l;

  v1l = length(v1);
  v2l = length(v2);
  result = 0;
  result += v1->vx * v2->vx / (v1l * v2l);
  result += v1->vy * v2->vy / (v1l * v2l);
  result += v1->vz * v2->vz / (v1l * v2l); 
  return (result);
}

void		normalized(t_vect *v)
{
  double	l;

  l = length(v);
  v->vx /= l;
  v->vy /= l;
  v->vz /= l;
}

void		my_br(t_st *s, double dot, t_vect *br)
{
  double	inl = length(&s->c.v);
  double	nl = length(&s->n);

  br->vx = s->c.v.vx / inl + (2 * dot * s->n.vx) / nl;
  br->vy = s->c.v.vy / inl + (2 * dot * s->n.vy) / nl;
  br->vz = s->c.v.vz / inl + (2 * dot * s->n.vz) / nl;
}
