/*
** thread_func.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Apr 20 09:48:32 2015 ugo belfiore
** Last update Sun May 31 01:05:51 2015 ugo belfiore
*/

#include "mini.h"

void	part_one(t_wild *w)
{
  (w->d.timer == 10) ? algo_rt(w, &w->s[0], 2, 2) : 1;
  (w->d.timer == 20) ? algo_rt(w, &w->s[0], 4, 1) : 1;
  (w->d.timer == 30) ? algo_rt(w, &w->s[0], 7, 1) : 1;
  (w->d.timer == 40) ? algo_rt(w, &w->s[0], 3, 0) : 1;
  (w->d.timer == 50) ? algo_rt(w, &w->s[0], 0, 3) : 1;
  (w->d.timer == 60) ? algo_rt(w, &w->s[0], 0, 0) : 1;
  (w->d.timer == 70) ? algo_rt(w, &w->s[0], 4, 0) : 1;
  (w->d.timer == 80) ? algo_rt(w, &w->s[0], 2, 3) : 1;
  (w->d.timer == 90) ? algo_rt(w, &w->s[0], 2, 1) : 1;
  (w->d.timer == 100) ? algo_rt(w, &w->s[0], 1, 0) : 1;
  (w->d.timer == 110) ? algo_rt(w, &w->s[0], 6, 0) : 1;
  (w->d.timer == 120) ? algo_rt(w, &w->s[0], 2, 0) : 1;
  (w->d.timer == 130) ? algo_rt(w, &w->s[0], 0, 1) : 1;
  (w->d.timer == 140) ? algo_rt(w, &w->s[0], 2, 8) : 1;
  (w->d.timer == 150) ? algo_rt(w, &w->s[0], 3, 1) : 1;
  (w->d.timer == 160) ? algo_rt(w, &w->s[0], 2, 4) : 1;
  (w->d.timer == 170) ? algo_rt(w, &w->s[0], 5, 3) : 1;
}

void	part_two(t_wild *w)
{
  (w->d.timer == 10) ? algo_rt(w, &w->s[1], 2, 6) : 1;
  (w->d.timer == 20) ? algo_rt(w, &w->s[1], 1, 4) : 1;
  (w->d.timer == 30) ? algo_rt(w, &w->s[1], 1, 1) : 1;
  (w->d.timer == 40) ? algo_rt(w, &w->s[1], 5, 0) : 1;
  (w->d.timer == 50) ? algo_rt(w, &w->s[1], 8, 3) : 1;
  (w->d.timer == 60) ? algo_rt(w, &w->s[1], 8, 0) : 1;
  (w->d.timer == 70) ? algo_rt(w, &w->s[1], 6, 3) : 1;
  (w->d.timer == 80) ? algo_rt(w, &w->s[1], 1, 2) : 1;
  (w->d.timer == 90) ? algo_rt(w, &w->s[1], 6, 1) : 1;
  (w->d.timer == 100) ? algo_rt(w, &w->s[1], 4, 2) : 1;
  (w->d.timer == 110) ? algo_rt(w, &w->s[1], 3, 2) : 1;
  (w->d.timer == 120) ? algo_rt(w, &w->s[1], 7, 0) : 1;
  (w->d.timer == 130) ? algo_rt(w, &w->s[1], 8, 1) : 1;
  (w->d.timer == 140) ? algo_rt(w, &w->s[1], 0, 7) : 1;
  (w->d.timer == 150) ? algo_rt(w, &w->s[1], 5, 1) : 1;
  (w->d.timer == 160) ? algo_rt(w, &w->s[1], 4, 6) : 1;
  (w->d.timer == 170) ? algo_rt(w, &w->s[1], 5, 5) : 1;
}

