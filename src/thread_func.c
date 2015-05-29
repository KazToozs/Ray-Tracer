/*
** thread_func.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Apr 20 09:48:32 2015 ugo belfiore
** Last update Fri May 29 15:08:23 2015 ugo belfiore
*/

#include "mini.h"

void	part_one(t_st *s)
{
  (s->d.timer == 10) ? algo_rt(s, 2, 2) : 1;
  (s->d.timer == 20) ? algo_rt(s, 4, 1) : 1;
  (s->d.timer == 30) ? algo_rt(s, 7, 1) : 1;
  (s->d.timer == 40) ? algo_rt(s, 3, 0) : 1;
  (s->d.timer == 50) ? algo_rt(s, 0, 3) : 1;
  (s->d.timer == 60) ? algo_rt(s, 0, 0) : 1;
  (s->d.timer == 70) ? algo_rt(s, 4, 0) : 1;
  (s->d.timer == 80) ? algo_rt(s, 2, 3) : 1;
  (s->d.timer == 90) ? algo_rt(s, 2, 1) : 1;
  //(s->d.timer == 100) ? algo_rt(s, , ) : 1;
}

void	part_two(t_st *s)
{
  (s->d.timer == 11) ? algo_rt(s, 2, 6) : 1;
  (s->d.timer == 21) ? algo_rt(s, 1, 4) : 1;
  (s->d.timer == 31) ? algo_rt(s, 1, 1) : 1;
  (s->d.timer == 41) ? algo_rt(s, 5, 0) : 1;
  (s->d.timer == 51) ? algo_rt(s, 8, 3) : 1;
  (s->d.timer == 61) ? algo_rt(s, 8, 0) : 1;
  (s->d.timer == 71) ? algo_rt(s, 6, 3) : 1;
  (s->d.timer == 81) ? algo_rt(s, 1, 2) : 1;
  (s->d.timer == 91) ? algo_rt(s, 6, 1) : 1;
  //(s->d.timer == 101) ? algo_rt(s, , ) : 1;
}

void	part_tree(t_st *s)
{
  (s->d.timer == 12) ? algo_rt(s, 4, 4) : 1;
  (s->d.timer == 22) ? algo_rt(s, 5, 4) : 1;
  (s->d.timer == 32) ? algo_rt(s, 3, 4) : 1;
  (s->d.timer == 42) ? algo_rt(s, 4, 3) : 1;
  (s->d.timer == 52) ? algo_rt(s, 4, 5) : 1;
  (s->d.timer == 62) ? algo_rt(s, 0, 4) : 1;
  (s->d.timer == 72) ? algo_rt(s, 8, 4) : 1;
  (s->d.timer == 82) ? algo_rt(s, 7, 2) : 1;
  (s->d.timer == 92) ? algo_rt(s, 5, 2) : 1;
  //(s->d.timer == 102) ? algo_rt(s, , ) : 1;
}

void	part_four(t_st *s)
{
  (s->d.timer == 13) ? algo_rt(s, 6, 2) : 1;
  (s->d.timer == 23) ? algo_rt(s, 7, 4) : 1;
  (s->d.timer == 33) ? algo_rt(s, 7, 7) : 1;
  (s->d.timer == 43) ? algo_rt(s, 3, 8) : 1;
  (s->d.timer == 53) ? algo_rt(s, 0, 5) : 1;
  (s->d.timer == 63) ? algo_rt(s, 0, 8) : 1;
  (s->d.timer == 73) ? algo_rt(s, 2, 5) : 1;
  (s->d.timer == 83) ? algo_rt(s, 1, 6) : 1;
  (s->d.timer == 93) ? algo_rt(s, 2, 7) : 1;
  //(s->d.timer == 103) ? algo_rt(s, , ) : 1;
}

void	part_five(t_st *s)
{
  (s->d.timer == 14) ? algo_rt(s, 6, 6) : 1;
  (s->d.timer == 24) ? algo_rt(s, 4, 7) : 1;
  (s->d.timer == 34) ? algo_rt(s, 1, 7) : 1;
  (s->d.timer == 44) ? algo_rt(s, 5, 8) : 1;
  (s->d.timer == 54) ? algo_rt(s, 8, 5) : 1;
  (s->d.timer == 64) ? algo_rt(s, 8, 8) : 1;
  (s->d.timer == 74) ? algo_rt(s, 4, 8) : 1;
  (s->d.timer == 84) ? algo_rt(s, 7, 6) : 1;
  (s->d.timer == 94) ? algo_rt(s, 6, 7) : 1;
  //(s->d.timer == 104) ? algo_rt(s, , ) : 1;
}
