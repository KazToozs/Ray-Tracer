/*
** evenement.c for  in /home/belfio_u/rendu/Allum1
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Feb  2 18:47:55 2015 ugo belfiore
** Last update Sun May 17 02:48:19 2015 ugo belfiore
*/

#include "mini.h"

/*
** evenement expose
*/

int	manage_expose(void *param)
{
  t_st	*s;

  s = (t_st *)param;
  mlx_put_image_to_window(s->d.mlx_ptr, s->d.win_ptr, s->d.img_ptr, 0, 0);
  return (0);
}

/*
** evenememnt clavier, active UNE fois lorsque l'on lache une touche.
*/

int	manage_key(int keycode, void *param)
{
  t_st	*s;

  s = (t_st *)param;
  s->d.timer = 0;			// initialise le temps pour les frame
  if (keycode == KEY_ESC)		// echap
    my_error(s, "exit.", 0);
  else if (keycode == KEY_REFRESH)	// refresh
    {
      //free tout avant
      //my_parsing_rt(s);
    }
  else if (keycode == KEY_W)
    s->d.w *= -1;
  else
    modify_key(s, keycode);
  return (0);
}

/*
** lorsu'on appuis sur une touche, modifie les variables
*/

void	modify_key(t_st *s, int keycode)
{
  /* (keycode == KEY_UP) ? move_xyz_all(d, 1, 10) : 1; */
  /* (keycode == KEY_DOWN) ? move_xyz_all(d, 1, -10) : 1; */
  /* (keycode == KEY_LEFT) ? move_xyz_all(d, 2, 10) : 1; */
  /* (keycode == KEY_RIGHT) ? move_xyz_all(d, 2, -10) : 1; */
  /* (keycode == KEY_MORE) ? move_xyz_all(d, 3, 10) : 1; */
  /* (keycode == KEY_LESS) ? move_xyz_all(d, 3, -10) : 1; */
  /* (keycode == KEY_A) ? d->o.view.rotangx += 5 : 1; */
  /* (keycode == KEY_E) ? d->o.view.rotangx -= 5 : 1; */
  /* (keycode == KEY_S) ? d->o.view.rotangy += 5 : 1; */
  /* (keycode == KEY_Z) ? d->o.view.rotangy -= 5 : 1; */
  /* (keycode == KEY_Q) ? d->o.view.rotangz += 5 : 1; */
  /* (keycode == KEY_D) ? d->o.view.rotangz -= 5 : 1; */
  /* (keycode == KEY_I) ? move_xyz_all(d, 4, 10) : 1; */
  /* (keycode == KEY_K) ? move_xyz_all(d, 4, -10) : 1; */
  /* (keycode == KEY_J) ? move_xyz_all(d, 5, 10) : 1; */
  /* (keycode == KEY_L) ? move_xyz_all(d, 5, -10) : 1; */
  /* (keycode == KEY_U) ? move_xyz_all(d, 6, 10) : 1; */
  /* (keycode == KEY_O) ? move_xyz_all(d, 6, -10) : 1; */
  algo_rt(s, 5, 0);
}
