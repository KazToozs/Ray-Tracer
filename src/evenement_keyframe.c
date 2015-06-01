/*
** evenement_norme.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Mar 12 13:45:12 2015 ugo belfiore
** Last update Mon Jun  1 10:13:33 2015 fernan_s
*/

#include "mini.h"

/*
** evenement frame qui s'active à chaque frame
*/

int		manage_frame(void *param)
{
  t_wild	*w;

  w = (t_wild *)param;
  manage_frame_test_key(w);
  w->d.timer++;
  if (w->d.timer > 172 && w->s[0].type == 0)
    {
      w->s[0].type++;
      w->d.timer = 9;
    }
  if (w->d.timer > 172 && w->s[0].type != 0)
    return (0);
  fast_way_only(w);
  return (0);
}

/*
** le timer augmente avec les frames, et l'algo du rt est appelé petit à petit
** la fonction "algo_rt" affiche Toute la scène en sautant 5 pixel par 5.
** pour affiche rle rt en entier, il faut rappeler cette fonction 25 fois.
*/

void	fast_way_only(t_wild *w)
{
  pthread_create(&w->threads[0], NULL, (void *)&part_one, w);
  pthread_create(&w->threads[1], NULL, (void *)&part_two, w);
  pthread_create(&w->threads[2], NULL, (void *)&part_tree, w);
  pthread_create(&w->threads[3], NULL, (void *)&part_four, w);
  pthread_create(&w->threads[4], NULL, (void *)&part_five, w);
  pthread_join(w->threads[0], NULL);
  pthread_join(w->threads[1], NULL);
  pthread_join(w->threads[2], NULL);
  pthread_join(w->threads[3], NULL);
  pthread_join(w->threads[4], NULL);
  apply_filter(w);
  mlx_put_image_to_window(w->d.mlx_ptr, w->d.win_ptr, w->d.img_ptr_f, 0, 0);
}

/*
** fonction de test dans le manage_frame SI une touche a été, ou est en train
** d'être appuyé.
*/

void	manage_frame_test_key(t_wild *w)
{
  (w->d.f[0] == 1) ? manage_key(KEY_UP, (void *)(w)) : 1;
  (w->d.f[1] == 1) ? manage_key(KEY_DOWN, (void *)(w)) : 1;
  (w->d.f[2] == 1) ? manage_key(KEY_LEFT, (void *)(w)) : 1;
  (w->d.f[3] == 1) ? manage_key(KEY_RIGHT, (void *)(w)) : 1;
  (w->d.f[4] == 1) ? manage_key(KEY_LESS, (void *)(w)) : 1;
  (w->d.f[5] == 1) ? manage_key(KEY_MORE, (void *)(w)) : 1;
  (w->d.f[6] == 1) ? manage_key(KEY_Z, (void *)(w)) : 1;
  (w->d.f[7] == 1) ? manage_key(KEY_S, (void *)(w)) : 1;
  (w->d.f[8] == 1) ? manage_key(KEY_Q, (void *)(w)) : 1;
  (w->d.f[9] == 1) ? manage_key(KEY_D, (void *)(w)) : 1;
  (w->d.f[10] == 1) ? manage_key(KEY_A, (void *)(w)) : 1;
  (w->d.f[11] == 1) ? manage_key(KEY_E, (void *)(w)) : 1;
  (w->d.f[12] == 1) ? manage_key(KEY_I, (void *)(w)) : 1;
  (w->d.f[13] == 1) ? manage_key(KEY_K, (void *)(w)) : 1;
  (w->d.f[14] == 1) ? manage_key(KEY_J, (void *)(w)) : 1;
  (w->d.f[15] == 1) ? manage_key(KEY_L, (void *)(w)) : 1;
  (w->d.f[16] == 1) ? manage_key(KEY_U, (void *)(w)) : 1;
  (w->d.f[17] == 1) ? manage_key(KEY_O, (void *)(w)) : 1;
}

/*
** evenement keyPress
** fonction active lorsque l'on appuis (ou reste appuyé) sur une touche
** ça rempli le tableau correspondant à la touche
**    (en prenant soin de pas créé de touche inverse
**     par exemple: avancer et reculer en même temps sur l'axe des X).
*/

