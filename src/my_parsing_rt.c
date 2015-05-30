/*
** my_str_to_wordtab.c for  in /home/belfio_u/rendu/Piscine_C_J08/ex_04
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 24 19:29:19 2014 ugo belfiore
** Last update Sun May 31 00:37:27 2015 ugo belfiore
*/

#include "mini.h"

static void    debug(t_wild *w)
{
  int		t;

  t = -1;
  while (++t < 5)
    {
      (light_len(w->s[t].l) == 0) ?
	my_error(w, "ERROR: no LIGHT detected.\n", -1)
	: my_printf("INFO: there are %d LIGHT.\n", light_len(w->s[t].l));
      (plan_len(w->s[t].pl) == 0) ? my_printf("INFO: no PLAN detected.\n")
	: my_printf("INFO: there are %d PLAN.\n", plan_len(w->s[t].pl));
      (sphere_len(w->s[t].s) == 0) ? my_printf("INFO: no SPHERE detected.\n")
	: my_printf("INFO: there are %d SPHERE.\n", sphere_len(w->s[t].s));
      (cyl_len(w->s[t].cy) == 0) ? my_printf("INFO: no CYLINDER detected.\n")
	: my_printf("INFO: there are %d CYLINDER.\n", cyl_len(w->s[t].cy));
      (cone_len(w->s[t].co) == 0) ? my_printf("INFO: no CONE detected.\n")
	: my_printf("INFO: there are %d CONE.\n", cone_len(w->s[t].co));
    }
}

static int	match(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (!s1[i])
    my_error(NULL, "ERROR: empty match", -1);
  while (s2[i])
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  if (s2[i] == '\0' && s1[i] == '\0')
    return (1);
  return (0);
}

void	line_camera(t_wild *w)
{
  int	t;

  t = -1;
  while (++t < 5)
    {
      if (match(w->fi.tab[0], "CAMERA-POS"))
	{
	  if (!w->fi.tab[1] || !w->fi.tab[2] || !w->fi.tab[3])
	    my_error(w, "ERROR: argument CAMERA_POS.", -1);
	  w->s[t].c.p.x = (double)my_getnbr(w->fi.tab[1]);
	  w->s[t].c.p.y = (double)my_getnbr(w->fi.tab[2]);
	  w->s[t].c.p.z = (double)my_getnbr(w->fi.tab[3]);
	}
      if (match(w->fi.tab[0], "CAMERA-ROTATE"))
	{
	  if (!w->fi.tab[1] || !w->fi.tab[2] || !w->fi.tab[3])
	    my_error(w, "ERROR: argument CAMERA_ROTATE.", -1);
	  w->s[t].c.rot.x = my_getnbr(w->fi.tab[1]);
	  w->s[t].c.rot.y = my_getnbr(w->fi.tab[2]);
	  w->s[t].c.rot.z = my_getnbr(w->fi.tab[3]);
	}
    }
}

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
	      || !w->fi.tab[5] || !w->fi.tab[6])
	    my_error(w, "ERROR: argument PLAN.", -1);
	  remp_p.z = (double)my_getnbr(w->fi.tab[1]);
	  remp_p.color = strtol(w->fi.tab[2], &test, 16);
	  remp_p.rot.x = my_getnbr(w->fi.tab[3]);
	  remp_p.rot.y = my_getnbr(w->fi.tab[4]);
	  remp_p.rot.z = my_getnbr(w->fi.tab[5]);
	  remp_p.coef = (double)atof(w->fi.tab[6]);
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
	if (!w->fi.tab[1] || !w->fi.tab[2] || !w->fi.tab[3]
	    || !w->fi.tab[4] || !w->fi.tab[5] || !w->fi.tab[6]
	    || !w->fi.tab[7] || !w->fi.tab[8] || !w->fi.tab[9])
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
	if (!w->fi.tab[1] || !w->fi.tab[2] || !w->fi.tab[3]
	    || !w->fi.tab[4] || !w->fi.tab[5] || !w->fi.tab[6]
	    || !w->fi.tab[7] || !w->fi.tab[8] || !w->fi.tab[10])
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
	if (!w->fi.tab[1] || !w->fi.tab[2] || !w->fi.tab[3]
	    || !w->fi.tab[4] || !w->fi.tab[5] || !w->fi.tab[6]
	    || !w->fi.tab[7] || !w->fi.tab[8] || !w->fi.tab[10])
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
	w->s[t].co = my_put_cone_list(w->s[t].co, remp);
      }
}

void	test_line(t_wild *w)
{
  w->fi.tab = my_str_tab(w->fi.buff);
  line_camera(w);
  line_light(w);
  line_plan(w);
  line_sphere(w);
  line_cyl(w);
  line_cone(w);
}

void	my_parsing_rt(t_wild *w)
{
  int	t;

  t = -1;
  while (++t < 5)
    {
      w->s[t].s = NULL;
      w->s[t].co = NULL;
      w->s[t].cy = NULL;
      w->s[t].l = NULL;
      w->s[t].pl = NULL;
      w->s[t].colo = COLOR_BLACK;
      w->s[t].tt = t;
    }
  while ((w->fi.buff = get_next_line(w->fi.fd))) // parse ligne par ligne
    {
      //si la ligne ne commence pas par /, *, ' ' ou \n, on test.
      if (!(w->fi.buff[0] == '/' || w->fi.buff[0] == '*'
	    || w->fi.buff[0] == ' ' || w->fi.buff[0] == '\n'
	    || w->fi.buff[0] == '#'
	    || (w->fi.buff[0] == '\0')))
	test_line(w);
      free(w->fi.buff);          // supprime la ligne courante et next
    }
  debug(w);// debugage et affichage information du parsing
}
