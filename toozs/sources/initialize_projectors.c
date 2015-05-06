/*
** initialize_projectors.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/sources
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Mar 10 15:23:35 2015 cristopher toozs-hobson
** Last update Wed Mar 11 11:53:23 2015 cristopher toozs-hobson
*/

#include "rt.h"

void		init_cam(t_st *s)
{
  s->c.p.x = -1500;
  s->c.p.y = 000;
  s->c.p.z = 200;
  s->c.rot.x = 0;
  s->c.rot.y = 0;
  s->c.rot.z = 0;
}

void		init_lit(t_st *s)
{
  s->l.p.x = -1500;
  s->l.p.y = 0;
  s->l.p.z = 500;
}
