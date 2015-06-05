/*
** my_obj_pos.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Jun  5 17:25:57 2015 ugo belfiore
** Last update Fri Jun  5 17:26:27 2015 ugo belfiore
*/

#include "mini.h"

void	remp_pos(t_pos *p, t_pos base)
{
  p->x = base.x;
  p->y = base.y;
  p->z = base.z;
}

void	remp_x(t_x *x, t_x base)
{
  x->x1 = 0;
  x->x2 = 0;
  x->color = base.color;
  x->t = base.t;
  x->ref = base.ref;
}

void	remp_rot(t_rot *r, t_rot base)
{
  r->x = base.x;
  r->y = base.y;
  r->z = base.z;
}
