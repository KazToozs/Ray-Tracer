/*
** thread_func.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Apr 20 09:48:32 2015 ugo belfiore
** Last update Mon May  4 13:00:21 2015 ugo belfiore
*/

#include "mini.h"

void	part_one(t_data *d)
{
  (d->timer == 10) ? algo_rt(d, 4, 0) : 1;
  (d->timer == 20) ? algo_rt(d, 3, 0) : 1;
  (d->timer == 30) ? algo_rt(d, 2, 0) : 1;
  (d->timer == 40) ? algo_rt(d, 1, 0) : 1;
  (d->timer == 50) ? algo_rt(d, 0, 0) : 1;
}

void	part_two(t_data *d)
{
  (d->timer == 11) ? algo_rt(d, 4, 1) : 1;
  (d->timer == 21) ? algo_rt(d, 3, 1) : 1;
  (d->timer == 31) ? algo_rt(d, 2, 1) : 1;
  (d->timer == 41) ? algo_rt(d, 1, 1) : 1;
  (d->timer == 51) ? algo_rt(d, 0, 1) : 1;
}

void	part_tree(t_data *d)
{
  (d->timer == 12) ? algo_rt(d, 4, 2) : 1;
  (d->timer == 22) ? algo_rt(d, 3, 2) : 1;
  (d->timer == 32) ? algo_rt(d, 2, 2) : 1;
  (d->timer == 42) ? algo_rt(d, 1, 2) : 1;
  (d->timer == 52) ? algo_rt(d, 0, 2) : 1;
}

void	part_four(t_data *d)
{
  (d->timer == 13) ? algo_rt(d, 4, 3) : 1;
  (d->timer == 23) ? algo_rt(d, 3, 3) : 1;
  (d->timer == 33) ? algo_rt(d, 2, 3) : 1;
  (d->timer == 43) ? algo_rt(d, 1, 3) : 1;
  (d->timer == 53) ? algo_rt(d, 0, 3) : 1;
}

void	part_five(t_data *d)
{
  (d->timer == 14) ? algo_rt(d, 4, 4) : 1;
  (d->timer == 24) ? algo_rt(d, 3, 4) : 1;
  (d->timer == 34) ? algo_rt(d, 2, 4) : 1;
  (d->timer == 44) ? algo_rt(d, 1, 4) : 1;
  (d->timer == 54) ? algo_rt(d, 0, 4) : 1;
}
