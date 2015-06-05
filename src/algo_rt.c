/*
** algo_rt.c for  in /home/belfio_u/rendu/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Sun Feb  8 16:18:36 2015 ugo belfiore
** Last update Fri Jun  5 17:49:29 2015 pallua_j
*/

#include "mini.h"

/*
** algo principal du rt, qui va boucler sur chaque pixel
** (ou plutot tout les 5 pixel, avec un system qui permet d'afficher
** petit à petit la scène
*/

void		my_ave(t_st *s, float r[s->ms], float g[s->ms], float b[s->ms])
{
  float		r_f;
  float		g_f;
  float		b_f;
  int		nb;

  nb = -1;
  r_f = 0;
  g_f = 0;
  b_f = 0;
  while (++nb < s->ms)
    {
      r_f += r[nb] / s->ms;
      g_f += g[nb] / s->ms;
      b_f += b[nb] / s->ms;
    }
  if (r_f > 255)
    r_f = 255;
  if (g_f > 255)
    g_f = 255;
  if (b_f > 255)
    b_f = 255;
  s->colo = ((int)r_f) + ((int)g_f * 0x100) + ((int)b_f * 0x10000);
}

void		init_struct_ray(t_st *s)
{
  s->ref = 0;
  s->nb_spots = 0;
  s->colo = COLOR_BLACK;
  s->x.k = 10000000;
  s->c.v.vx = 1000;
  rotate(&s->c.rot, &s->c.v, &s->c.p, 2);
}

void		anti_aliasing(t_st *s, int x, int y, t_wild *w)
{
  double	part;
  int		nbx;
  int		nby;
  int		nb;
  float		c[3][s->ms];
  float		aa[s->ms];

  nbx = -1;
  part = 1 / (sqrt(s->ms) + 1);
  nb = -1;
  while (++nbx < sqrt(s->ms))
    {
      nby = -1;
      while (++nby < sqrt(s->ms))
	{
	  s->c.v.vy = (w->d.x_max / 2) - (x + (part * (nbx + 1)));
	  s->c.v.vz = (w->d.y_max / 2) - (y + (part * (nby + 1)));
	  init_struct_ray(s);
	  aa[++nb] = calc(s);
	  c[0][nb] = (int)aa[nb] & 0xFF;
	  c[1][nb] = ((int)aa[nb] >> 8) & 0xFF;
	  c[2][nb] = ((int)aa[nb] >> 16) & 0xFF;
	}
    }
  my_ave(s, c[0], c[1], c[2]);
}

void	algo_rt(t_wild *w, t_st *s, int flew, int flew2)
{
  int	i;
  int	j;

  i = flew;
  j = flew2;
  while (i < w->d.x_max)
    {
      while (j < w->d.y_max)
	{
	  anti_aliasing(s, i, j, w);
	  (s->tt == 0) ? aff_pix_img_zero(w, i, j, w->d.bigData) : 1;
	  (s->tt == 1) ? aff_pix_img_one(w, i, j, w->d.bigData) : 1;
	  (s->tt == 2) ? aff_pix_img_two(w, i, j, w->d.bigData) : 1;
	  (s->tt == 3) ? aff_pix_img_tree(w, i, j, w->d.bigData) : 1;
	  (s->tt == 4) ? aff_pix_img_four(w, i, j, w->d.bigData) : 1;
	  j += 9;
	}
      j = flew2;
      i += 9;
    }
}
