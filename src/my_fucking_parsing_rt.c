/*
** my_str_to_wordtab.c for  in /home/belfio_u/rendu/Piscine_C_J08/ex_04
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 24 19:29:19 2014 ugo belfiore
** Last update Tue Mar 17 17:24:17 2015 ugo belfiore
*/

#include "../include/my.h"
#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"

int	match(char *s1, char *s2)
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

void	test_line(t_data *d, int line)
{
  char *test;
  d->fi.tab = my_str_to_wordtab_rt(d->fi.buff);
  if (line == 0)
    {
      if ((!d->fi.tab[0]) || (!match(d->fi.tab[0], "CAMERA_POS:")))
	my_error(d, "ERROR: missing CAMERA_POS: in file.", -1);
      d->o.view.x_eyes = my_getnbr(d->fi.tab[1]);
      d->o.view.y_eyes = my_getnbr(d->fi.tab[2]);
      d->o.view.z_eyes = my_getnbr(d->fi.tab[3]);
      printf("cam: %d %d %d\n", d->o.view.x_eyes, d->o.view.y_eyes, d->o.view.z_eyes);
    }
  if (line == 1)
    {
      if (!match(d->fi.tab[0], "CAMERA_ROTATE:"))
	my_error(d, "ERROR: missing CAMERA_ROTATE: in file.", -1);
      d->o.view.rotangx = my_getnbr(d->fi.tab[1]);
      d->o.view.rotangy = my_getnbr(d->fi.tab[2]);
      d->o.view.rotangz = my_getnbr(d->fi.tab[3]);
      printf("rotate: %f %f %f\n", d->o.view.rotangx, d->o.view.rotangy,d->o.view.rotangz);
    }
  if (line == 2)
    {
      if (d->o.lum.nb_lum == 0 && (!match(d->fi.tab[0], "LIGHT_&:")))
	my_error(d, "ERROR: missing LIGHT_&: in file.", -1);
      d->o.lum.x_lum[d->o.lum.nb_lum] = (double)my_getnbr(d->fi.tab[1]);
      d->o.lum.y_lum[d->o.lum.nb_lum] = (double)my_getnbr(d->fi.tab[2]);
      d->o.lum.z_lum[d->o.lum.nb_lum] = (double)my_getnbr(d->fi.tab[3]);
      printf("lum(%d):%f %f %f\n", d->o.lum.nb_lum, d->o.lum.x_lum[d->o.lum.nb_lum], d->o.lum.y_lum[d->o.lum.nb_lum], d->o.lum.z_lum[d->o.lum.nb_lum]);
      d->o.lum.nb_lum++;
    }
  if (line == 3)
    {
      if (!match(d->fi.tab[0], "PLAN:"))
	{
	  if (match(d->fi.tab[0], "LIGHT_&:"))
	    {
	      if (d->o.lum.nb_lum >= 8)
		my_error(d, "ERROR: too many light !", -1);
	      d->o.lum.x_lum[d->o.lum.nb_lum] = (double)my_getnbr(d->fi.tab[1]);
	      d->o.lum.y_lum[d->o.lum.nb_lum] = (double)my_getnbr(d->fi.tab[2]);
	      d->o.lum.z_lum[d->o.lum.nb_lum] = (double)my_getnbr(d->fi.tab[3]);
	      printf("lum(%d):%f %f %f\n", d->o.lum.nb_lum, d->o.lum.x_lum[d->o.lum.nb_lum], d->o.lum.y_lum[d->o.lum.nb_lum], d->o.lum.z_lum[d->o.lum.nb_lum]);
	      d->o.lum.nb_lum++;
	      d->o.lum.debug = 1;
	    }
	  else
	    line++;// pas de plan
	}
      else
	{
	  d->o.pl.high = my_getnbr(d->fi.tab[1]);
	  d->o.pl.color_plan = strtol(d->fi.tab[2], &test, 16);
	  d->o.pl.nb_plan++;
	  printf("plan: %d %x\n", d->o.pl.high, d->o.pl.color_plan);
	}
    }
  if (line == 4)
    {
      if (d->o.sph.nb_sph == 0 && (!match(d->fi.tab[0], "SPHERE_&:")))
	line++;
      else
	{
	  d->o.sph.x_sphere[d->o.sph.nb_sph] =
	    d->o.view.x_eyes + my_getnbr(d->fi.tab[1]);
	  d->o.sph.y_sphere[d->o.sph.nb_sph] =
	    d->o.view.y_eyes + my_getnbr(d->fi.tab[2]);
	  d->o.sph.z_sphere[d->o.sph.nb_sph] =
	    d->o.view.z_eyes + my_getnbr(d->fi.tab[3]);
	  d->o.sph.r_sh[d->o.sph.nb_sph] = my_getnbr(d->fi.tab[4]);
	  d->o.sph.color_sphere[d->o.sph.nb_sph] =
	    strtol(d->fi.tab[5], &test, 16);
	  d->o.sph.rotx[d->o.sph.nb_sph] = (double)my_getnbr(d->fi.tab[6]);
	  d->o.sph.roty[d->o.sph.nb_sph] = (double)my_getnbr(d->fi.tab[7]);
	  d->o.sph.rotz[d->o.sph.nb_sph] = (double)my_getnbr(d->fi.tab[8]);
	  printf("sph(%d):%d %d %d %d %x %f %f %f\n", d->o.sph.nb_sph,
		 d->o.sph.x_sphere[d->o.sph.nb_sph],
		 d->o.sph.y_sphere[d->o.sph.nb_sph],
		 d->o.sph.z_sphere[d->o.sph.nb_sph],
		 d->o.sph.r_sh[d->o.sph.nb_sph],
		 d->o.sph.color_sphere[d->o.sph.nb_sph],
		 d->o.sph.rotx[d->o.sph.nb_sph],
		 d->o.sph.roty[d->o.sph.nb_sph],
		 d->o.sph.rotz[d->o.sph.nb_sph]);
	  d->o.sph.nb_sph++;
	}
    }
  if (line == 5)
    {
      if (!match(d->fi.tab[0], "CYLINDER_&:"))
	{
	  if (match(d->fi.tab[0], "SPHERE_&:"))
	    {
	      if (d->o.sph.nb_sph >= 8)
                my_error(d, "ERROR: too many sphere !", -1);
	      d->o.sph.x_sphere[d->o.sph.nb_sph] =
		d->o.view.x_eyes + my_getnbr(d->fi.tab[1]);
	      d->o.sph.y_sphere[d->o.sph.nb_sph] =
		d->o.view.y_eyes + my_getnbr(d->fi.tab[2]);
	      d->o.sph.z_sphere[d->o.sph.nb_sph] =
		d->o.view.z_eyes + my_getnbr(d->fi.tab[3]);
	      d->o.sph.r_sh[d->o.sph.nb_sph] = my_getnbr(d->fi.tab[4]);
	      d->o.sph.color_sphere[d->o.sph.nb_sph] =
		strtol(d->fi.tab[5], &test, 16);
	      d->o.sph.rotx[d->o.sph.nb_sph] = (double)my_getnbr(d->fi.tab[6]);
	      d->o.sph.roty[d->o.sph.nb_sph] = (double)my_getnbr(d->fi.tab[7]);
	      d->o.sph.rotz[d->o.sph.nb_sph] = (double)my_getnbr(d->fi.tab[8]);
	      printf("sph(%d):%d %d %d %d %x %f %f %f\n", d->o.sph.nb_sph,
		     d->o.sph.x_sphere[d->o.sph.nb_sph],
		     d->o.sph.y_sphere[d->o.sph.nb_sph],
		     d->o.sph.z_sphere[d->o.sph.nb_sph],
		     d->o.sph.r_sh[d->o.sph.nb_sph],
		     d->o.sph.color_sphere[d->o.sph.nb_sph],
		     d->o.sph.rotx[d->o.sph.nb_sph],
		     d->o.sph.roty[d->o.sph.nb_sph],
		     d->o.sph.rotz[d->o.sph.nb_sph]);
	      d->o.sph.nb_sph++;
	      d->o.sph.debug = 1;
	    }
	  else
	    line++;
	}
      else
	{
	  //premier cylindre ?
	  if (d->o.cy.nb_cyl == 0 && (!match(d->fi.tab[0], "CYLINDER_&:")))
	    line++; // pas de cylindre, ouf passons au cone !
	  else
	    {
	      d->o.cy.x_cyl[d->o.cy.nb_cyl] =
		d->o.view.x_eyes + my_getnbr(d->fi.tab[1]);
	      d->o.cy.y_cyl[d->o.cy.nb_cyl] =
		d->o.view.y_eyes + my_getnbr(d->fi.tab[2]);
	      d->o.cy.z_cyl[d->o.cy.nb_cyl] =
		d->o.view.z_eyes + my_getnbr(d->fi.tab[3]);
	      d->o.cy.r_cyl[d->o.cy.nb_cyl] = my_getnbr(d->fi.tab[4]);
	      d->o.cy.color_cyl[d->o.cy.nb_cyl] =
		strtol(d->fi.tab[5], &test, 16);
	      d->o.cy.rotx[d->o.cy.nb_cyl] = (double)my_getnbr(d->fi.tab[6]);
	      d->o.cy.roty[d->o.cy.nb_cyl] = (double)my_getnbr(d->fi.tab[7]);
	      d->o.cy.rotz[d->o.cy.nb_cyl] = (double)my_getnbr(d->fi.tab[8]);
	      d->o.cy.high[d->o.cy.nb_cyl] = my_getnbr(d->fi.tab[9]);
	      printf("cyl(%d):%d %d %d %d %x %f %f %f %d\n", d->o.cy.nb_cyl,
		     d->o.cy.x_cyl[d->o.cy.nb_cyl],
		     d->o.cy.y_cyl[d->o.cy.nb_cyl],
		     d->o.cy.z_cyl[d->o.cy.nb_cyl],
		     d->o.cy.r_cyl[d->o.cy.nb_cyl],
		     d->o.cy.color_cyl[d->o.cy.nb_cyl],
		     d->o.cy.rotx[d->o.cy.nb_cyl],
		     d->o.cy.roty[d->o.cy.nb_cyl],
		     d->o.cy.rotz[d->o.cy.nb_cyl],
		     d->o.cy.high[d->o.cy.nb_cyl]);
	      d->o.cy.nb_cyl++;
	    }
	}
    }
  if (line == 6)
    {
      // cylindre en boucle, else et apres premeir cone.
    }
  /* if (d->o.sph.nb_sph >= 8) */
  /*   my_error(d, "ERROR: too many sphere !", -1); */
  /* d->o.sph.debug = 1; */
}

void	my_fucking_parsing_rt(t_data *d)
{
  static int	line = 0;	// ligne courante (ne s'ajoute pas pour les
  int	i;			//	commentaire & ligne vite)

  i = 0;
  //my_printf("[%d]", line);
  if (d->fi.buff[0] == '/' || d->fi.buff[0] == '*' || d->fi.buff[0] == ' '
      || d->fi.buff[0] == '\n' || (!d->fi.buff[0]))
    return; // quitte sans ajouter 'line++' si y'a un commentaire
  test_line(d, line);// test la ligne courrante pour save variable
  line += 1 - d->o.lum.debug - d->o.sph.debug - d->o.cy.debug - d->o.co.debug;
  d->o.lum.debug = 0;
  d->o.sph.debug = 0;
  d->o.cy.debug = 0;
  d->o.co.debug = 0;
}
