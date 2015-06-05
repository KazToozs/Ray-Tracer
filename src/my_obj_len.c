/*
** my_obj_len.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Jun  5 17:28:22 2015 ugo belfiore
** Last update Fri Jun  5 17:29:19 2015 ugo belfiore
*/

#include "mini.h"

int		plan_len(t_plan *list)
{
  t_plan	*tmp;
  int		x;

  x = 0;
  if (list == NULL)
    return (0);
  tmp = list;
  while (tmp != NULL)
    {
      x++;
      tmp = tmp->next;
    }
  return (x);
}

int		sphere_len(t_sph *list)
{
  t_sph		*tmp;
  int		x;

  x = 0;
  if (list == NULL)
    return (0);
  tmp = list;
  while (tmp != NULL)
    {
      x++;
      tmp = tmp->next;
    }
  return (x);
}

int		cyl_len(t_cyl *list)
{
  t_cyl		*tmp;
  int		x;

  x = 0;
  if (list == NULL)
    return (0);
  tmp = list;
  while (tmp != NULL)
    {
      x++;
      tmp = tmp->next;
    }
  return (x);
}

int		cone_len(t_cone *list)
{
  t_cone	*tmp;
  int		x;

  x = 0;
  if (list == NULL)
    return (0);
  tmp = list;
  while (tmp != NULL)
    {
      x++;
      tmp = tmp->next;
    }
  return (x);
}

int		light_len(t_cam *list)
{
  t_cam		*tmp;
  int		x;

  x = 0;
  if (list == NULL)
    return (0);
  tmp = list;
  while (tmp != NULL)
    {
      x++;
      tmp = tmp->next;
    }
  return (x);
}