int		manage_keyPres(int keycode, void *param)
{
  t_wild	*w;

  w = (t_wild *)param;
  w->d.f[0] = (keycode == KEY_UP && w->d.f[1] == 0) ? 1 : w->d.f[0];
  w->d.f[1] = (keycode == KEY_DOWN && w->d.f[0] == 0) ? 1 : w->d.f[1];
  w->d.f[2] = (keycode == KEY_LEFT && w->d.f[3] == 0) ? 1 : w->d.f[2];
  w->d.f[3] = (keycode == KEY_RIGHT && w->d.f[2] == 0) ? 1 : w->d.f[3];
  w->d.f[4] = (keycode == KEY_LESS && w->d.f[5] == 0) ? 1 : w->d.f[4];
  w->d.f[5] = (keycode == KEY_MORE && w->d.f[4] == 0) ? 1 : w->d.f[5];
  w->d.f[6] = (keycode == KEY_Z && w->d.f[7] == 0) ? 1 : w->d.f[6];
  w->d.f[7] = (keycode == KEY_S && w->d.f[6] == 0) ? 1 : w->d.f[7];
  w->d.f[8] = (keycode == KEY_Q && w->d.f[9] == 0) ? 1 : w->d.f[8];
  w->d.f[9] = (keycode == KEY_D && w->d.f[8] == 0) ? 1 : w->d.f[9];
  w->d.f[10] = (keycode == KEY_A && w->d.f[11] == 0) ? 1 : w->d.f[10];
  w->d.f[11] = (keycode == KEY_E && w->d.f[10] == 0) ? 1 : w->d.f[11];
  w->d.f[12] = (keycode == KEY_I && w->d.f[13] == 0) ? 1 : w->d.f[12];
  w->d.f[13] = (keycode == KEY_K && w->d.f[12] == 0) ? 1 : w->d.f[13];
  w->d.f[14] = (keycode == KEY_J && w->d.f[15] == 0) ? 1 : w->d.f[14];
  w->d.f[15] = (keycode == KEY_L && w->d.f[14] == 0) ? 1 : w->d.f[15];
  w->d.f[16] = (keycode == KEY_U && w->d.f[17] == 0) ? 1 : w->d.f[16];
  w->d.f[17] = (keycode == KEY_O && w->d.f[16] == 0) ? 1 : w->d.f[17];
  return (0);
}

/*
** fonction active lorsque l'on lache une touche
** (vide le tableau de la touche qui était resté appuyé,
**	puis appelle une fois manage_key).
*/

int		manage_keyRelease(int keycode, void *param)
{
  t_wild	*w;

  w = (t_wild *)param;
  w->d.f[0] = (keycode == KEY_UP) ? 0 : w->d.f[0];
  w->d.f[1] = (keycode == KEY_DOWN) ? 0 : w->d.f[1];
  w->d.f[2] = (keycode == KEY_LEFT) ? 0 : w->d.f[2];
  w->d.f[3] = (keycode == KEY_RIGHT) ? 0 : w->d.f[3];
  w->d.f[4] = (keycode == KEY_LESS) ? 0 : w->d.f[4];
  w->d.f[5] = (keycode == KEY_MORE) ? 0 : w->d.f[5];
  w->d.f[6] = (keycode == KEY_Z) ? 0 : w->d.f[6];
  w->d.f[7] = (keycode == KEY_S) ? 0 : w->d.f[7];
  w->d.f[8] = (keycode == KEY_Q) ? 0 : w->d.f[8];
  w->d.f[9] = (keycode == KEY_D) ? 0 : w->d.f[9];
  w->d.f[10] = (keycode == KEY_A) ? 0 : w->d.f[10];
  w->d.f[11] = (keycode == KEY_E) ? 0 : w->d.f[11];
  w->d.f[12] = (keycode == KEY_I) ? 0 : w->d.f[12];
  w->d.f[13] = (keycode == KEY_K) ? 0 : w->d.f[13];
  w->d.f[14] = (keycode == KEY_J) ? 0 : w->d.f[14];
  w->d.f[15] = (keycode == KEY_L) ? 0 : w->d.f[15];
  w->d.f[16] = (keycode == KEY_U) ? 0 : w->d.f[16];
  w->d.f[17] = (keycode == KEY_O) ? 0 : w->d.f[17];
  manage_key(keycode, (void *)(w));
  return (0);
}
