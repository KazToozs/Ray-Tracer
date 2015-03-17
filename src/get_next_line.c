/*
** get_next_line.c for  in /home/belfio_u/rendu/CPE_2014_get_next_line
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sat Nov 22 15:11:19 2014 ugo belfiore
** Last update Tue Mar 17 08:34:24 2015 ugo belfiore
*/

#include "../include/my.h"
#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"

#define LEN 4096
char    *reset_buff(char *buff);
char    *my_strcat2(char *src1, char *src2, int ret);
char    *read_loop(const int fd, char *result);
char    *my_strdup2(char *str);

char		*read_loop(const int fd, char *result)
{
  char		*buff;
  int		ret;

  ret = LEN;
  buff = malloc((sizeof(char) * LEN) + 1);
  buff[LEN] = '\0';
  while (ret == LEN)
    {
      ret = read(fd, buff, LEN);
      if (ret > 0)
	{
	  result = my_strcat2(result, buff, ret);
     	  buff = reset_buff(buff);
	}
      else
	return (NULL);
    }
  free(buff);
  return (result);
}

char		*my_strdup2(char *str)
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

char		*my_strcat2(char *src1, char *src2, int ret)
{
  static int	result_len = 0;
  int		i;
  int		j;
  char		*result;

  i = 0;
  j = 0;
  result_len += ret;
  result = malloc((sizeof(char) * result_len) + 1);
  if (src1 != NULL)
    while (src1[i] != '\0')
      {
	result[i] = src1[i];
	i++;
      }
  while (src2[j] != '\0')
    {
      result[i] = src2[j];
      i++;
      j++;
    }
  result[i] = '\0';
  free(src1);
  return (result);
}

char		*reset_buff(char *buff)
{
  int		i;

  i = 0;
  while (buff[i] != '\0')
    {
      buff[i] = '\0';
      i++;
    }
  return (buff);
}

char		*get_next_line(const int fd)
{
  int		i;
  char		*result;
  static char	*save = NULL;

  i = 0;
  result = NULL;
  if (save == NULL)
    {
      result = read_loop(fd, result);
      if (result == NULL)
	return (NULL);
    }
  else
    result = my_strdup2(save);
  while (result[i] != '\0' && result[i] != '\n')
    ++i;
  if (result[i] == '\0')
    {
      save = &result[i];
      return ((result[0] != '\0') ? (my_strdup2(result)) : (NULL));
    }
  result[i] = '\0';
  save = &result[++i];
  return (my_strdup2(result));
}
