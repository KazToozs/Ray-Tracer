/*
** my_change_color.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon May 18 12:07:41 2015 ugo belfiore
** Last update Mon May 18 14:25:43 2015 ugo belfiore
*/

#include "mini.h"

void    my_change_color(t_st *s, double cosin)
{
  int   R;
  int   G;
  int   B;

  R = cosin * (s->d.colo & 0xFF);
  if (R > 255)
    R = 255;
  G = cosin * ((s->d.colo >> 8) & 0xFF);
  if (G > 255)
    G = 255;
  B = cosin * ((s->d.colo >> 16) & 0xFF);
  if (B > 255)
    B = 255;
  s->d.colo = (R) + (G * 0x100) + (B * 0x10000);
}
