/*
** my_parsing_obj.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Jun  5 17:42:05 2015 ugo belfiore
** Last update Fri Jun  5 17:47:42 2015 ugo belfiore
*/

#include "mini.h"

void		line_light(t_wild *w)
{
  char		*test;
  t_cam		remp;
  int		t;

  t = -1;
  while (++t < 5)
    {
      if (match(w->fi.tab[0], "LIGHT"))
	{
	  if (!w->fi.tab[1] || !w->fi.tab[2] || !w->fi.tab[3] || !w->fi.tab[4])
	    my_error(w, "ERROR: argument LIGHT.", -1);
	  remp.p.x = (double)my_getnbr(w->fi.tab[1]);
	  remp.p.y = (double)my_getnbr(w->fi.tab[2]);
	  remp.p.z = (double)my_getnbr(w->fi.tab[3]);
	  remp.color = strtol(w->fi.tab[4], &test, 16);
	  w->s[t].l = my_put_light_list(w->s[t].l, remp);
	}
    }
}

void		line_plan(t_wild *w)
{
  char		*test;
  t_plan	remp_p;
  int		t;

  t = -1;
  while (++t < 5)
    {
      if (match(w->fi.tab[0], "PLAN"))
	{
	  if (!w->fi.tab[1] || !w->fi.tab[2] || !w->fi.tab[3] || !w->fi.tab[4]
	      || !w->fi.tab[5] || !w->fi.tab[6] || !w->fi.tab[7])
	    my_error(w, "ERROR: argument PLAN.", -1);
	  remp_p.z = (double)my_getnbr(w->fi.tab[1]);
	  remp_p.color = strtol(w->fi.tab[2], &test, 16);
	  remp_p.rot.x = my_getnbr(w->fi.tab[3]);
	  remp_p.rot.y = my_getnbr(w->fi.tab[4]);
	  remp_p.rot.z = my_getnbr(w->fi.tab[5]);
	  remp_p.coef = (double)atof(w->fi.tab[6]);
	  remp_p.ref = (double)atof(w->fi.tab[7]);
	  w->s[t].pl = my_put_plan_list(w->s[t].pl, remp_p);
	}
    }
}

void		line_sphere(t_wild *w)
{
  char		*test;
  t_sph		remp;
  int		t;

  t = -1;
  if (match(w->fi.tab[0], "SPHERE"))
    while (++t < 5)
      {
	if (WORD_1 || WORD_2 || !w->fi.tab[9] || !w->fi.tab[10])
	  my_error(w, "ERROR: argument SPHERE.", -1);
	remp.p.x = (double)my_getnbr(w->fi.tab[1]);
	remp.p.y = (double)my_getnbr(w->fi.tab[2]);
	remp.p.z = (double)my_getnbr(w->fi.tab[3]);
	remp.r = (double)my_getnbr(w->fi.tab[4]);
	remp.x.color = strtol(w->fi.tab[5], &test, 16);
	remp.x.t = SPHERE;
	remp.rot.x = my_getnbr(w->fi.tab[6]);
	remp.rot.y = my_getnbr(w->fi.tab[7]);
	remp.rot.z = my_getnbr(w->fi.tab[8]);
	remp.x.coef = atof(w->fi.tab[9]);
	remp.x.ref = atof(w->fi.tab[10]);
	w->s[t].s = my_put_sph_list(w->s[t].s, remp);
      }
}

void	line_cyl(t_wild *w)
{
  char	*test;
  t_cyl	remp;
  int	t;

  t = -1;
  if (match(w->fi.tab[0], "CYLINDER"))
    while (++t < 5)
      {
	if (WORD_1 || WORD_2 || !w->fi.tab[10] || !w->fi.tab[11])
	  my_error(w, "ERROR: argument CYLINDER.", -1);
	remp.p.x = (double)my_getnbr(w->fi.tab[1]);
	remp.p.y = (double)my_getnbr(w->fi.tab[2]);
	remp.p.z = (double)my_getnbr(w->fi.tab[3]);
	remp.r = (double)my_getnbr(w->fi.tab[4]);
	remp.x.color = strtol(w->fi.tab[5], &test, 16);
	remp.x.t = CYLINDER;
	remp.rot.x = my_getnbr(w->fi.tab[6]);
	remp.rot.y = my_getnbr(w->fi.tab[7]);
	remp.rot.z = my_getnbr(w->fi.tab[8]);
	remp.high = my_getnbr(w->fi.tab[9]);
	remp.x.coef = (double)atof(w->fi.tab[10]);
	remp.x.ref = (double)atof(w->fi.tab[11]);
	w->s[t].cy = my_put_cyl_list(w->s[t].cy, remp);
      }
}

void		line_cone(t_wild *w)
{
  char		*test;
  t_cone	remp;
  int		t;

  t = -1;
  if (match(w->fi.tab[0], "CONE"))
    while (++t < 5)
      {
	if (WORD_1 || WORD_2 || !w->fi.tab[10])
	  my_error(w, "ERROR: argument CONE.", -1);
	remp.p.x = (double)my_getnbr(w->fi.tab[1]);
	remp.p.y = (double)my_getnbr(w->fi.tab[2]);
	remp.p.z = (double)my_getnbr(w->fi.tab[3]);
	remp.r = (double)my_getnbr(w->fi.tab[4]);
	remp.x.color = strtol(w->fi.tab[5], &test, 16);
	remp.x.t = CONE;
	remp.rot.x = my_getnbr(w->fi.tab[6]);
	remp.rot.y = my_getnbr(w->fi.tab[7]);
	remp.rot.z = my_getnbr(w->fi.tab[8]);
	remp.high = my_getnbr(w->fi.tab[9]);
	remp.x.coef = (double)atof(w->fi.tab[10]);
	remp.x.ref = (double)atof(w->fi.tab[11]);
	w->s[t].co = my_put_cone_list(w->s[t].co, remp);
      }
}
