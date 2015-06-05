/*
** negativ.c for filter in /home/fernan_s/Desktop/rendu/MUL_2014_rtracer/src
** 
** Made by fernan_s
** Login   <fernan_s@epitech.net>
** 
** Started on  Fri Jun  5 14:01:11 2015 fernan_s
** Last update Fri Jun  5 14:02:22 2015 fernan_s
*/

#include "mini.h"

void	negativ_f(int x, int y, t_wild *s)
{
  int	addr;

  addr = (s->d.sizeline * y) + (x * (s->d.bpp / 8));
  s->d.bigData_f[addr + 2] = 255 ^ s->d.bigData[addr + 2];
  s->d.bigData_f[addr + 1] = 255 ^ s->d.bigData[addr + 1];
  s->d.bigData_f[addr] = 255 ^ s->d.bigData[addr + 0];
}

void	negativ_inv_f(int x, int y, t_wild *s)
{
  int	addr;

  addr = (s->d.sizeline * y) + (x * (s->d.bpp / 8));
  s->d.bigData_f[addr + 2] = 255 - s->d.bigData[addr + 0];
  s->d.bigData_f[addr + 1] = 255 - s->d.bigData[addr + 1];
  s->d.bigData_f[addr] = 255 - s->d.bigData[addr + 2];
}
