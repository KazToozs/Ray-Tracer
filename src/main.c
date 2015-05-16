/*
** main.c for  in /home/belfio_u/rendu/MUL_2014_wolf3d
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Dec  5 17:23:50 2014 ugo belfiore
** Last update Sun May 17 01:38:02 2015 ugo belfiore
*/

#include "mini.h"

/*
** initialise quelque variable
*/

static void	init_fucking_rt(t_data *d)
{
  int   i;

  i = -1;
  d->timer = 0;
  while (++i < 256)
    d->f[i] = 0;
}

/*
** fonction main 
*/

int		main(int ac, char **av)
{
  extern char	**environ;
  t_st		s;

  ac = (ac == 2) ? ac : ac;
  if (environ[0] == NULL)
    my_error(&s, "ERROR: environment.", -1);
  s.fi.fd = open(av[1], O_RDONLY);
  if (s.fi.fd == -1)
    {
      s.fi.fd = open("./maps/scene1.conf", O_RDONLY);
      if (s.fi.fd == -1)
	my_error(&s, "ERROR: no argument & file scene1.conf corrupted.", -1);
    }
  my_parsing_rt(&s);
  //aff_win(&s, "rtv1");
  close(s.fi.fd);
  return (0);
}

/*
** fonction affichage window.
*/

void	aff_win(t_st *s, char *name)
{
  /* d->x_max = 1200; */
  /* d->y_max = 710; */
  /* d->w = 1; */
  /* //sound_init(d); */
  /* (!(d->mlx_ptr = mlx_init())) ? my_error(d, "ERROR: mlx init.", -1) : 1; */
  /* (!(d->win_ptr = mlx_new_window(d->mlx_ptr, d->x_max, d->y_max, name))) ? */
  /*   my_error(d, "ERROR: win init.", -1) : 1; */
  /* (!(d->img_ptr = mlx_new_image(d->mlx_ptr, d->x_max, d->y_max))) ? */
  /*   my_error(d, "ERROR: img init.", -1) : 1; */
  /* d->bigData = mlx_get_data_addr(d->img_ptr, &d->bpp, &d->sizeline, &d->end); */
  /* init_fucking_rt(d); */
  /* mlx_expose_hook(d->win_ptr, &manage_expose, (void *)(d)); */
  /* mlx_hook(d->win_ptr, 2, 2, &manage_keyPres, (void *)(d)); */
  /* mlx_hook(d->win_ptr, 3, 3, &manage_keyRelease, (void *)(d)); */
  /* mlx_loop_hook(d->mlx_ptr, &manage_frame, (void *)(d)); */
  /* mlx_loop(d->mlx_ptr); */
}
