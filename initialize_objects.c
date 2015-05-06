/*
** initialize_objects.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/sources
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Mar 10 15:22:07 2015 cristopher toozs-hobson
** Last update Wed Mar 11 11:57:13 2015 cristopher toozs-hobson
*/

#include "rt.h"

void		init_sphere(t_st *s)
{
  s->s.p.x = 0;
  s->s.p.y = 0;
  s->s.p.z = 0;
  s->s.r = 500;
  s->s.x.red = 255;
  s->s.x.green = 255;
  s->s.x.blue = 0;
}

void		init_plan(t_st *s)
{
  s->pl.z = 0;
  s->pl.red = 196;
  s->pl.green = 196;
  s->pl.blue = 196;
}

void		init_cone(t_st *s)
{
  s->co.p.x = 0;
  s->co.p.y = -900;
  s->co.p.z = 0;
  s->co.r = 500;
  s->co.x.red = 255;
  s->co.x.green = 0;
  s->co.x.blue = 255;
  s->co.rot.x = 0;
  s->co.rot.y = 0;
  s->co.rot.z = 0;
}

void		init_cyl(t_st *s)
{
  s->cy.p.x = -300;
  s->cy.p.y = 750;
  s->cy.p.z = 0;
  s->cy.r = 200;
  s->cy.x.red = 51;
  s->cy.x.green = 255;
  s->cy.x.blue = 0;
  s->cy.rot.x = 0;
  s->cy.rot.y = 0;
  s->cy.rot.z = 0;
}
