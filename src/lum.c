/*
** lum.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon May 18 14:04:11 2015 ugo belfiore
** Last update Thu Jun  4 17:25:29 2015 pallua_j
*/

#include "mini.h"

void	calculate_n(t_st *s)
{

  if (s->x.t == SPHERE)
    {
      rotate(&s->s->rot, &s->n, NULL, 2);
      s->n.vx = s->x.c.p.x - s->x.o.x;
      s->n.vy = s->x.c.p.y - s->x.o.y;
      s->n.vz = s->x.c.p.z - s->x.o.z;
      rotate_inv(&s->s->rot, &s->n, NULL, 2);
    }
  else if (s->x.t == PLANE)
    {
      rotate(&s->pl->rot, &s->n, NULL, 2);
      s->n.vx = 0;
      s->n.vy = 0;
      s->n.vz = 100;
      rotate_inv(&s->pl->rot, &s->n, NULL, 2);
    }
  else if (s->x.t == CYLINDER)
    {
      rotate(&s->cy->rot, &s->n, NULL, 2);
      s->n.vx = s->x.c.p.x - s->x.o.x;
      s->n.vy = s->x.c.p.y - s->x.o.y;
      s->n.vz = 0;
      rotate_inv(&s->cy->rot, &s->n, NULL, 2);
    }
  else if (s->x.t == CONE)
    {
      rotate(&s->co->rot, &s->n, NULL, 2);
      s->n.vx = s->x.c.p.x - s->x.o.x;
      s->n.vy = s->x.c.p.y - s->x.o.y;
      s->n.vz = 0 - (s->x.c.p.z - s->x.o.z);
      rotate_inv(&s->co->rot, &s->n, NULL, 2);
    }
}

void            light(t_st *s, t_cam *l)
{
  double        cosin;

  l->type = 0;
  s->x.c.v.vx = l->p.x - s->x.c.p.x;
  s->x.c.v.vy = l->p.y - s->x.c.p.y;
  s->x.c.v.vz = l->p.z - s->x.c.p.z;
  cosin = (((s->n.vx * s->x.c.v.vx) + (s->n.vy * s->x.c.v.vy)
            + (s->n.vz * s->x.c.v.vz))
           / sqrt((pow(s->n.vx, 2) + pow(s->n.vy, 2) + pow(s->n.vz, 2)) *
                  (pow(s->x.c.v.vx, 2) + pow(s->x.c.v.vy, 2)
                   + pow(s->x.c.v.vz, 2))));
  if (cosin > 0.000001)
    {
      if (shadow(s) == -1)
      	return ;
      my_change_color(s, cosin, l);
    }
}
