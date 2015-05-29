/*
** evenement_norme.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Mar 12 13:45:12 2015 ugo belfiore
** Last update Fri May 29 13:56:17 2015 ugo belfiore
*/

#include "mini.h"

/*
** evenement frame qui s'active à chaque frame
*/

int	manage_frame(void *param)
{
  t_st	*s;

  s = (t_st *)param;
  manage_frame_test_key(s);
  s->d.timer++;
  if (s->d.timer > 500 * 5)
    return (0);
  fast_way_only(s);
  return (0);
}

/*
** le timer augmente avec les frames, et l'algo du rt est appelé petit à petit
** la fonction "algo_rt" affiche Toute la scène en sautant 5 pixel par 5.
** pour affiche rle rt en entier, il faut rappeler cette fonction 25 fois.
*/

void	fast_way_only(t_st *s)
{
  pthread_create(&s->threads[0], NULL, (void *)&part_one, s);
  pthread_create(&s->threads[1], NULL, (void *)&part_two, s);
  pthread_create(&s->threads[2], NULL, (void *)&part_tree, s);
  pthread_create(&s->threads[3], NULL, (void *)&part_four, s);
  pthread_create(&s->threads[4], NULL, (void *)&part_five, s);
  pthread_join(s->threads[0], NULL);
  pthread_join(s->threads[1], NULL);
  pthread_join(s->threads[2], NULL);
  pthread_join(s->threads[3], NULL);
  pthread_join(s->threads[4], NULL);
}

/*
** fonction de test dans le manage_frame SI une touche a été, ou est en train
** d'être appuyé.
*/

void	manage_frame_test_key(t_st *s)
{
  (s->d.f[0] == 1) ? manage_key(KEY_UP, (void *)(s)) : 1;
  (s->d.f[1] == 1) ? manage_key(KEY_DOWN, (void *)(s)) : 1;
  (s->d.f[2] == 1) ? manage_key(KEY_LEFT, (void *)(s)) : 1;
  (s->d.f[3] == 1) ? manage_key(KEY_RIGHT, (void *)(s)) : 1;
  (s->d.f[4] == 1) ? manage_key(KEY_LESS, (void *)(s)) : 1;
  (s->d.f[5] == 1) ? manage_key(KEY_MORE, (void *)(s)) : 1;
  (s->d.f[6] == 1) ? manage_key(KEY_Z, (void *)(s)) : 1;
  (s->d.f[7] == 1) ? manage_key(KEY_S, (void *)(s)) : 1;
  (s->d.f[8] == 1) ? manage_key(KEY_Q, (void *)(s)) : 1;
  (s->d.f[9] == 1) ? manage_key(KEY_D, (void *)(s)) : 1;
  (s->d.f[10] == 1) ? manage_key(KEY_A, (void *)(s)) : 1;
  (s->d.f[11] == 1) ? manage_key(KEY_E, (void *)(s)) : 1;
  (s->d.f[12] == 1) ? manage_key(KEY_I, (void *)(s)) : 1;
  (s->d.f[13] == 1) ? manage_key(KEY_K, (void *)(s)) : 1;
  (s->d.f[14] == 1) ? manage_key(KEY_J, (void *)(s)) : 1;
  (s->d.f[15] == 1) ? manage_key(KEY_L, (void *)(s)) : 1;
  (s->d.f[16] == 1) ? manage_key(KEY_U, (void *)(s)) : 1;
  (s->d.f[17] == 1) ? manage_key(KEY_O, (void *)(s)) : 1;
}

/*
** evenement keyPress
** fonction active lorsque l'on appuis (ou reste appuyé) sur une touche
** ça rempli le tableau correspondant à la touche
**    (en prenant soin de pas créé de touche inverse
**     par exemple: avancer et reculer en même temps sur l'axe des X).
*/

