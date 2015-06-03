/*
** my_change_color.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon May 18 12:07:41 2015 ugo belfiore
** Last update Wed Jun  3 09:43:39 2015 pallua_j
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
  int		r;
  int		g;
  int		b;
  double	ref;

  tmp = s->l;
  r = 0;
  g = 0;
  b = 0;
  while (tmp != NULL)
    {
      if (tmp->type == 1)
	{
	  r += tmp->r;
	  g += tmp->g;
	  b += tmp->b;
	}
      tmp = tmp->next;
    }
  ref = ((double)(s->color_ref & 0xFF)) / 255.f;
  r *= (1 - s->x.ref) + (s->x.ref * (ref));
  ref = ((double)((s->color_ref >> 8) & 0xFF)) / 255.f;
  g *= (1 - s->x.ref) + (s->x.ref * (ref));
  ref = ((double)((s->color_ref >> 16) & 0xFF)) / 255.f;
  b *= (1 - s->x.ref) + (s->x.ref * (ref));
  if (r > 255)
    r = 255;
  if (g > 255)
    g = 255;
  if (b > 255)
    b = 255;
  return ((r) + (g * 0x100) + (b * 0x10000));
}
