/*
** my_error.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Apr 20 06:52:15 2015 ugo belfiore
** Last update Sat May 30 23:20:21 2015 ugo belfiore
*/

#include "mini.h"

/*
** fonction echap qui clean et free ce qu'il y a à free.
** i = -1: retour d'erreur + afichage
** i = 0: exit propre avec free
*/

void    my_error(t_wild *w, char *error, int i)
{
  if (i == -1)
    my_printf("%s\n", error);
  else if (i == 0)
    {
      /* my_error_free(d); */
      /* free(d->o.co.r_cone); */
      /* free(d->o.co.color_cone); */
      /* free(d->o.co.rotx); */
      /* free(d->o.co.roty); */
      /* free(d->o.co.rotz); */
      /* free(d->o.co.high); */
      my_printf("attention: ");
      FMOD_Sound_Release(w->sd.bonus1);
      FMOD_System_Close(w->sd.system);
      FMOD_System_Release(w->sd.system);
      mlx_destroy_window(w->d.mlx_ptr, w->d.win_ptr);
      my_printf("%s\n", error);
    }
  else
    my_printf("%s\n", error);
  exit(i);
}

void	aff_error(char *str)
{
  my_printf("%s\n", str);
  exit(EXIT_SUCCESS);
}
