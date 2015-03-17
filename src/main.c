/*
** main.c for  in /home/belfio_u/rendu/MUL_2014_wolf3d
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Dec  5 17:23:50 2014 ugo belfiore
** Last update Tue Mar 17 08:47:14 2015 ugo belfiore
*/

#include "../include/my.h"
#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"

void     debug(t_data *d)
{
  int   i;

  printf("%d %d %d\n", d->o.view.x_eyes, d->o.view.y_eyes, d->o.view.z_eyes);
  printf("%f %f %f\n", d->o.view.rotangx, d->o.view.rotangy,d->o.view.rotangz);
  i = -1;
  while (++i < 3)
    printf("%f %f %f\n",d->o.lum.x_lum[i],d->o.lum.y_lum[i],d->o.lum.z_lum[i]);
  i = -1;
  while (++i < 3)
    printf("%d %d %d %d %d\n", d->o.sph.x_sphere[i], d->o.sph.y_sphere[i],
	   d->o.sph.z_sphere[i], d->o.sph.r_sh[i], d->o.sph.color_sphere[i]);
  i = -1;
  while (++i < 3)
    printf("%d %d %d %d %d\n", d->o.cy.x_cyl[i], d->o.cy.y_cyl[i],
	   d->o.cy.z_cyl[i], d->o.cy.r_cyl[i], d->o.cy.color_cyl[i]);
  i = -1;
  while (++i < 2)
    printf("%d %d %d %d %d\n", d->o.co.x_cone[i], d->o.co.y_cone[i],
	   d->o.co.z_cone[i], d->o.co.r_cone[i], d->o.co.color_cone[i]);
}

/*
** fonction main 
*/

int		main(int ac, char **av)
{
  extern char	**environ;	// Récupère l'environnement
  t_data	d;
  int		fd;

  ac = (ac == 2) ? ac : ac;	// pour enlever le void
  if (environ[0] == NULL)	// Quit si on fait env -i
    my_error(&d, "ERROR: environment.", -1);
  fd = open(av[1], O_RDONLY);	// ouvre le fichier en argument, s'il y a pas,
  if (fd == -1)			//	il va chercher lui même !
    {
      fd = open("./maps/scene1.conf", O_RDONLY); //en dur !
      if (fd == -1)	// si vraiment ça marche pas, fuck off
	my_error(&d, "ERROR: no argument & file 'scene1.conf' corrupted.", -1);
    }
  while ((d.fi.buff = get_next_line(fd))) // parse tout le fichier
    {
      my_fucking_parsing_rt(&d); // enregistre les variable qu'il faut
      free(d.fi.buff);		// supprime la ligne courante et next
    }
  // une fois toute les variables ok, gogo rt !
  debug(&d);
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
