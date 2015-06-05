/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/toozs-_c/rendu/Piscine_C_J08/ex_04
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Mon Nov  3 10:09:14 2014 cristopher toozs-hobson
** Last update Fri Jun  5 17:51:57 2015 ugo belfiore
*/

#include "mini.h"

int		count_words(char *str)
{
  int		i;
  int		cpt;

  i = 0;
  cpt = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
	  || (str[i] >= '0' && str[i] <= '9') || str[i] == '-'
	  || str[i] == '.')
	{
	  cpt++;
	  while ((str[i] >= 'a' && str[i] <= 'z')
		 || (str[i] >= 'A' && str[i] <= 'Z')
		 || (str[i] >= '0' && str[i] <= '9') || str[i] == '-'
		 || str[i] == '.')
	    i++;
	}
      else
	i++;
    }
  return (cpt);
}

int		count_chars(char *str, int *i)
{
  int		cpt;

  cpt = 0;
  while (str[*i] && ((str[*i] >= 'a' && str[*i] <= 'z')
		     || (str[*i] >= 'A' && str[*i] <= 'Z')
		     || (str[*i] >= '0' && str[*i] <= '9') || str[*i] == '-'
		     || str[*i] == '.'))
    {
      cpt++;
      *i = *i + 1;
    }
  return (cpt);
}

char		**my_str_tab(char *st)
{
  int		i;
  int		words;
  int		size;
  char		**tab;

  i = 0;
  size = 0;
  words = count_words(st);
  if ((tab = malloc(sizeof(char *) * (words + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (st[i] && words > 0)
    {
      if ((st[i] >= 'a' && st[i] <= 'z') || (st[i] >= 'A' && st[i] <= 'Z')
	  || (st[i] >= '0' && st[i] <= '9') || st[i] == '-' || st[i] == '.')
	{
	  tab[size] = my_strdup(st + i);
	  tab[size] [count_chars(st, &i)] = '\0';
	  size++;
	  words = words - 1;
	}
      else
	i++;
    }
  tab[size] = NULL;
  return (tab);
}
