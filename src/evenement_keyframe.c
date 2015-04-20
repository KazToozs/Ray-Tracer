/*
** evenement_norme.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Mar 12 13:45:12 2015 ugo belfiore
** Last update Mon Apr 20 09:58:18 2015 ugo belfiore
*/

#include "../lib/minilibx/mlx.h"
#include "../include/mini.h"
#include "../include/my.h"

/*
** evenement frame qui s'active à chaque frame
*/

int		manage_frame(void *param)
{
  t_data	*d;

  d = (t_data *)param;
  manage_frame_test_key(d);
  d->timer++;
  if (d->timer > 500 * 5)
    return (0);
  fast_way_only(d);
  return (0);
}

/*
** le timer augmente avec les frames, et l'algo du rt est appelé petit à petit
** la fonction "algo_rt" affiche Toute la scène en sautant 5 pixel par 5.
** pour affiche rle rt en entier, il faut rappeler cette fonction 25 fois.
*/

void	fast_way_only(t_data *d)
{
  pthread_create(&d->threads[0], NULL, (void *)&part_one, d);
  pthread_create(&d->threads[1], NULL, (void *)&part_two, d);
  pthread_create(&d->threads[2], NULL, (void *)&part_tree, d);
  pthread_create(&d->threads[3], NULL, (void *)&part_four, d);
  pthread_create(&d->threads[4], NULL, (void *)&part_five, d);
  pthread_join(d->threads[0], NULL);
  pthread_join(d->threads[1], NULL);
  pthread_join(d->threads[2], NULL);
  pthread_join(d->threads[3], NULL);
  pthread_join(d->threads[4], NULL);
}
/*
** fonction de test dans le manage_frame SI une touche a été, ou est en train
** d'être appuyé.
*/

void	manage_frame_test_key(t_data *d)
{
  (d->f[0] == 1) ? manage_key(KEY_UP, (void *)(d)) : 1;
  (d->f[1] == 1) ? manage_key(KEY_DOWN, (void *)(d)) : 1;
  (d->f[2] == 1) ? manage_key(KEY_LEFT, (void *)(d)) : 1;
  (d->f[3] == 1) ? manage_key(KEY_RIGHT, (void *)(d)) : 1;
  (d->f[4] == 1) ? manage_key(KEY_LESS, (void *)(d)) : 1;
  (d->f[5] == 1) ? manage_key(KEY_MORE, (void *)(d)) : 1;
  (d->f[6] == 1) ? manage_key(KEY_Z, (void *)(d)) : 1;
  (d->f[7] == 1) ? manage_key(KEY_S, (void *)(d)) : 1;
  (d->f[8] == 1) ? manage_key(KEY_Q, (void *)(d)) : 1;
  (d->f[9] == 1) ? manage_key(KEY_D, (void *)(d)) : 1;
  (d->f[10] == 1) ? manage_key(KEY_A, (void *)(d)) : 1;
  (d->f[11] == 1) ? manage_key(KEY_E, (void *)(d)) : 1;
  (d->f[12] == 1) ? manage_key(KEY_I, (void *)(d)) : 1;
  (d->f[13] == 1) ? manage_key(KEY_K, (void *)(d)) : 1;
  (d->f[14] == 1) ? manage_key(KEY_J, (void *)(d)) : 1;
  (d->f[15] == 1) ? manage_key(KEY_L, (void *)(d)) : 1;
  (d->f[16] == 1) ? manage_key(KEY_U, (void *)(d)) : 1;
  (d->f[17] == 1) ? manage_key(KEY_O, (void *)(d)) : 1;
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
  t_data	*d;

  d = (t_data *)param;
  d->f[0] = (keycode == KEY_UP && d->f[1] == 0) ? 1 : d->f[0];
  d->f[1] = (keycode == KEY_DOWN && d->f[0] == 0) ? 1 : d->f[1];
  d->f[2] = (keycode == KEY_LEFT && d->f[3] == 0) ? 1 : d->f[2];
  d->f[3] = (keycode == KEY_RIGHT && d->f[2] == 0) ? 1 : d->f[3];
  d->f[4] = (keycode == KEY_LESS && d->f[5] == 0) ? 1 : d->f[4];
  d->f[5] = (keycode == KEY_MORE && d->f[4] == 0) ? 1 : d->f[5];
  d->f[6] = (keycode == KEY_Z && d->f[7] == 0) ? 1 : d->f[6];
  d->f[7] = (keycode == KEY_S && d->f[6] == 0) ? 1 : d->f[7];
  d->f[8] = (keycode == KEY_Q && d->f[9] == 0) ? 1 : d->f[8];
  d->f[9] = (keycode == KEY_D && d->f[8] == 0) ? 1 : d->f[9];
  d->f[10] = (keycode == KEY_A && d->f[11] == 0) ? 1 : d->f[10];
  d->f[11] = (keycode == KEY_E && d->f[10] == 0) ? 1 : d->f[11];
  d->f[12] = (keycode == KEY_I && d->f[13] == 0) ? 1 : d->f[12];
  d->f[13] = (keycode == KEY_K && d->f[12] == 0) ? 1 : d->f[13];
  d->f[14] = (keycode == KEY_J && d->f[15] == 0) ? 1 : d->f[14];
  d->f[15] = (keycode == KEY_L && d->f[14] == 0) ? 1 : d->f[15];
  d->f[16] = (keycode == KEY_U && d->f[17] == 0) ? 1 : d->f[16];
  d->f[17] = (keycode == KEY_O && d->f[16] == 0) ? 1 : d->f[17];
  return (0);
}

/*
** fonction active lorsque l'on lache une touche
** (vide le tableau de la touche qui était resté appuyé,
**	puis appelle une fois manage_key).
*/

int		manage_keyRelease(int keycode, void *param)
{
  t_data	*d;

  d = (t_data *)param;
  d->f[0] = (keycode == KEY_UP) ? 0 : d->f[0];
  d->f[1] = (keycode == KEY_DOWN) ? 0 : d->f[1];
  d->f[2] = (keycode == KEY_LEFT) ? 0 : d->f[2];
  d->f[3] = (keycode == KEY_RIGHT) ? 0 : d->f[3];
  d->f[4] = (keycode == KEY_LESS) ? 0 : d->f[4];
  d->f[5] = (keycode == KEY_MORE) ? 0 : d->f[5];
  d->f[6] = (keycode == KEY_Z) ? 0 : d->f[6];
  d->f[7] = (keycode == KEY_S) ? 0 : d->f[7];
  d->f[8] = (keycode == KEY_Q) ? 0 : d->f[8];
  d->f[9] = (keycode == KEY_D) ? 0 : d->f[9];
  d->f[10] = (keycode == KEY_A) ? 0 : d->f[10];
  d->f[11] = (keycode == KEY_E) ? 0 : d->f[11];
  d->f[12] = (keycode == KEY_I) ? 0 : d->f[12];
  d->f[13] = (keycode == KEY_K) ? 0 : d->f[13];
  d->f[14] = (keycode == KEY_J) ? 0 : d->f[14];
  d->f[15] = (keycode == KEY_L) ? 0 : d->f[15];
  d->f[16] = (keycode == KEY_U) ? 0 : d->f[16];
  d->f[17] = (keycode == KEY_O) ? 0 : d->f[17];
  manage_key(keycode, (void *)(d));
  return (0);
}
