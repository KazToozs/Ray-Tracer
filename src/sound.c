/*
** sound.c for  in /home/belfio_u/rendu/Allum1
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Feb  2 18:53:38 2015 ugo belfiore
** Last update Sun May 17 01:25:30 2015 ugo belfiore
*/

#include "mini.h"

/*
** focntion qui initialise les sons.
*/

void	sound_init(t_st *st)
{
  FMOD_System_Create(&st->sd.system);
  FMOD_System_Init(st->sd.system, 1, FMOD_INIT_NORMAL, NULL);
  FMOD_System_CreateSound(st->sd.system, "./texture/sound/intro_island.wav",
  				 FMOD_CREATESAMPLE, 0, &st->sd.bonus1);
  FMOD_Sound_SetLoopCount(st->sd.bonus1, -1);
  FMOD_System_PlaySound(st->sd.system, FMOD_CHANNEL_FREE,
                        st->sd.bonus1, 0, NULL);
}
