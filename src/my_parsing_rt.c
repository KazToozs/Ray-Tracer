/*
** my_str_to_wordtab.c for  in /home/belfio_u/rendu/Piscine_C_J08/ex_04
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 24 19:29:19 2014 ugo belfiore
** Last update Sun May 17 01:51:00 2015 ugo belfiore
*/

#include "mini.h"

static void    debug(t_st *s)
{
/*   // debugage de fin */
/*   if (d->o.view.check == 0) */
/*     my_error(d, "ERROR: can't find CAMERA_POS.", -1); */
/*   if (d->o.view.check2 == 0) */
/*     my_error(d, "ERROR: can't find CAMERA_ROTATE.", -1); */
/*   (d->o.lum.check == 0) ? my_error(d, "ERROR: no LIGHT detected.\n", -1) */
/*     : my_printf("INFO: there are %d LIGHT.\n", d->o.lum.check); */
/*   (d->o.pl.check == 0) ? my_printf("INFO: no PLAN detected.\n") */
/*     : my_printf("INFO: there are %d PLAN.\n", d->o.pl.check); */
/*   (d->o.sph.check == 0) ? my_printf("INFO: no SPHERE detected.\n") */
/*     : my_printf("INFO: there are %d SPHERE.\n", d->o.sph.check); */
/*   (d->o.cy.check == 0) ? my_printf("INFO: no CYLINDER detected.\n") */
/*     : my_printf("INFO: there are %d CYLINDER.\n", d->o.cy.check); */
/*   (d->o.co.check == 0) ? my_printf("INFO: no CONE detected.\n") */
/*     : my_printf("INFO: there are %d CONE.\n", d->o.co.check); */
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
      //s->o.view.check++;
      /* if (d->o.view.check >= 2) */
      /* 	my_error(d, "ERROR: too many CAMERA_POS.", -1); */
      if (!s->fi.tab[1] || !s->fi.tab[2] || !s->fi.tab[3])
	my_error(s, "ERROR: argument CAMERA_POS.", -1);
      //d->o.view.x_eyes = my_getnbr(d->fi.tab[1]);
      //d->o.view.y_eyes = my_getnbr(d->fi.tab[2]);
      //d->o.view.z_eyes = my_getnbr(d->fi.tab[3]);
    }
  if (match(s->fi.tab[0], "CAMERA_ROTATE:"))
    {
      //d->o.view.check2++;
      /* if (d->o.view.check2 >= 2) */
      /* 	my_error(d, "ERROR: too many CAMERA_ROTATE.", -1); */
      if (!s->fi.tab[1] || !s->fi.tab[2] || !s->fi.tab[3])
	my_error(s, "ERROR: argument CAMERA_ROTATE.", -1);
      //d->o.view.rotangx = my_getnbr(d->fi.tab[1]);
      //d->o.view.rotangy = my_getnbr(d->fi.tab[2]);
      //d->o.view.rotangz = my_getnbr(d->fi.tab[3]);
    }
}

void	line_light_plan(t_st *s)
{
  char	*test;

  if (match(s->fi.tab[0], "LIGHT_&:"))
    {
      //d->o.lum.check++;
      /* if (d->o.lum.check > 255) // nombre de lumière maximum. */
      /* 	my_error(d, "ERROR: too many LIGHT.", -1); */
      if (!s->fi.tab[1] || !s->fi.tab[2] || !s->fi.tab[3])
	my_error(s, "ERROR: argument LIGHT.", -1);
      //d->o.lum.x_lum[d->o.lum.check - 1] = (double)my_getnbr(d->fi.tab[1]);
      //d->o.lum.y_lum[d->o.lum.check - 1] = (double)my_getnbr(d->fi.tab[2]);
      //d->o.lum.z_lum[d->o.lum.check - 1] = (double)my_getnbr(d->fi.tab[3]);
    }
  if (match(s->fi.tab[0], "PLAN_&:"))
    {
      //d->o.pl.check++;
      /* if (d->o.pl.check > 255) // nombre de plan maximum. */
      /* 	my_error(d, "ERROR: too many PLAN.", -1); */
      if (!s->fi.tab[1] || !s->fi.tab[2])
	my_error(s, "ERROR: argument PLAN.", -1);
      //d->o.pl.high[d->o.pl.check - 1] = my_getnbr(d->fi.tab[1]);
      //d->o.pl.color_plan[d->o.pl.check - 1] = strtol(d->fi.tab[2], &test, 16);
    }
}

