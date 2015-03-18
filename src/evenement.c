/*
** evenement.c for  in /home/belfio_u/rendu/Allum1
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Feb  2 18:47:55 2015 ugo belfiore
** Last update Wed Mar 18 16:40:17 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** evenement expose
*/

int             manage_expose(void *param)
{
  t_data        *d;

  d = (t_data *)param;
  mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
  return (0);
}

/*
** evenememnt clavier, active UNE fois lorsque l'on lache une touche.
*/

int		manage_key(int keycode, void *param)
{
  t_data	*d;

  d = (t_data *)param;
  d->timer = 0;				// initialise le temps pour les frame
  if (keycode == KEY_ESC)		// echap
    my_error(d, "exit.", 0);
  else if (keycode == KEY_REFRESH)	// refresh
    my_fucking_parsing_rt(d);
  else
    modify_key(d, keycode);
  return (0);
}

/*
** lorsu'on appuis sur une touche, modifie les variables
*/

void	modify_key(t_data *d, int keycode)
{
  /* (keycode == KEY_UP) ? d->o.view.x_eyes += 50 : 1; */
  /* (keycode == KEY_DOWN) ? d->o.view.x_eyes -= 50 : 1; */
  /* (keycode == KEY_RIGHT) ? d->o.view.y_eyes -= 10 : 1; */
  /* (keycode == KEY_LEFT) ? d->o.view.y_eyes += 10 : 1; */
  /* (keycode == KEY_MORE) ? d->o.view.z_eyes -= 10 : 1; */
  /* (keycode == KEY_LESS) ? d->o.view.z_eyes += 10 : 1; */
  (keycode == KEY_A) ? d->o.view.rotangx += 5 : 1;
  (keycode == KEY_E) ? d->o.view.rotangx -= 5 : 1;
  (keycode == KEY_S) ? d->o.view.rotangy += 5 : 1;
  (keycode == KEY_Z) ? d->o.view.rotangy -= 5 : 1;
  (keycode == KEY_Q) ? d->o.view.rotangz += 5 : 1;
  (keycode == KEY_D) ? d->o.view.rotangz -= 5 : 1;
  /* init_sphere(d); */
  /* init_cyl(d); */
  /* init_cone(d); */
  algo_rt(d, 5, 0);
}
