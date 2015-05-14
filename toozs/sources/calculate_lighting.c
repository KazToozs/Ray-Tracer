/*
** calculate_lighting.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/sources
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Mar 10 15:25:08 2015 cristopher toozs-hobson
** Last update Wed May 13 19:13:34 2015 ugo belfiore
*/

#include <math.h>
#include "rt.h"

void		calculate_n(t_st *s)
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

int		shadow(t_st *s)
{
  inter_cyl(&s->x.c, &s->cy);
  inter_cone(&s->x.c, &s->co);
  inter_sphere(&s->x.c, &s->s);
  inter_plan(s, &s->x.c);
  if (shadow_k(s) == -1)
    return (-1);
  return (0);
}

void		light_calculations(t_st *s)
{
  s->x.c.p.x = s->c.p.x + (s->x.k * s->c.v.vx);
  s->x.c.p.y = s->c.p.y + (s->x.k * s->c.v.vy);
  s->x.c.p.z = s->c.p.z + (s->x.k * s->c.v.vz);
  s->x.c.v.vx = s->l.p.x - s->x.c.p.x;
  s->x.c.v.vy = s->l.p.y - s->x.c.p.y;
  s->x.c.v.vz = s->l.p.z - s->x.c.p.z;
}

void		light(t_st *s)
{
  double	cosin;

  light_calculations(s);
  if (shadow(s) == -1)
    return ;
  calculate_n(s);
  cosin = (((s->n.vx * s->x.c.v.vx) + (s->n.vy * s->x.c.v.vy)
            + (s->n.vz * s->x.c.v.vz))
           / sqrt((pow(s->n.vx, 2) + pow(s->n.vy, 2) + pow(s->n.vz, 2)) *
                  (pow(s->x.c.v.vx, 2) + pow(s->x.c.v.vy, 2)
                   + pow(s->x.c.v.vz, 2))));
  if (cosin < 0.000001)
    {
      s->d.red = 0;
      s->d.green = 0;
      s->d.blue = 0;
    }
  else if (cosin > 0.000001)
    {
      s->d.red = s->d.red * cosin;
      s->d.green = s->d.green * cosin;
      s->d.blue = s->d.blue * cosin;
    }
}
