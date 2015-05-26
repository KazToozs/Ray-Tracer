/*
** my_change_color.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon May 18 12:07:41 2015 ugo belfiore
** Last update Tue May 26 17:18:42 2015 pallua_j
*/

#include "mini.h"

void    my_change_color(t_st *s, double cosin, t_cam *l)
{
  l->r = ((s->d.colo & 0xFF) * (1 - s->x.coef)
	  + (l->color & 0xFF) * s->x.coef) * cosin;
  if (l->r > 255)
    l->r = 255;
  l->g = (((s->d.colo >> 8) & 0xFF) * (1 - s->x.coef)
	  + ((l->color >> 8) & 0xFF) * s->x.coef) * cosin;
  if (l->g > 255)
    l->g = 255;
  l->b = (((s->d.colo >> 16) & 0xFF) * (1 - s->x.coef)
	  + ((l->color >> 16) & 0xFF) * s->x.coef) * cosin;
  if (l->b > 255)
    l->b = 255;
  l->type = 1;
  s->d.nb_spots += 1;
}

void    my_change_color_bis(t_st *s)
{
  t_cam	*tmp;
  int	r;
  int	g;
  int	b;

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
  if (r > 255)
    r = 255;
  if (g > 255)
    g = 255;
  if (b > 255)
    b = 255;
  s->d.colo = (r) + (g * 0x100) + (b * 0x10000);
}
