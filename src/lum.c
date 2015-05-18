/*
** lum.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon May 18 14:04:11 2015 ugo belfiore
** Last update Mon May 18 14:27:42 2015 ugo belfiore
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

void            light(t_st *s)
{
  double        cosin;

  s->x.c.p.x = s->c.p.x + (s->x.k * s->c.v.vx);
  s->x.c.p.y = s->c.p.y + (s->x.k * s->c.v.vy);
  s->x.c.p.z = s->c.p.z + (s->x.k * s->c.v.vz);
  s->x.c.v.vx = s->l->p.x - s->x.c.p.x;
  s->x.c.v.vy = s->l->p.y - s->x.c.p.y;
  s->x.c.v.vz = s->l->p.z - s->x.c.p.z;
  if (shadow(s) == -1)
    return ;
  calculate_n(s);
  cosin = (((s->n.vx * s->x.c.v.vx) + (s->n.vy * s->x.c.v.vy)
            + (s->n.vz * s->x.c.v.vz))
           / sqrt((pow(s->n.vx, 2) + pow(s->n.vy, 2) + pow(s->n.vz, 2)) *
                  (pow(s->x.c.v.vx, 2) + pow(s->x.c.v.vy, 2)
                   + pow(s->x.c.v.vz, 2))));
  if (cosin < 0.000001)
    s->d.colo = COLOR_BLACK;
  else if (cosin > 0.000001)
    my_change_color(s, cosin);
}