void	line_sphere(t_st *s)
{
  char	*test;

  if (match(s->fi.tab[0], "SPHERE_&:"))
    {
      //d->o.sph.check++;
      /* if (d->o.sph.check > 255) // nombre de sphere maximum. */
      /* 	my_error(d, "ERROR: too many SPHERE.", -1); */
      if (!s->fi.tab[1] || !s->fi.tab[2] || !s->fi.tab[3]
	  || !s->fi.tab[4] || !s->fi.tab[5] || !s->fi.tab[6]
	  || !s->fi.tab[7] || !s->fi.tab[8])
	my_error(s, "ERROR: argument SPHERE.", -1);
      //d->o.sph.x_sphere[d->o.sph.check - 1] = my_getnbr(d->fi.tab[1]);
      //d->o.sph.y_sphere[d->o.sph.check - 1] = my_getnbr(d->fi.tab[2]);
      //d->o.sph.z_sphere[d->o.sph.check - 1] = my_getnbr(d->fi.tab[3]);
      //d->o.sph.r_sh[d->o.sph.check - 1] = my_getnbr(d->fi.tab[4]);
      /* d->o.sph.color_sphere[d->o.sph.check - 1] = */
      /* 	strtol(d->fi.tab[5], &test, 16); */
      //d->o.sph.rotx[d->o.sph.check - 1] = (double)my_getnbr(d->fi.tab[6]);
      //d->o.sph.roty[d->o.sph.check - 1] = (double)my_getnbr(d->fi.tab[7]);
      //d->o.sph.rotz[d->o.sph.check - 1] = (double)my_getnbr(d->fi.tab[8]);
    }
}

void	line_cyl(t_st *s)
{
  char	*test;

  if (match(s->fi.tab[0], "CYLINDER_&:"))
    {
      //d->o.cy.check++;
      /* if (d->o.cy.check > 255) // nombre de cylindre maximum. */
      /* 	my_error(d, "ERROR: too many CYLINDER.", -1); */
      if (!s->fi.tab[1] || !s->fi.tab[2] || !s->fi.tab[3]
	  || !s->fi.tab[4] || !s->fi.tab[5] || !s->fi.tab[6]
	  || !s->fi.tab[7] || !s->fi.tab[8] || !s->fi.tab[9])
	my_error(s, "ERROR: argument CYLINDER.", -1);
      //d->o.cy.x_cyl[d->o.cy.check - 1] = my_getnbr(d->fi.tab[1]);
      //d->o.cy.y_cyl[d->o.cy.check - 1] = my_getnbr(d->fi.tab[2]);
      //d->o.cy.z_cyl[d->o.cy.check - 1] = my_getnbr(d->fi.tab[3]);
      //d->o.cy.r_cyl[d->o.cy.check - 1] = my_getnbr(d->fi.tab[4]);
      /* d->o.cy.color_cyl[d->o.cy.check - 1] = */
      /* 	strtol(d->fi.tab[5], &test, 16); */
      //d->o.cy.rotx[d->o.cy.check - 1] = (double)my_getnbr(d->fi.tab[6]);
      //d->o.cy.roty[d->o.cy.check - 1] = (double)my_getnbr(d->fi.tab[7]);
      //d->o.cy.rotz[d->o.cy.check - 1] = (double)my_getnbr(d->fi.tab[8]);
      //d->o.cy.high[d->o.cy.check - 1] = my_getnbr(d->fi.tab[9]);
    }
}

void	line_cone(t_st *s)
{
  char	*test;

  if (match(s->fi.tab[0], "CONE_&:"))
    {
      //d->o.co.check++;
      /* if (d->o.co.check > 255) // nombre de cone maximum. */
      /* 	my_error(d, "ERROR: too many CONE.", -1); */
      if (!s->fi.tab[1] || !s->fi.tab[2] || !s->fi.tab[3]
	  || !s->fi.tab[4] || !s->fi.tab[5] || !s->fi.tab[6]
	  || !s->fi.tab[7] || !s->fi.tab[8] || !s->fi.tab[9])
	my_error(s, "ERROR: argument CONE.", -1);
      //d->o.co.x_cone[d->o.co.check - 1] = my_getnbr(d->fi.tab[1]);
      //d->o.co.y_cone[d->o.co.check - 1] = my_getnbr(d->fi.tab[2]);
      //d->o.co.z_cone[d->o.co.check - 1] = my_getnbr(d->fi.tab[3]);
      //d->o.co.r_cone[d->o.co.check - 1] = my_getnbr(d->fi.tab[4]);
      /* d->o.co.color_cone[d->o.co.check - 1] = */
      /* 	strtol(d->fi.tab[5], &test, 16); */
      //d->o.co.rotx[d->o.co.check - 1] = (double)my_getnbr(d->fi.tab[6]);
      //d->o.co.roty[d->o.co.check - 1] = (double)my_getnbr(d->fi.tab[7]);
      //d->o.co.rotz[d->o.co.check - 1] = (double)my_getnbr(d->fi.tab[8]);
      //d->o.co.high[d->o.co.check - 1] = my_getnbr(d->fi.tab[9]);
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
  /* d->o.view.check = 0;	//init vue_pos */
  /* d->o.view.check2 = 0;	//init vue_rotate */
  /* d->o.lum.check = 0;	// init nombre de lumiere */
  /* d->o.pl.check = 0;	// init plan */
  /* d->o.sph.check = 0;	//init sphere */
  /* d->o.cy.check = 0;	//init cyl */
  /* d->o.co.check = 0;	//init cone */
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
