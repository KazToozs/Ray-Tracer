/*
** filter.c for filter in /home/fernan_s/Desktop/rendu/MUL_2014_rtracer/src
** 
** Made by fernan_s
** Login   <fernan_s@epitech.net>
** 
** Started on  Mon Jun  1 09:51:51 2015 fernan_s
** Last update Tue Jun  2 17:16:56 2015 ugo belfiore
*/

#include "mini.h"

t_filter	func_filter[] =
  {
    normal_f,
    grey_level,
    wb_filter,
    sepia
  };

void	normal_f(int x, int y, t_wild *s)
{
  int	addr;

  addr = (s->d.sizeline * y) + (x * (s->d.bpp / 8));
  s->d.bigData_f[addr + 2] = s->d.bigData[addr + 2];
  s->d.bigData_f[addr + 1] = s->d.bigData[addr + 1];
  s->d.bigData_f[addr] = s->d.bigData[addr + 0];
}

void	grey_level(int x, int y, t_wild *s)
{
  int	grey;
  int	addr;

  addr = (s->d.sizeline * y) + (x * (s->d.bpp / 8));
  grey = (int)((float)(unsigned char)s->d.bigData[addr + 2] * 0.2125);
  grey += (int)((float)(unsigned char)s->d.bigData[addr + 1] * 0.7154);
  grey += (int)((float)(unsigned char)s->d.bigData[addr + 0] * 0.0721);
  s->d.bigData_f[addr] = (grey > 254) ? 255 : grey;
  s->d.bigData_f[addr + 1] = (grey > 254) ? 255 : grey;
  s->d.bigData_f[addr + 2] = (grey > 254) ? 255 : grey;
}

void	wb_filter(int x, int y, t_wild *s)
{
  int	grey;
  int	addr;

  addr = (s->d.sizeline * y) + (x * (s->d.bpp / 8));
  grey = (int)((float)(unsigned char)s->d.bigData[addr + 2] * 0.2125);
  grey += (int)((float)(unsigned char)s->d.bigData[addr + 1] * 0.7154);
  grey += (int)((float)(unsigned char)s->d.bigData[addr + 0] * 0.0721);
  s->d.bigData_f[addr] = (grey < 64) ? 0
    : ((grey < 128) ? 64
       : ((grey < 192) ? 128
	  : ((grey < 250) ? 192 : 255)));
  s->d.bigData_f[addr + 1] = (grey < 64) ? 0
    : ((grey < 128) ? 64
       : ((grey < 192) ? 128
	  : ((grey < 250) ? 192 : 255)));
  s->d.bigData_f[addr + 2] = (grey < 64) ? 0
    : ((grey < 128) ? 64
       : ((grey < 192) ? 128
	  : ((grey < 250) ? 192 : 255)));
}

void	sepia(int x, int y, t_wild *s)
{
  int	grey;
  int	addr;

  addr = (s->d.sizeline * y) + (x * (s->d.bpp / 8));
  grey = (int)((float)(unsigned char)s->d.bigData[addr + 2] * 0.2125);
  grey += (int)((float)(unsigned char)s->d.bigData[addr + 1] * 0.7154);
  grey += (int)((float)(unsigned char)s->d.bigData[addr + 0] * 0.0721);
  grey %= 255;
  s->d.bigData_f[addr + 2] = (grey + 112) / 2;
  s->d.bigData_f[addr + 1] = (grey + 66) / 2;
  s->d.bigData_f[addr + 0] = (grey + 20) / 2;
}

void	apply_filter(t_wild *s)
{
  int	x;
  int	y;

  x = 0;
  while (x < s->d.x_max)
    {
      y = 0;
      while (y < s->d.y_max)
	func_filter[s->d.filter % 4](x, y++, s);
      x++;
    }
}
