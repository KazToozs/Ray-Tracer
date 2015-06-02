/*
** evenement.c for  in /home/belfio_u/rendu/Allum1
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Feb  2 18:47:55 2015 ugo belfiore
** Last update Tue Jun  2 18:31:05 2015 ugo belfiore
*/

#include "mini.h"

/*
** evenement expose
*/

int		manage_expose(void *param)
{
  t_wild	*w;

  w = (t_wild *)param;
  mlx_put_image_to_window(w->d.mlx_ptr, w->d.win_ptr, w->d.img_ptr_f, 0, 0);
  return (0);
}

/*
** evenememnt clavier, active UNE fois lorsque l'on lache une touche.
*/

int		manage_key(int keycode, void *param)
{
  t_wild	*w;
  int		t;

  t = -1;
  w = (t_wild *)param;
  //my_printf("%d ", keycode);
  w->d.timer = 0;
  while (++t < 5)
    w->s[t].type = 0;
  if (keycode == KEY_F)
    {
      w->d.filter = (w->d.filter + 1) % 4;
      apply_filter(w);
    }
  if (keycode == KEY_ESC)
    my_error(w, "exit.", 0);
  else if (keycode == KEY_W)
    aff_all(w);
  else
    modify_key(w, keycode);
  return (0);
}

/*
** lorsu'on appuis sur une touche, modifie les variables
*/

void	rotate_key(t_wild *w, int keycode)
{
  int	t;

  t = -1;
  while (++t < 5)
    {
      (keycode == KEY_A) ? w->s[t].c.rot.x += 5 : 1;
      (keycode == KEY_E) ? w->s[t].c.rot.x -= 5 : 1;
      (keycode == KEY_S) ? w->s[t].c.rot.y += 5 : 1;
      (keycode == KEY_Z) ? w->s[t].c.rot.y -= 5 : 1;
      (keycode == KEY_Q) ? w->s[t].c.rot.z += 5 : 1;
      (keycode == KEY_D) ? w->s[t].c.rot.z -= 5 : 1;
    }
}

void	modify_key(t_wild *w, int keycode)
{
  (keycode == KEY_UP) ? move_xyz_all(w, 1, 50) : 1;
  (keycode == KEY_DOWN) ? move_xyz_all(w, 1, -50) : 1;
  (keycode == KEY_LEFT) ? move_xyz_all(w, 2, 50) : 1;
  (keycode == KEY_RIGHT) ? move_xyz_all(w, 2, -50) : 1;
  (keycode == KEY_MORE) ? move_xyz_all(w, 3, 50) : 1;
  (keycode == KEY_LESS) ? move_xyz_all(w, 3, -50) : 1;
  (keycode == KEY_I) ? move_xyz_all(w, 4, 10) : 1;
  (keycode == KEY_K) ? move_xyz_all(w, 4, -10) : 1;
  (keycode == KEY_J) ? move_xyz_all(w, 5, 10) : 1;
  (keycode == KEY_L) ? move_xyz_all(w, 5, -10) : 1;
  (keycode == KEY_U) ? move_xyz_all(w, 6, 10) : 1;
  (keycode == KEY_O) ? move_xyz_all(w, 6, -10) : 1;
  rotate_key(w, keycode);
  algo_rt(w, &w->s[0], 4, 4);
}
