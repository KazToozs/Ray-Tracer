/*
** evenement.c for  in /home/belfio_u/rendu/Allum1
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Feb  2 18:47:55 2015 ugo belfiore
** Last update Fri May 29 14:18:22 2015 ugo belfiore
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
  //my_printf("%d ", keycode);
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
  else if (keycode == KEY_2)
    aff_all(s);
  else
    modify_key(s, keycode);
  return (0);
}

/*
** lorsu'on appuis sur une touche, modifie les variables
*/

void	modify_key(t_st *s, int keycode)
{
  (keycode == KEY_UP) ? move_xyz_all(s, 1, 150) : 1;
  (keycode == KEY_DOWN) ? move_xyz_all(s, 1, -150) : 1;
  (keycode == KEY_LEFT) ? move_xyz_all(s, 2, 150) : 1;
  (keycode == KEY_RIGHT) ? move_xyz_all(s, 2, -150) : 1;
  (keycode == KEY_MORE) ? move_xyz_all(s, 3, 150) : 1;
  (keycode == KEY_LESS) ? move_xyz_all(s, 3, -150) : 1;
  (keycode == KEY_A) ? s->c.rot.x += 5 : 1;
  (keycode == KEY_E) ? s->c.rot.x -= 5 : 1;
  (keycode == KEY_S) ? s->c.rot.y += 5 : 1;
  (keycode == KEY_Z) ? s->c.rot.y -= 5 : 1;
  (keycode == KEY_Q) ? s->c.rot.z += 5 : 1;
  (keycode == KEY_D) ? s->c.rot.z -= 5 : 1;
  (keycode == KEY_I) ? move_xyz_all(s, 4, 50) : 1;
  (keycode == KEY_K) ? move_xyz_all(s, 4, -50) : 1;
  (keycode == KEY_J) ? move_xyz_all(s, 5, 50) : 1;
  (keycode == KEY_L) ? move_xyz_all(s, 5, -50) : 1;
  (keycode == KEY_U) ? move_xyz_all(s, 6, 50) : 1;
  (keycode == KEY_O) ? move_xyz_all(s, 6, -50) : 1;
  algo_rt(s, 4, 4);
}
