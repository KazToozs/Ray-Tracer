/*
** my_str_to_wordtab.c for  in /home/belfio_u/rendu/Piscine_C_J08/ex_04
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 24 19:29:19 2014 ugo belfiore
** Last update Mon May 18 12:03:55 2015 ugo belfiore
*/

#include "mini.h"

static void    debug(t_st *s)
{
/*   // debugage de fin */
/*   if (d->o.view.check == 0) */
/*     my_error(d, "ERROR: can't find CAMERA_POS.", -1); */
/*   if (d->o.view.check2 == 0) */
/*     my_error(d, "ERROR: can't find CAMERA_ROTATE.", -1); */
  (light_len(s->l) == 0) ? my_error(s, "ERROR: no LIGHT detected.\n", -1)
    : my_printf("INFO: there are %d LIGHT.\n", light_len(s->l));
  (plan_len(s->pl) == 0) ? my_printf("INFO: no PLAN detected.\n")
    : my_printf("INFO: there are %d PLAN.\n", plan_len(s->pl));
  (sphere_len(s->s) == 0) ? my_printf("INFO: no SPHERE detected.\n")
    : my_printf("INFO: there are %d SPHERE.\n", sphere_len(s->s));
  (cyl_len(s->cy) == 0) ? my_printf("INFO: no CYLINDER detected.\n")
    : my_printf("INFO: there are %d CYLINDER.\n", cyl_len(s->cy));
  (cone_len(s->co) == 0) ? my_printf("INFO: no CONE detected.\n")
    : my_printf("INFO: there are %d CONE.\n", cone_len(s->co));
/*   // affichage des variables (pour verifier si ça marche) */
/*   int   i; */

/*   i = -1; */
/*   printf("cam: %d %d %d\n", d->o.view.x_eyes, d->o.view.y_eyes, */
/*   	 d->o.view.z_eyes); */
/*   printf("rotate: %f %f %f\n", d->o.view.rotangx, */
/*   	 d->o.view.rotangy,d->o.view.rotangz); */
/*   while (++i < d->o.lum.check) */
/*     printf("lum(%d):%f %f %f\n", i, */
/*   	   d->o.lum.x_lum[i], d->o.lum.y_lum[i], d->o.lum.z_lum[i]); */
/*   i = -1; */
/*   while (++i < d->o.pl.check) */
/*     printf("plan(%d): %d %x\n", i, */
/*   	   d->o.pl.high[i], d->o.pl.color_plan[i]); */
/*   i = -1; */
/*   while (++i < d->o.sph.check) */
/*     printf("sph(%d):%d %d %d %d %x %f %f %f\n", i, d->o.sph.x_sphere[i], */
/*            d->o.sph.y_sphere[i], d->o.sph.z_sphere[i], d->o.sph.r_sh[i], */
/*            d->o.sph.color_sphere[i], d->o.sph.rotx[i], d->o.sph.roty[i], */
/*            d->o.sph.rotz[i]); */
/*   i = -1; */
/*   while (++i < d->o.cy.check) */
/*     printf("cyl(%d):%d %d %d %d %x %f %f %f %d\n", i, d->o.cy.x_cyl[i], */
/*            d->o.cy.y_cyl[i], d->o.cy.z_cyl[i], d->o.cy.r_cyl[i], */
/*            d->o.cy.color_cyl[i], d->o.cy.rotx[i], d->o.cy.roty[i], */
/*            d->o.cy.rotz[i], d->o.cy.high[i]); */
/*   i = -1; */
/*   while (++i < d->o.co.check) */
/*     printf("cone(%d):%d %d %d %d %x %f %f %f %d\n", i, d->o.co.x_cone[i], */
/*            d->o.co.y_cone[i], d->o.co.z_cone[i], d->o.co.r_cone[i], */
/*            d->o.co.color_cone[i], d->o.co.rotx[i], d->o.co.roty[i], */
/*            d->o.co.rotz[i], d->o.co.high[i]); */
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
	if (s2[i] != '&')
	  return (0);
      i++;
    }
  if (s2[i] == '\0' && s1[i] == '\0')
    return (1);
  return (0);
}

void	line_camera(t_st *s)
{
  if (match(s->fi.tab[0], "CAMERA_POS:"))
    {
      if (!s->fi.tab[1] || !s->fi.tab[2] || !s->fi.tab[3])
	my_error(s, "ERROR: argument CAMERA_POS.", -1);
      s->c.p.x = (double)my_getnbr(s->fi.tab[1]);
      s->c.p.y = (double)my_getnbr(s->fi.tab[2]);
      s->c.p.z = (double)my_getnbr(s->fi.tab[3]);
    }
  if (match(s->fi.tab[0], "CAMERA_ROTATE:"))
    {
      if (!s->fi.tab[1] || !s->fi.tab[2] || !s->fi.tab[3])
	my_error(s, "ERROR: argument CAMERA_ROTATE.", -1);
      s->c.rot.x = my_getnbr(s->fi.tab[1]);
      s->c.rot.y = my_getnbr(s->fi.tab[2]);
      s->c.rot.z = my_getnbr(s->fi.tab[3]);
    }
}

