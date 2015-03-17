/*
** my_str_to_wordtab.c for  in /home/belfio_u/rendu/Piscine_C_J08/ex_04
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 24 19:29:19 2014 ugo belfiore
** Last update Tue Mar 17 09:54:04 2015 ugo belfiore
*/

#include "../include/my.h"
#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"

int	match(char *s1, char *s2)
{
  int	i;

  i = 0;
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

void	test_line(t_data *d, int line)
{
  my_printf("%s\n", d->fi.buff);
  d->fi.tab = my_str_to_wordtab_rt(d->fi.buff);
  my_show_wordtab(d->fi.tab);
  if (line == 0)
    {
      if (!match(d->fi.tab[0], "CAMERA_POS:"))
	my_error(d, "ERROR: missing CAMERA_POS: in file.", -1);
    }
}

void	my_fucking_parsing_rt(t_data *d)
{
  static int	current = 0;	//
  static int	line = 0;	// ligne courante (ne s'ajoute pas pour les
  int	i;			//	commentaire & ligne vite)

  i = 0;
  if (d->fi.buff[0] == '/' || d->fi.buff[0] == '*' || d->fi.buff[0] == ' '
      || d->fi.buff[0] == '\n' || (!d->fi.buff[0]))
    return; // quitte sans ajouter 'line++' si y'a un commentaire
  test_line(d, line);// test la ligne courrante pour save variable
  line++;// fin, ajout de ligne
  if (line == 1)
    exit(0);
}
