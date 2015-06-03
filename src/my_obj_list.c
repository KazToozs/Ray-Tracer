/*
** my_obj_list.c for rt in /home/pallua_j/rendu/miniblix/MUL_2014_rtracer/src
** 
** Made by jules palluau
** Login   <pallua_j@epitech.net>
** 
** Started on  Sun May 17 01:54:41 2015 jules palluau
** Last update Tue Jun  2 13:21:47 2015 pallua_j
*/

#include "mini.h"

void		remp_pos(t_pos *p, t_pos base)
{
  p->x = base.x;
  p->y = base.y;
  p->z = base.z;
}

void		remp_x(t_x *x, t_x base)
{
  x->x1 = 0;
  x->x2 = 0;
  x->color = base.color;
  x->t = base.t;
  x->ref = base.ref;
}

void		remp_rot(t_rot *r, t_rot base)
{
  r->x = base.x;
  r->y = base.y;
  r->z = base.z;
}

t_sph		*my_put_sph_list(t_sph *list, t_sph remp)
{
  t_sph		*tmp;
  t_sph		*elem;

  if ((elem = malloc(sizeof(t_sph))) == NULL)
    aff_error("Can't perform malloc!\n");
  elem->prev = NULL;
  elem->next = NULL;
  remp_pos(&elem->p, remp.p);
  remp_x(&elem->x, remp.x);
  remp_rot(&elem->rot, remp.rot);
  elem->r = remp.r;
  elem->x.coef = remp.x.coef;
  if (list == NULL)
    return (elem);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  elem->prev = tmp;
  return(list);
}

t_cone		*my_put_cone_list(t_cone *list, t_cone remp)
{
  t_cone	*tmp;
  t_cone	*elem;

  if ((elem = malloc(sizeof(t_cone))) == NULL)
    aff_error("Can't perform malloc!\n");
  elem->prev = NULL;
  elem->next = NULL;
  remp_pos(&elem->p, remp.p);
  remp_x(&elem->x, remp.x);
  remp_rot(&elem->rot, remp.rot);
  elem->r = remp.r;
  elem->high = remp.high;
  elem->x.coef = remp.x.coef;
  if (list == NULL)
    return (elem);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  elem->prev = tmp;
  return(list);
}

t_cyl		*my_put_cyl_list(t_cyl *list, t_cyl remp)
{
  t_cyl		*tmp;
  t_cyl		*elem;

  if ((elem = malloc(sizeof(t_cone))) == NULL)
    aff_error("Can't perform malloc!\n");
  elem->prev = NULL;
  elem->next = NULL;
  remp_pos(&elem->p, remp.p);
  remp_x(&elem->x, remp.x);
  remp_rot(&elem->rot, remp.rot);
  elem->r = remp.r;
  elem->high = remp.high;
  elem->x.coef = remp.x.coef;
  if (list == NULL)
    return (elem);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  elem->prev = tmp;
  return(list);
}

t_cam		*my_put_light_list(t_cam *list, t_cam remp)
{
  t_cam		*tmp;
  t_cam		*elem;
  static int	nb = 1;

  if ((elem = malloc(sizeof(t_cam))) == NULL)
    aff_error("Can't perform malloc!\n");
  elem->prev = NULL;
  elem->next = NULL;
  elem->nbr = nb++;
  remp_pos(&elem->p, remp.p);
  elem->color = remp.color;
  if (list == NULL)
    return (elem);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  elem->prev = tmp;
  return(list);
}

t_plan		*my_put_plan_list(t_plan *list, t_plan remp)
{
  t_plan       	*tmp;
  t_plan       	*elem;

  if ((elem = malloc(sizeof(t_plan))) == NULL)
    aff_error("Can't perform malloc!\n");
  elem->prev = NULL;
  elem->next = NULL;
  elem->z = remp.z;
  elem->color = remp.color;
  remp_rot(&elem->rot, remp.rot);
  elem->coef = remp.coef;
  elem->ref = remp.ref;
  if (list == NULL)
    return (elem);
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = elem;
  elem->prev = tmp;
  return(list);
}

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
  t_cone       	*tmp;
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