void	line_light_plan(t_st *s)
{
  char	*test;

  if (match(s->fi.tab[0], "LIGHT_&:"))
    {
      if (!s->fi.tab[1] || !s->fi.tab[2] || !s->fi.tab[3])
	my_error(s, "ERROR: argument LIGHT.", -1);
      s->l = my_put_light_list(s->l, my_getnbr(s->fi.tab[1]),
			       my_getnbr(s->fi.tab[2]),
			       my_getnbr(s->fi.tab[3]));
    }
  if (match(s->fi.tab[0], "PLAN_&:"))
    {
      if (!s->fi.tab[1] || !s->fi.tab[2])
	my_error(s, "ERROR: argument PLAN.", -1);
      s->pl = my_put_plan_list(s->pl, my_getnbr(s->fi.tab[1]),
			       strtol(s->fi.tab[2], &test, 16));
    }
}

void		line_sphere(t_st *s)
{
  char		*test;
  t_sph		remp;

  if (match(s->fi.tab[0], "SPHERE_&:"))
    {
      if (!s->fi.tab[1] || !s->fi.tab[2] || !s->fi.tab[3]
	  || !s->fi.tab[4] || !s->fi.tab[5] || !s->fi.tab[6]
	  || !s->fi.tab[7] || !s->fi.tab[8])
	my_error(s, "ERROR: argument SPHERE.", -1);
      remp.p.x = (double)my_getnbr(s->fi.tab[1]);
      remp.p.y = (double)my_getnbr(s->fi.tab[2]);
      remp.p.z = (double)my_getnbr(s->fi.tab[3]);
      remp.r = (double)my_getnbr(s->fi.tab[4]);
      remp.x.color = strtol(s->fi.tab[5], &test, 16);
      remp.x.t = SPHERE;
      remp.rot.x = my_getnbr(s->fi.tab[6]);
      remp.rot.y = my_getnbr(s->fi.tab[7]);
      remp.rot.z = my_getnbr(s->fi.tab[8]);
      s->s = my_put_sph_list(s->s, remp);
    }
}

void	line_cyl(t_st *s)
{
  char	*test;
  t_cyl	remp;

  if (match(s->fi.tab[0], "CYLINDER_&:"))
    {
      if (!s->fi.tab[1] || !s->fi.tab[2] || !s->fi.tab[3]
	  || !s->fi.tab[4] || !s->fi.tab[5] || !s->fi.tab[6]
	  || !s->fi.tab[7] || !s->fi.tab[8] || !s->fi.tab[9])
	my_error(s, "ERROR: argument CYLINDER.", -1);
      remp.p.x = (double)my_getnbr(s->fi.tab[1]);
      remp.p.y = (double)my_getnbr(s->fi.tab[2]);
      remp.p.z = (double)my_getnbr(s->fi.tab[3]);
      remp.r = (double)my_getnbr(s->fi.tab[4]);
      remp.x.color = strtol(s->fi.tab[5], &test, 16);
      remp.x.t = CYLINDER;
      remp.rot.x = my_getnbr(s->fi.tab[6]);
      remp.rot.y = my_getnbr(s->fi.tab[7]);
      remp.rot.z = my_getnbr(s->fi.tab[8]);
      remp.high = my_getnbr(s->fi.tab[9]);
      s->cy = my_put_cyl_list(s->cy, remp);
    }
}

void		line_cone(t_st *s)
{
  char		*test;
  t_cone	remp;

  if (match(s->fi.tab[0], "CONE_&:"))
    {
      if (!s->fi.tab[1] || !s->fi.tab[2] || !s->fi.tab[3]
	  || !s->fi.tab[4] || !s->fi.tab[5] || !s->fi.tab[6]
	  || !s->fi.tab[7] || !s->fi.tab[8] || !s->fi.tab[9])
	my_error(s, "ERROR: argument CONE.", -1);
      remp.p.x = (double)my_getnbr(s->fi.tab[1]);
      remp.p.y = (double)my_getnbr(s->fi.tab[2]);
      remp.p.z = (double)my_getnbr(s->fi.tab[3]);
      remp.r = (double)my_getnbr(s->fi.tab[4]);
      remp.x.color = strtol(s->fi.tab[5], &test, 16);
      remp.x.t = CONE;
      remp.rot.x = my_getnbr(s->fi.tab[6]);
      remp.rot.y = my_getnbr(s->fi.tab[7]);
      remp.rot.z = my_getnbr(s->fi.tab[8]);
      remp.high = my_getnbr(s->fi.tab[9]);
      s->co = my_put_cone_list(s->co, remp);
    }
}

void	test_line(t_st *s)
{
  s->fi.tab = my_str_to_wordtab_rt(s->fi.buff);
  line_camera(s);
  line_light_plan(s);
  line_sphere(s);
  line_cyl(s);
  line_cone(s);
}

void	my_parsing_rt(t_st *s)
{
  s->s = NULL;
  s->co = NULL;
  s->cy = NULL;
  s->l = NULL;
  s->pl = NULL;
  while ((s->fi.buff = get_next_line(s->fi.fd))) // parse ligne par ligne
    {
      //si la ligne ne commence pas par /, *, ' ' ou \n, on test.
      if (!(s->fi.buff[0] == '/' || s->fi.buff[0] == '*'
	    || s->fi.buff[0] == ' ' || s->fi.buff[0] == '\n'
	    || (!s->fi.buff[0])))
	test_line(s);
      free(s->fi.buff);          // supprime la ligne courante et next
    }
  debug(s);// debugage et affichage information du parsing
}
