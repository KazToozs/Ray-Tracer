/*
** aff_all.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu May 21 14:16:28 2015 ugo belfiore
** Last update Thu May 21 14:38:34 2015 ugo belfiore
*/

#include "mini.h"
#define CLEARSCREEN "clear"

void	aff_all(t_st *s)
{
  t_cone        *tmp_c;
  t_cyl         *tmp_cy;
  t_sph         *tmp_s;
  t_cam         *tmp_l;

  tmp_c = s->co;
  tmp_cy = s->cy;
  tmp_s = s->s;
  tmp_l = s->l;
  system(CLEARSCREEN);
  while (tmp_cy != NULL)
    {
      printf("cyl x: %f\n", tmp_cy->p.x);
      printf("cyl y: %f\n", tmp_cy->p.y);
      printf("cyl z: %f\n\n", tmp_cy->p.z);
      tmp_cy = tmp_cy->next;
    }
  while (tmp_c != NULL)
    {
      printf("cone x: %f\n", tmp_c->p.x);
      printf("cone y: %f\n", tmp_c->p.y);
      printf("cone z: %f\n\n", tmp_c->p.z);
      tmp_c = tmp_c->next;
    }
  while (tmp_s != NULL)
    {
      printf("sphere x: %f\n", tmp_s->p.x);
      printf("sphere y: %f\n", tmp_s->p.y);
      printf("sphere z: %f\n\n", tmp_s->p.z);
      tmp_s = tmp_s->next;
    }
  while (tmp_l != NULL)
    {
      printf("lum x: %f\n", tmp_l->p.x);
      printf("lum y: %f\n", tmp_l->p.y);
      printf("lum z: %f\n\n", tmp_l->p.z);
      tmp_l = tmp_l->next;
    }
}
