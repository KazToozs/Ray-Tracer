/*
** calculate_k.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/sources
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Sun Mar  8 20:24:43 2015 cristopher toozs-hobson
** Last update Wed Mar 18 17:18:03 2015 cristopher toozs-hobson
*/

#include "rt.h"

void		check(t_st *s, t_x *x)
{
  if (x->x1 > 0.0000001 && x->x1 < s->x.k &&
      (x->x1 < x->x2 || x->x2 < 0.0000001))
    {
      s->x.t = x->t;
      s->x.k = x->x1;
      s->d.red = x->red;
      s->d.green = x->green;
      s->d.blue = x->blue;
    }
  else if (x->x2 > 0.0000001 && x->x2 < s->x.k &&
	   (x->x2 < x->x1 || x->x1 < 0.0000001))
    {
      s->x.t = x->t;
      s->x.k = x->x2;
      s->d.red = x->red;
      s->d.green = x->green;
      s->d.blue = x->blue;
    }
}

void		check_plane(t_st *s)
{
  if (s->pl.k > 0.0000001 && s->pl.k < s->x.k)
    {
      s->x.t = PLANE;
      s->x.k = s->pl.k;
      s->d.red = s->pl.red;
      s->d.green = s->pl.green;
      s->d.blue = s->pl.blue;
    }
}

void		check_shadow(t_st *s, t_x *x)
{
  if ((x->x1 < x->x2) && (x->x1 < s->x.k) && (x->x1 > 0.000001)
      && (x->x2 < 1) /* je crois que ça devrait être x->x1 < 1 ici */)
    s->x.k = x->x1;
  else if ((x->x2 < x->x1) && (x->x2 < s->x.k) && (x->x2 > 0.000001)
  	   && (x->x2 < 1) /* comme ceci */)
    s->x.k = x->x2;
}

void		calculate_k(t_st *s)
{
  check(s, &s->s.x);
  check(s, &s->co.x);
  check(s, &s->cy.x);
  check_plane(s);
}

int		shadow_k(t_st *s)
{
  /*
  ** On set une variable k pour le point d'intersection, comme on a fait pour
  ** avant pour la camera
  */
  s->x.k = 10000;

  /*
  ** On prend le k le plus petit non négatif, tant qu'il est entre 0 et 1
  ** (enfin je crois, c'était un peu du bricodage à partir de là)
  */ 

  check_shadow(s, &s->s.x);// check sphère
  check_shadow(s, &s->co.x);// check cone
  check_shadow(s, &s->cy.x);// check cylindre
  if (s->pl.k < s->x.k && s->pl.k > 0.000001)
    s->x.k = s->pl.k; // check plan

  // Si 0 < k < 1 on met l'ombre
  if (s->x.k > 0.000001 && s->x.k < 1 && s->x.k != 10000 /* euh...? */)
    {
      // set à noir
      s->d.red = 0;
      s->d.green = 0;
      s->d.blue = 0;
      // je semble avoir implémenté les retours pour rien, à ignorer
      return (1);
    }
  return (0);
}
