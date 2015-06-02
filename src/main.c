/*
** main.c for  in /home/belfio_u/rendu/MUL_2014_wolf3d
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Dec  5 17:23:50 2014 ugo belfiore
** Last update Tue Jun  2 17:19:12 2015 ugo belfiore
*/

#include "mini.h"

/*
** initialise quelque variable
*/

static void	init_glo(t_wild *w)
{
  int		i;
  int		t;

  i = -1;
  t = -1;
  while (++t < 5)
    w->s[t].type = 0;
  w->d.timer = 0;
  while (++i < 256)
    w->d.f[i] = 0;
  w->d.filter = 0;
}

/*
** fonction main 
*/

int		main(int ac, char **av)
{
  extern char	**environ;
  t_wild	w;

  ac = (ac == 2) ? ac : ac;
  if (environ[0] == NULL)
    my_error(&w, "ERROR: environment.", -1);
  w.fi.fd = open(av[1], O_RDONLY);
  if (w.fi.fd == -1)
    {
      w.fi.fd = open("./maps/sceneX.conf", O_RDONLY);
      if (w.fi.fd == -1)
	my_error(&w, "ERROR: no argument & file sceneX.conf corrupted.", -1);
    }
  my_parsing_rt(&w);
  aff_win(&w, "rt");
  close(w.fi.fd);
  return (0);
}

/*
** fonction affichage window.
*/

void	aff_win(t_wild *w, char *name)
{
  w->d.x_max = 1200;
  w->d.y_max = 710;
  w->d.w = 1;
  sound_init(w);
  (!(w->d.mlx_ptr = mlx_init())) ? my_error(w, "ERROR: mlx init.", -1) : 1;
  (!(w->d.win_ptr = mlx_new_window(w->d.mlx_ptr,
				   w->d.x_max, w->d.y_max, name))) ?
    my_error(w, "ERROR: win init.", -1) : 1;
  (!(w->d.img_ptr = mlx_new_image(w->d.mlx_ptr, w->d.x_max, w->d.y_max))) ?
    my_error(w, "ERROR: img init.", -1) : 1;
  w->d.bigData = mlx_get_data_addr(w->d.img_ptr,
				   &w->d.bpp, &w->d.sizeline, &w->d.end);
  (!(w->d.img_ptr_f = mlx_new_image(w->d.mlx_ptr, w->d.x_max, w->d.y_max))) ?
    my_error(w, "ERROR: img init.", -1) : 1;
  w->d.bigData_f = mlx_get_data_addr(w->d.img_ptr_f,
				     &w->d.bpp, &w->d.sizeline, &w->d.end);
  init_glo(w);
  mlx_expose_hook(w->d.win_ptr, &manage_expose, (void *)(w));
  mlx_hook(w->d.win_ptr, 2, 2, &manage_keyPres, (void *)(w));
  mlx_hook(w->d.win_ptr, 3, 3, &manage_keyRelease, (void *)(w));
  mlx_loop_hook(w->d.mlx_ptr, &manage_frame, (void *)(w));
  mlx_loop(w->d.mlx_ptr);
}
