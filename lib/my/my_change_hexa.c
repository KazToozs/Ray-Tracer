/*
** my_change_hexa.c for  in /home/belfio_u/rendu/MUL_2014_rtv1/lib/my
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Feb  9 06:21:08 2015 ugo belfiore
** Last update Mon Feb  9 06:22:08 2015 ugo belfiore
*/

int	my_change_hexa(int R, int G, int B)
{
  if (R > 255)
    R = 255;
  if (G > 255)
    G = 255;
  if (B > 255)
    B = 255;
  return (B * 256 * 256 + G * 256 + R);
}
