/*
** my_str_to_wordtab.c for  in /home/belfio_u/rendu/Piscine_C_J08/ex_04
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 24 19:29:19 2014 ugo belfiore
** Last update Tue Mar 17 09:28:08 2015 ugo belfiore
*/

#include "../include/my.h"
#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"

int	my_count_word_rt(char *s);
int	my_count_char_rt(char *s, int *i);

int	my_count_word_rt(char *s)
{
  int	i;
  int	cpt;

  i = 0;
  cpt = 0;
  while (s[i])
    {
      if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
          || (s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '+'
	  || s[i] == '.' || s[i] == ':' || s[i] == ';' || s[i] == '('
	  || s[i] == ')' || s[i] == '_')
        {
          cpt++;
          while (s[i] && ((s[i] >= 'a' && s[i] <= 'z') || s[i] == '-'
                          || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '+'
                          || (s[i] >= '0' && s[i] <= '9') || s[i] == '.'
			  || s[i] == ':' || s[i] == ';' || s[i] == '('
			  || s[i] == ')' || s[i] == '_'))
            i++;
        }
      i++;
    }
  return (cpt);
}

int	my_count_char_rt(char *s, int *i)
{
  int	cpt;

  cpt = 0;
  while (s[*i] && ((s[*i] >= 'a' && s[*i] <= 'z') || s[*i] == '-'
		   || (s[*i] >= 'A' && s[*i] <= 'Z') || s[*i] == '+'
		   || (s[*i] >= '0' && s[*i] <= '9') || s[*i] == '.'
		   || s[*i] == ':' || s[*i] == ';' || s[*i] == '('
		   || s[*i] == ')' || s[*i] == '_'))
    {
      cpt++;
      *i = *i + 1;
    }
  return (cpt);
}

char	**my_str_to_wordtab_rt(char *str)
{
  int	i;
  int	n;
  int	word;
  char	**tab;

  i = 0;
  n = 0;
  word = my_count_word_rt(my_strdup(str));
  tab = (char **)malloc(sizeof(char *) * word);
  while (str[i] && word > 0)
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
          || (str[i] >= '0' && str[i] <= '9') || str[i] == '-'
	  || str[i] == '+' || str[i] == '.' || str[i] == ':' || str[i] == ';'
	  || str[i] == '(' || str[i] == ')' || str[i] == '_')
        {
          tab[n] = my_strdup(str + i);
          tab[n][my_count_char_rt(str, &i)] = '\0';
          n++;
          word--;
        }
      i++;
    }
  tab[my_count_word_rt(my_strdup(str))] = NULL;
  return (tab);
}
