/*
** sound.c for  in /home/belfio_u/rendu/Allum1
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Feb  2 18:53:38 2015 ugo belfiore
** Last update Sun May 31 02:09:44 2015 ugo belfiore
*/

#include "mini.h"

/*
** focntion qui initialise les sons.
*/

void	sound_init(t_wild *w)
{
  FMOD_System_Create(&w->sd.system);
  FMOD_System_Init(w->sd.system, 1, FMOD_INIT_NORMAL, NULL);
  FMOD_System_CreateSound(w->sd.system, "./texture/sound/intro_island.wav",
  				 FMOD_CREATESAMPLE, 0, &w->sd.bonus1);
  FMOD_Sound_SetLoopCount(w->sd.bonus1, -1);
  FMOD_System_PlaySound(w->sd.system, FMOD_CHANNEL_FREE,
                        w->sd.bonus1, 0, NULL);
}
