/*
** translations.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/sources
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu Mar  5 10:22:14 2015 cristopher toozs-hobson
** Last update Tue Mar 10 16:29:57 2015 cristopher toozs-hobson
*/

#include "rt.h"

void		inverse_translation(t_pos *p, int x, int y, int z)
{
  p->x += x;
  p->y += y;
  p->z += z;
}

void		translation(t_pos *p, int x, int y, int z)
{
  p->x -= x;
  p->y -= y;
  p->z -= z;
}
