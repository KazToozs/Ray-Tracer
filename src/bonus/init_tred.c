/*
** init_tred.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Mar 12 17:58:09 2015 ugo belfiore
** Last update Sat Mar 14 14:19:50 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

void	*thread_1(void *arg)
{
  printf("Nous sommes dans le thread 1.\n");
  (void)arg;
  pthread_exit(NULL);
}

void	*thread_2(void *arg)
{
  printf("Nous sommes dans le thread 2.\n");
  (void)arg;
  pthread_exit(NULL);
}

void	*thread_3(void *arg)
{
  printf("Nous sommes dans le thread 3.\n");
  (void)arg;
  pthread_exit(NULL);
}

void	*thread_4(void *arg)
{
  printf("Nous sommes dans le thread 4.\n");
  (void)arg;
  pthread_exit(NULL);
}

void	*thread_5(void *arg)
{
  printf("Nous sommes dans le thread 5.\n");
  (void)arg;
  pthread_exit(NULL);
}

/*
** initialise les thread
*/

void	init_tred(t_data *d)
{
  if (pthread_create(&d->td.td1, NULL, thread_1, NULL))
    exit(0);
  if (pthread_create(&d->td.td2, NULL, thread_2, NULL))
    exit(0);
  if (pthread_create(&d->td.td3, NULL, thread_3, NULL))
    exit(0);
  if (pthread_create(&d->td.td4, NULL, thread_4, NULL))
    exit(0);
  if (pthread_create(&d->td.td5, NULL, thread_5, NULL))
    exit(0);
  if (pthread_join(d->td.td1, NULL))
    exit(0);
  if (pthread_join(d->td.td2, NULL))
    exit(0);
  if (pthread_join(d->td.td3, NULL))
    exit(0);
  if (pthread_join(d->td.td4, NULL))
    exit(0);
  if (pthread_join(d->td.td5, NULL))
    exit(0);
}
