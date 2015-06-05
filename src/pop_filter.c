/*
** pop_filter.c for filter in /home/fernan_s/Desktop/rendu/MUL_2014_rtracer/src
** 
** Made by fernan_s
** Login   <fernan_s@epitech.net>
** 
** Started on  Wed Jun  3 20:00:12 2015 fernan_s
** Last update Fri Jun  5 18:06:30 2015 ugo belfiore
*/

#include "mini.h"

void		ul_pop(unsigned int grey, int x, int y, t_wild *s)
{
  int		addr;

  addr = (s->d.sizeline * y) + (x * (s->d.bpp / 8));
  s->d.bigData_f[addr + 2] = 255 ^ grey;
  s->d.bigData_f[addr + 1] = grey;
  s->d.bigData_f[addr] = grey;
}

void		ur_pop(unsigned int grey, int x, int y, t_wild *s)
{
  int		addr;

  addr = (s->d.sizeline * y) + (x * (s->d.bpp / 8));
  s->d.bigData_f[addr + 2] = grey;
  s->d.bigData_f[addr + 1] = 255 ^ grey;
  s->d.bigData_f[addr] = 255 ^ grey;
}

void		dl_pop(unsigned int grey, int x, int y, t_wild *s)
{
  int		addr;

  addr = (s->d.sizeline * y) + (x * (s->d.bpp / 8));
  s->d.bigData_f[addr + 2] = 255;
  s->d.bigData_f[addr + 1] = 255 ^ grey;
  s->d.bigData_f[addr] = grey;
}

void		dr_pop(unsigned int grey, int x, int y, t_wild *s)
{
  int		addr;

  addr = (s->d.sizeline * y) + (x * (s->d.bpp / 8));
  s->d.bigData_f[addr + 2] = 255 ^ grey;
  s->d.bigData_f[addr + 1] = grey;
  s->d.bigData_f[addr] = 255;
}

void		pop_filter(int x, int y, t_wild *s)
{
  unsigned int	grey;

  if (x % 2 || y % 2)
    return ;
  grey = color_avarage(x, y, s);
  ul_pop(grey, (x / 2), (y / 2), s);
  ur_pop(grey, (x / 2) + (s->d.x_max / 2), (y / 2), s);
  dl_pop(grey, (x / 2), (y / 2) + (s->d.y_max / 2), s);
  dr_pop(grey, (x / 2) + (s->d.x_max / 2), (y / 2)
	 + (s->d.y_max / 2), s);
}
