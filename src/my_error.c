/*
** my_error.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Apr 20 06:52:15 2015 ugo belfiore
** Last update Mon Apr 20 06:54:26 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** fonction echap qui clean et free ce qu'il y a à free.
** i = -1: retour d'erreur + afichage
** i = 0: exit propre avec free
*/

void    my_error(t_data *d, char *error, int i)
{
  if (i == -1)
    my_printf("%s\n", error);
  else if (i == 0)
    {
      my_printf("attention: ");
      FMOD_Sound_Release(d->sd.bonus1);
      FMOD_System_Close(d->sd.system);
      FMOD_System_Release(d->sd.system);
      mlx_destroy_window(d->mlx_ptr, d->win_ptr);
      my_printf("%s\n", error);
    }
  else
    my_printf("%s\n", error);
  exit(i);
}
