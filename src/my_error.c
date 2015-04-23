/*
** my_error.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Apr 20 06:52:15 2015 ugo belfiore
** Last update Thu Apr 23 09:13:48 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** fonction echap qui clean et free ce qu'il y a à free.
** i = -1: retour d'erreur + afichage
** i = 0: exit propre avec free
*/

static void	my_error_free(t_data *d)
{
  free(d->o.lum.x_lum);
  free(d->o.lum.y_lum);
  free(d->o.lum.z_lum);
  free(d->o.pl.high);
  free(d->o.pl.color_plan);
  free(d->o.sph.x_sphere);
  free(d->o.sph.y_sphere);
  free(d->o.sph.z_sphere);
  free(d->o.sph.r_sh);
  free(d->o.sph.color_sphere);
  free(d->o.sph.rotx);
  free(d->o.sph.roty);
  free(d->o.sph.rotz);
  free(d->o.cy.x_cyl);
  free(d->o.cy.y_cyl);
  free(d->o.cy.z_cyl);
  free(d->o.cy.r_cyl);
  free(d->o.cy.color_cyl);
  free(d->o.cy.rotx);
  free(d->o.cy.roty);
  free(d->o.cy.rotz);
  free(d->o.cy.high);
  free(d->o.co.x_cone);
  free(d->o.co.y_cone);
  free(d->o.co.z_cone);
}

void    my_error(t_data *d, char *error, int i)
{
  if (i == -1)
    my_printf("%s\n", error);
  else if (i == 0)
    {
      my_error_free(d);
      free(d->o.co.r_cone);
      free(d->o.co.color_cone);
      free(d->o.co.rotx);
      free(d->o.co.roty);
      free(d->o.co.rotz);
      free(d->o.co.high);
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
