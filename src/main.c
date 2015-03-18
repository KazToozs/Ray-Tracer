/*
** main.c for  in /home/belfio_u/rendu/MUL_2014_wolf3d
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Dec  5 17:23:50 2014 ugo belfiore
** Last update Wed Mar 18 15:34:14 2015 ugo belfiore
*/

#include "../include/my.h"
#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"

/*
** initialise quelque variable
*/

static void    init_fucking_rt(t_data *d)
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
  extern char	**environ;	// Récupère l'environnement
  t_data	d;

  ac = (ac == 2) ? ac : ac;	// pour enlever le void
  if (environ[0] == NULL)	// Quit si on fait env -i
    my_error(&d, "ERROR: environment.", -1);
  d.fi.fd = open(av[1], O_RDONLY);	// ouvre le fichier en argument,
  if (d.fi.fd == -1)			// (si pas d'argument, il va chercher lui même
    {				//			le fichier en dur !).
      d.fi.fd = open("./maps/scene1.conf", O_RDONLY); //en dur !
      if (d.fi.fd == -1)	// si vraiment ça marche pas, fuck off
	my_error(&d, "ERROR: no argument & file 'scene1.conf' corrupted.", -1);
    }
  my_fucking_parsing_rt(&d); // parsing + gestion d'erreur de la mort
  // une fois toute les variables ok, gogo rt !
  aff_win(&d, "rtv1");// fonction RT si t'es triste !!!
  close(d.fi.fd);
  return (0);
}

/*
** fonctin affichage window.
*/

void	aff_win(t_data *d, char *name)
{
  d->x_max = 1200;		// fenetre X
  d->y_max = 710;		// fenetre Y
  //sound_init(d);		// init le son d'ambiance (+1 point bitch)
  // toute les initialisations et gestions d'erreur
  (!(d->mlx_ptr = mlx_init())) ? my_error(d, "ERROR: mlx init.", -1) : 1;
  (!(d->win_ptr = mlx_new_window(d->mlx_ptr, d->x_max, d->y_max, name))) ?
    my_error(d, "ERROR: win init.", -1) : 1;
  (!(d->img_ptr = mlx_new_image(d->mlx_ptr, d->x_max, d->y_max))) ?
    my_error(d, "ERROR: img init.", -1) : 1;
  d->bigData = mlx_get_data_addr(d->img_ptr, &d->bpp, &d->sizeline, &d->end);
  init_fucking_rt(d); //initialise quelque variable
  // evenement (vous occupez pas de ça je gère).
  mlx_expose_hook(d->win_ptr, &manage_expose, (void *)(d));
  mlx_hook(d->win_ptr, 2, 2, &manage_keyPres, (void *)(d));
  mlx_hook(d->win_ptr, 3, 3, &manage_keyRelease, (void *)(d));
  mlx_loop_hook(d->mlx_ptr, &manage_frame, (void *)(d));
  mlx_loop(d->mlx_ptr);
  // mais ou donc est appelé l'affichage du rt ? mystère et boule de gomme.
}
