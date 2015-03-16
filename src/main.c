/*
** main.c for  in /home/belfio_u/rendu/MUL_2014_wolf3d
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Dec  5 17:23:50 2014 ugo belfiore
** Last update Mon Mar 16 17:05:08 2015 ugo belfiore
*/

#include "../include/my.h"
#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"

/*
** fonction main 
*/

int		main(int ac, char **av)
{
  extern char	**environ;	// Récupère l'environnement
  t_data	d;
  int		fd;
  int		ret;

  ac = (ac == 2) ? ac : ac;	// pour enlever le void
  if (environ[0] == NULL)	// Quit si on fait env -i
    my_error(&d, "ERROR: environment.", -1);
  fd = open(av[1], O_RDONLY);
  if (fd == -1)
    {
      fd = open("./maps/scene1.conf", O_RDONLY);
      if (fd == -1)
	my_error(&d, "ERROR: no argument & file 'scene1.conf' corrupted.", -1);
    }
  ret = read(fd, d.fi.buff, 8192000);
  if (ret == 0 || ret > 8191999)
    my_error(&d, "ERROR: empty file or file too large.", -1);
  my_fucking_parsing_rt(&d, d.fi.buff);
  //aff_win(&d, "rtv1");		// fonction qui contient les évenements. (tout)
  close(fd);
  return (0);
}

/*
** fonctin affichage window.
*/

/* void	aff_win(t_data *d, char *name) */
/* { */
/*   d->x_max = 1200;		// fenetre X */
/*   d->y_max = 710;		// fenetre Y */
/*   //sound_init(d);		// init le son d'ambiance (+1 point bitch) */
/*   // toute les initialisations et gestions d'erreur */
/*   (!(d->mlx_ptr = mlx_init())) ? my_error(d, "ERROR: mlx init.", -1) : 1; */
/*   (!(d->win_ptr = mlx_new_window(d->mlx_ptr, d->x_max, d->y_max, name))) ? */
/*     my_error(d, "ERROR: win init.", -1) : 1; */
/*   (!(d->img_ptr = mlx_new_image(d->mlx_ptr, d->x_max, d->y_max))) ? */
/*     my_error(d, "ERROR: img init.", -1) : 1; */
/*   d->bigData = mlx_get_data_addr(d->img_ptr, &d->bpp, &d->sizeline, &d->end); */
/*   parsing(d); // parsing des objets (fait une fois). */
/*   // evenement. */
/*   mlx_expose_hook(d->win_ptr, &manage_expose, (void *)(d)); */
/*   mlx_hook(d->win_ptr, 2, 2, &manage_keyPres, (void *)(d)); */
/*   mlx_hook(d->win_ptr, 3, 3, &manage_keyRelease, (void *)(d)); */
/*   mlx_loop_hook(d->mlx_ptr, &manage_frame, (void *)(d)); */
/*   mlx_loop(d->mlx_ptr); */
/* } */
