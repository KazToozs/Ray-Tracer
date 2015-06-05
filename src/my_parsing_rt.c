/*
** my_parsing_rt.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sun May 31 02:04:45 2015 ugo belfiore
** Last update Fri Jun  5 17:46:44 2015 ugo belfiore
*/

#include "mini.h"

static void    debug(t_wild *w)
{
  int		t;

  t = 0;
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

int		match(char *s1, char *s2)
{
  int		i;

  i = 0;
  if (!s1)
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

static void	line_camera(t_wild *w)
{
  int		t;

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
  while ((w->fi.buff = get_next_line(w->fi.fd)))
    {
      if (!(w->fi.buff[0] == '/' || w->fi.buff[0] == '*'
	    || w->fi.buff[0] == ' ' || w->fi.buff[0] == '\n'
	    || w->fi.buff[0] == '#'
	    || (w->fi.buff[0] == '\0')))
	test_line(w);
      free(w->fi.buff);
    }
  debug(w);
}
