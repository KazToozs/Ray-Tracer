/*
** main.c for  in /home/belfio_u/rendu/MUL_2014_wolf3d
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Dec  5 17:23:50 2014 ugo belfiore
** Last update Wed May 20 12:36:47 2015 ugo belfiore
*/

#include "mini.h"

/*
** initialise quelque variable
*/

static void	init_fucking_rt(t_st *s)
{
  int   i;

  i = -1;
  s->d.timer = 0;
  while (++i < 256)
    s->d.f[i] = 0;
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
  //aff_win(&s, "rt");
  close(s.fi.fd);
  return (0);
}

/*
** fonction affichage window.
*/

void	aff_win(t_st *s, char *name)
{
  s->d.x_max = 1200;
  s->d.y_max = 710;
  s->d.w = 1;
  s->d.colo = COLOR_BLACK;
  //sound_init(s);
  printf("CARE:\n");
  (!(s->d.mlx_ptr = mlx_init())) ? my_error(s, "ERROR: mlx init.", -1) : 1;
  printf("LOL\n");
  (!(s->d.win_ptr = mlx_new_window(s->d.mlx_ptr,
				   s->d.x_max, s->d.y_max, name))) ?
    my_error(s, "ERROR: win init.", -1) : 1;
  (!(s->d.img_ptr = mlx_new_image(s->d.mlx_ptr, s->d.x_max, s->d.y_max))) ?
    my_error(s, "ERROR: img init.", -1) : 1;
  s->d.bigData = mlx_get_data_addr(s->d.img_ptr,
				   &s->d.bpp, &s->d.sizeline, &s->d.end);
  init_fucking_rt(s);
  mlx_expose_hook(s->d.win_ptr, &manage_expose, (void *)(s));
  mlx_hook(s->d.win_ptr, 2, 2, &manage_keyPres, (void *)(s));
  mlx_hook(s->d.win_ptr, 3, 3, &manage_keyRelease, (void *)(s));
  mlx_loop_hook(s->d.mlx_ptr, &manage_frame, (void *)(s));
  mlx_loop(s->d.mlx_ptr);
}
