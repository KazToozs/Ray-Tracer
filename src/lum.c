/*
** lum.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon May 18 14:04:11 2015 ugo belfiore
** Last update Fri May 29 12:39:34 2015 ugo belfiore
*/

#include "mini.h"

static void	calculate_n(t_st *s)
{
  if (s->x.t == SPHERE)
    {
      s->n.vx = s->x.c.p.x;
      s->n.vy = s->x.c.p.y;
      s->n.vz = s->x.c.p.z;
    }
  else if (s->x.t == PLANE)
    {
      s->n.vx = 0;
      s->n.vy = 0;
      s->n.vz = 100;
    }
  else if (s->x.t == CYLINDER)
    {
      s->n.vx = s->x.c.p.x;
      s->n.vy = s->x.c.p.y;
      s->n.vz = 0;
    }
  else if (s->x.t == CONE)
    {
      s->n.vx = s->x.c.p.x;
      s->n.vy = s->x.c.p.y;
      s->n.vz = (-1000) * s->x.c.p.z;
    }
}

void            light(t_st *s, t_cam *l)
{
  double        cosin;

  l->type = 0;
  s->x.c.p.x = s->c.p.x + (s->x.k * s->c.v.vx);
  s->x.c.p.y = s->c.p.y + (s->x.k * s->c.v.vy);
  s->x.c.p.z = s->c.p.z + (s->x.k * s->c.v.vz);
  s->x.c.v.vx = l->p.x - s->x.c.p.x;
  s->x.c.v.vy = l->p.y - s->x.c.p.y;
  s->x.c.v.vz = l->p.z - s->x.c.p.z;
  calculate_n(s);
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