void	part_tree(t_wild *w)
{
  (w->d.timer == 10) ? algo_rt(w, &w->s[2], 4, 4) : 1;
  (w->d.timer == 20) ? algo_rt(w, &w->s[2], 5, 4) : 1;
  (w->d.timer == 30) ? algo_rt(w, &w->s[2], 3, 4) : 1;
  (w->d.timer == 40) ? algo_rt(w, &w->s[2], 4, 3) : 1;
  (w->d.timer == 50) ? algo_rt(w, &w->s[2], 4, 5) : 1;
  (w->d.timer == 60) ? algo_rt(w, &w->s[2], 0, 4) : 1;
  (w->d.timer == 70) ? algo_rt(w, &w->s[2], 8, 4) : 1;
  (w->d.timer == 80) ? algo_rt(w, &w->s[2], 7, 2) : 1;
  (w->d.timer == 90) ? algo_rt(w, &w->s[2], 5, 2) : 1;
  (w->d.timer == 100) ? algo_rt(w, &w->s[2], 5, 6) : 1;
  (w->d.timer == 110) ? algo_rt(w, &w->s[2], 7, 3) : 1;
  (w->d.timer == 120) ? algo_rt(w, &w->s[2], 8, 6) : 1;
  (w->d.timer == 130) ? algo_rt(w, &w->s[2], 0, 6) : 1;
  (w->d.timer == 140) ? algo_rt(w, &w->s[2], 6, 8) : 1;
  (w->d.timer == 150) ? algo_rt(w, &w->s[2], 1, 3) : 1;
  (w->d.timer == 160) ? algo_rt(w, &w->s[2], 6, 5) : 1;
}

void	part_four(t_wild *w)
{
  (w->d.timer == 10) ? algo_rt(w, &w->s[3], 6, 2) : 1;
  (w->d.timer == 20) ? algo_rt(w, &w->s[3], 7, 4) : 1;
  (w->d.timer == 30) ? algo_rt(w, &w->s[3], 7, 7) : 1;
  (w->d.timer == 40) ? algo_rt(w, &w->s[3], 3, 8) : 1;
  (w->d.timer == 50) ? algo_rt(w, &w->s[3], 0, 5) : 1;
  (w->d.timer == 60) ? algo_rt(w, &w->s[3], 0, 8) : 1;
  (w->d.timer == 70) ? algo_rt(w, &w->s[3], 2, 5) : 1;
  (w->d.timer == 80) ? algo_rt(w, &w->s[3], 1, 6) : 1;
  (w->d.timer == 90) ? algo_rt(w, &w->s[3], 2, 7) : 1;
  (w->d.timer == 100) ? algo_rt(w, &w->s[3], 7, 5) : 1;
  (w->d.timer == 110) ? algo_rt(w, &w->s[3], 3, 5) : 1;
  (w->d.timer == 120) ? algo_rt(w, &w->s[3], 0, 6) : 1;
  (w->d.timer == 130) ? algo_rt(w, &w->s[3], 8, 2) : 1;
  (w->d.timer == 140) ? algo_rt(w, &w->s[3], 7, 8) : 1;
  (w->d.timer == 150) ? algo_rt(w, &w->s[3], 3, 7) : 1;
  (w->d.timer == 160) ? algo_rt(w, &w->s[3], 6, 4) : 1;
}

void	part_five(t_wild *w)
{
  (w->d.timer == 10) ? algo_rt(w, &w->s[4], 6, 6) : 1;
  (w->d.timer == 20) ? algo_rt(w, &w->s[4], 4, 7) : 1;
  (w->d.timer == 30) ? algo_rt(w, &w->s[4], 1, 7) : 1;
  (w->d.timer == 40) ? algo_rt(w, &w->s[4], 5, 8) : 1;
  (w->d.timer == 50) ? algo_rt(w, &w->s[4], 8, 5) : 1;
  (w->d.timer == 60) ? algo_rt(w, &w->s[4], 8, 8) : 1;
  (w->d.timer == 70) ? algo_rt(w, &w->s[4], 4, 8) : 1;
  (w->d.timer == 80) ? algo_rt(w, &w->s[4], 7, 6) : 1;
  (w->d.timer == 90) ? algo_rt(w, &w->s[4], 6, 7) : 1;
  (w->d.timer == 100) ? algo_rt(w, &w->s[4], 8, 7) : 1;
  (w->d.timer == 110) ? algo_rt(w, &w->s[4], 1, 5) : 1;
  (w->d.timer == 120) ? algo_rt(w, &w->s[4], 0, 2) : 1;
  (w->d.timer == 130) ? algo_rt(w, &w->s[4], 1, 8) : 1;
  (w->d.timer == 140) ? algo_rt(w, &w->s[4], 5, 7) : 1;
  (w->d.timer == 150) ? algo_rt(w, &w->s[4], 3, 6) : 1;
  (w->d.timer == 160) ? algo_rt(w, &w->s[4], 3, 3) : 1;
}
