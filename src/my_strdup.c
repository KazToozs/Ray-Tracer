/*
** my_strdup.c for  in /home/belfio_u/PISCINE/rendu/Piscine_C_J07
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Oct  7 21:31:05 2014 ugo belfiore
** Last update Tue Mar 17 08:34:01 2015 ugo belfiore
*/

#include "../include/my.h"
#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"

char		*my_strdup(char *str)
{
  int		i;
  char		*cpy;

  i = 0;
  while (str[i] != '\0')
    i++;
  cpy = malloc(sizeof(char) * i + 1);
  i = 0;
  while (str[i] != '\0')
    {
      cpy[i] = str[i];
      i++;
    }
  cpy[i] = '\0';
  return (cpy);
}
