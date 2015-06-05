/*
** my_change_color.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon May 18 12:07:41 2015 ugo belfiore
** Last update Fri Jun  5 17:54:20 2015 pallua_j
*/

#include "mini.h"

double		my_spec(t_st *s)
{
  t_vect	br;
  double	my_dot;
  double	my_spec;

  my_dot = -dotproduct(&s->c.v, &s->n);
  my_br(s, my_dot, &br);
  my_spec = dotproduct(&br, &s->x.c.v);
  if (my_spec < 0)
    my_spec = 0;
  if (s->x.coef == 0)
    return (0);
  my_spec = pow(my_spec, s->x.coef);
  return (my_spec);
}

void		my_change_color(t_st *s, double cosin, t_cam *l)
{
  double	ob;
  double	li;
  double	spec;

  ob = ((double)(s->colo & 0xFF)) / 255.f;
  li = ((double)(l->color & 0xFF)) / 255.f;
  spec = my_spec(s);
  l->r = 255 * ((ob * li * cosin + (li * spec)));
  ob = ((double)((s->colo >> 8) & 0xFF)) / 255.f;
  li = ((double)((l->color >> 8) & 0xFF)) / 255.f;
  l->g = 255 * (ob * li *  cosin + (li * spec));
  ob = ((double)((s->colo >> 16) & 0xFF)) / 255.f;
  li = ((double)((l->color >> 16) & 0xFF)) / 255.f;
  l->b = 255 * (ob * li * cosin + (li * spec));
  l->type = 1;
  s->nb_spots += 1;
}

int		my_change_color_bis(t_st *s)
{
  t_cam		*tmp;
  int		c[3];

  tmp = s->l;
  c[0] = 0;
  c[1] = 0;
  c[2] = 0;
  while (tmp != NULL)
    {
      if (tmp->type == 1)
	{
	  c[0] += tmp->r;
	  c[1] += tmp->g;
	  c[2] += tmp->b;
	}
      tmp = tmp->next;
    }
  if (c[0] > 255)
    c[0] = 255;
  if (c[1] > 255)
    c[1] = 255;
  if (c[2] > 255)
    c[2] = 255;
  return ((c[0]) + (c[1] * 0x100) + (c[2] * 0x10000));
}
