/*
** sound.c for  in /home/belfio_u/rendu/Allum1
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Feb  2 18:53:38 2015 ugo belfiore
** Last update Mon Apr 20 06:53:17 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** focntion qui initialise les sons.
*/

void	sound_init(t_data *d)
{
  FMOD_System_Create(&d->sd.system);
  FMOD_System_Init(d->sd.system, 1, FMOD_INIT_NORMAL, NULL);
  FMOD_System_CreateSound(d->sd.system, "./texture/sound/intro_island.wav",
  				 FMOD_CREATESAMPLE, 0, &d->sd.bonus1);
  FMOD_Sound_SetLoopCount(d->sd.bonus1, -1);
  FMOD_System_PlaySound(d->sd.system, FMOD_CHANNEL_FREE,
                        d->sd.bonus1, 0, NULL);
}