int	manage_keyPres(int keycode, void *param)
{
  t_st	*s;

  s = (t_st *)param;
  s->d.f[0] = (keycode == KEY_UP && s->d.f[1] == 0) ? 1 : s->d.f[0];
  s->d.f[1] = (keycode == KEY_DOWN && s->d.f[0] == 0) ? 1 : s->d.f[1];
  s->d.f[2] = (keycode == KEY_LEFT && s->d.f[3] == 0) ? 1 : s->d.f[2];
  s->d.f[3] = (keycode == KEY_RIGHT && s->d.f[2] == 0) ? 1 : s->d.f[3];
  s->d.f[4] = (keycode == KEY_LESS && s->d.f[5] == 0) ? 1 : s->d.f[4];
  s->d.f[5] = (keycode == KEY_MORE && s->d.f[4] == 0) ? 1 : s->d.f[5];
  s->d.f[6] = (keycode == KEY_Z && s->d.f[7] == 0) ? 1 : s->d.f[6];
  s->d.f[7] = (keycode == KEY_S && s->d.f[6] == 0) ? 1 : s->d.f[7];
  s->d.f[8] = (keycode == KEY_Q && s->d.f[9] == 0) ? 1 : s->d.f[8];
  s->d.f[9] = (keycode == KEY_D && s->d.f[8] == 0) ? 1 : s->d.f[9];
  s->d.f[10] = (keycode == KEY_A && s->d.f[11] == 0) ? 1 : s->d.f[10];
  s->d.f[11] = (keycode == KEY_E && s->d.f[10] == 0) ? 1 : s->d.f[11];
  s->d.f[12] = (keycode == KEY_I && s->d.f[13] == 0) ? 1 : s->d.f[12];
  s->d.f[13] = (keycode == KEY_K && s->d.f[12] == 0) ? 1 : s->d.f[13];
  s->d.f[14] = (keycode == KEY_J && s->d.f[15] == 0) ? 1 : s->d.f[14];
  s->d.f[15] = (keycode == KEY_L && s->d.f[14] == 0) ? 1 : s->d.f[15];
  s->d.f[16] = (keycode == KEY_U && s->d.f[17] == 0) ? 1 : s->d.f[16];
  s->d.f[17] = (keycode == KEY_O && s->d.f[16] == 0) ? 1 : s->d.f[17];
  return (0);
}

/*
** fonction active lorsque l'on lache une touche
** (vide le tableau de la touche qui était resté appuyé,
**	puis appelle une fois manage_key).
*/

int	manage_keyRelease(int keycode, void *param)
{
  t_st	*s;

  s = (t_st *)param;
  s->d.f[0] = (keycode == KEY_UP) ? 0 : s->d.f[0];
  s->d.f[1] = (keycode == KEY_DOWN) ? 0 : s->d.f[1];
  s->d.f[2] = (keycode == KEY_LEFT) ? 0 : s->d.f[2];
  s->d.f[3] = (keycode == KEY_RIGHT) ? 0 : s->d.f[3];
  s->d.f[4] = (keycode == KEY_LESS) ? 0 : s->d.f[4];
  s->d.f[5] = (keycode == KEY_MORE) ? 0 : s->d.f[5];
  s->d.f[6] = (keycode == KEY_Z) ? 0 : s->d.f[6];
  s->d.f[7] = (keycode == KEY_S) ? 0 : s->d.f[7];
  s->d.f[8] = (keycode == KEY_Q) ? 0 : s->d.f[8];
  s->d.f[9] = (keycode == KEY_D) ? 0 : s->d.f[9];
  s->d.f[10] = (keycode == KEY_A) ? 0 : s->d.f[10];
  s->d.f[11] = (keycode == KEY_E) ? 0 : s->d.f[11];
  s->d.f[12] = (keycode == KEY_I) ? 0 : s->d.f[12];
  s->d.f[13] = (keycode == KEY_K) ? 0 : s->d.f[13];
  s->d.f[14] = (keycode == KEY_J) ? 0 : s->d.f[14];
  s->d.f[15] = (keycode == KEY_L) ? 0 : s->d.f[15];
  s->d.f[16] = (keycode == KEY_U) ? 0 : s->d.f[16];
  s->d.f[17] = (keycode == KEY_O) ? 0 : s->d.f[17];
  manage_key(keycode, (void *)(s));
  return (0);
}
