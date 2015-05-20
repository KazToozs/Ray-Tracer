/*
** my_realloc.c for allum1 in /home/toozs-_c/Prog_tests/allum1
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Wed Feb 11 17:26:37 2015 cristopher toozs-hobson
** Last update Wed May 20 13:02:21 2015 ugo belfiore
*/

#include "mini.h"

char		*my_realloc(char *buffer, int size)
{
  int		i;
  char		*tmp;

  if ((tmp = malloc(size)) == NULL)
    return (NULL);
  i = 0;
  while (buffer[i] != '\0')
    {
      tmp[i] = buffer[i];
      i++;
    }
  while (i < size)
    tmp[i++] = '\0';
  free(buffer);
  return (tmp);
}
