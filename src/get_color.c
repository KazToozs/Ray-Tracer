/*
** get_grey.c for filter in /home/fernan_s/Desktop/rendu/MUL_2014_rtracer/src
** 
** Made by fernan_s
** Login   <fernan_s@epitech.net>
** 
** Started on  Thu Jun  4 13:41:54 2015 fernan_s
** Last update Thu Jun  4 20:53:53 2015 fernan_s
*/

#include "mini.h"

unsigned int	get_color(int addr, t_wild *s)
{
  unsigned int	color;

  color = (unsigned char)s->d.bigData[addr + 2];
  color += (unsigned char)s->d.bigData[addr + 1];
  color += (unsigned char)s->d.bigData[addr + 0];
  color /= 3;
  color %= 255;
  return (color);
}

unsigned int	color_avarage(int x, int y, t_wild *s)
{
  int		addr;
  unsigned int	color;

  addr = (s->d.sizeline * y) + (x * (s->d.bpp / 8));
  color = (unsigned int)((float)get_color(addr, s) * 0.2500f);
  addr = (s->d.sizeline * (y + 1)) + (x * (s->d.bpp / 8));
  color += (unsigned int)((float)get_color(addr, s) * 0.2500f);
  addr = (s->d.sizeline * (y + 1)) + ((x + 1) * (s->d.bpp / 8));
  color += (unsigned int)((float)get_color(addr, s) * 0.2500f);
  addr = (s->d.sizeline * y) + ((x + 1) * (s->d.bpp / 8));
  color += (unsigned int)((float)get_color(addr, s) * 0.2500f);
  return (color);
}
