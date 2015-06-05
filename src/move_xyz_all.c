/*
** move_xyz_all.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon May  4 12:45:16 2015 ugo belfiore
** Last update Fri Jun  5 17:22:47 2015 ugo belfiore
*/

#include "mini.h"

static void	move_bis(t_cam *tmp, int which, int value)
{
  if (which == 5)
    {
      while (tmp != NULL)
	{
	  tmp->p.y += value;
	  tmp = tmp->next;
	}
    }
  if (which == 6)
    {
      while (tmp != NULL)
	{
	  tmp->p.z += value;
	  tmp = tmp->next;
	}
    }
}

void	move_xyz_all(t_wild *w, int which, int value)
{
  t_cam	*tmp;
  int	t;

  t = -1;
  while (++t < 5)
    {
      tmp = w->s[t].l;
      if (which == 1)
	w->s[t].c.p.x += value;
      if (which == 2)
	w->s[t].c.p.y += value;
      if (which == 3)
	w->s[t].c.p.z += value;
      if (which == 4)
	{
	  while (tmp != NULL)
	    {
	      tmp->p.x += value;
	      tmp = tmp->next;
	    }
	}
      move_bis(tmp, which, value);
    }
}
