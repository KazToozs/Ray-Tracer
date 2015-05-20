/*
** my_strdup.c for my_strdup in /home/toozs-_c/rendu/Piscine_C_J08/ex_01
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Wed Nov  5 17:02:51 2014 cristopher toozs-hobson
** Last update Wed May 20 13:12:04 2015 ugo belfiore
*/

#include "mini.h"

char	*my_strdup(char *str)
{
  char	*dest;

  if ((dest = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  dest = my_strcpy(dest, str);
  dest[my_strlen(str)] = 0;
  return (dest);
}
