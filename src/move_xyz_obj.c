/*
** move_xyz_obj.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Jun  5 14:44:08 2015 ugo belfiore
** Last update Fri Jun  5 15:06:15 2015 ugo belfiore
*/

#include "mini.h"

void	move_plan(t_st *s, int wich, int value)
{
  t_plan	*tmp_pl;

  tmp_pl = s->pl;
  while (tmp_pl != NULL)
    {
      if (wich == 1)
	tmp_pl->rot.x += value;
      else if (wich == 2)
	tmp_pl->rot.y += value;
      else
	tmp_pl->rot.z += value;
      tmp_pl = tmp_pl->next;
    }
}

void	move_xyz_obj(t_st *s, int keycode, int tabi)
{
  if (tabi == 1)
    {
      (keycode == KEY_A) ? move_plan(s, 1, 5) : 1;
      (keycode == KEY_E) ? move_plan(s, 1, -5) : 1;
      (keycode == KEY_S) ? move_plan(s, 2, 5) : 1;
      (keycode == KEY_Z) ? move_plan(s, 2, -5) : 1;
      (keycode == KEY_Q) ? move_plan(s, 3, 5) : 1;
      (keycode == KEY_D) ? move_plan(s, 3, -5) : 1;
    }
  /* else if (tabi == 2) */
  /*   { */
  /*   } */
  /* else if (tabi == 3) */
  /*   { */

  /*   } */
  /* else */
  /*   { */

  /*   } */
}
