/*
** my_str_to_wordtab.c for  in /home/belfio_u/rendu/Piscine_C_J08/ex_04
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 24 19:29:19 2014 ugo belfiore
** Last update Tue Mar 17 15:32:10 2015 ugo belfiore
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
  //my_printf("%s\n", d->fi.buff);
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
      // si on a init aucune lumière et qu'il n'y a aps de ligne LIGHT_&
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
	    my_error(d, "ERROR: missing PLAN: in file.", -1);
	}
      else
	{
	  d->o.pl.high = my_getnbr(d->fi.tab[1]);
	  char *test;
	  d->o.pl.color_plan = strtol(d->fi.tab[2], &test, 16);
	  printf("plan: %d %x\n", d->o.pl.high, d->o.pl.color_plan);
	}
    }
  
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
