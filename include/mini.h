/*
** mini.h for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Oct 28 09:26:37 2014 ugo belfiore
** Last update Sun May 17 01:37:06 2015 ugo belfiore
*/

#ifndef MINI_H_
#define MINI_H_

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include "fmod.h"
#include "mlx.h"
#include "my.h"

/*
** macro rtv1
*/

#define PI (3.14159265)

/*
** define: couleur en hexadécimale.
*/

#define COLOR_YELLOW 0xFFFF00
#define COLOR_BLACK 0x000000
#define COLOR_WHITE 0xFFFFFF
#define COLOR_RED 0xFF0000
#define COLOR_GREEN 0x33FF00
#define COLOR_PURPLE 0xFF00FF
#define COLOR_BLUE 0x0033FF

/*
** define: clavier.
*/

#define KEY_ENTER 65293
#define KEY_ESC 65307
#define KEY_REFRESH 65471
#define KEY_RIGHT 65363
#define KEY_LEFT 65361
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_MORE 65365
#define KEY_LESS 65366
#define KEY_A 97
#define KEY_Q 113
#define KEY_Z 122
#define KEY_S 115
#define KEY_E 101
#define KEY_D 100
#define KEY_R 114
#define KEY_F 102
#define KEY_T 116
#define KEY_G 103
#define KEY_Y 121
#define KEY_H 104
#define KEY_U 117
#define KEY_J 106
#define KEY_I 105
#define KEY_K 107
#define KEY_O 111
#define KEY_L 108
#define KEY_W 119

/*
** stucture son
*/

typedef struct	s_sound
{
  FMOD_SYSTEM	*system;
  FMOD_SOUND	*bonus1;
}		t_sound;

/*
** structure image
*/

typedef struct	s_piic
{
  void		*pros;
  int		save1;
  int		save2;
  char          *pData;
  int           bpp;
  int           size;
  int           end;
}		t_piic;

enum    SHAPE
  {
    SPHERE,
    CONE,
    CYLINDER,
    PLANE
  };

typedef struct  s_file
{
  char          *buff;
  char		**tab;
  int		fd;
}               t_file;

/*
** data: structure principale contenant les pointeurs
**	de fenêtreet d'image, contient le tableau **tab,
*/

typedef struct  s_rot
{
  int           x;
  int           y;
  int           z;
}               t_rot;

typedef struct  s_pic
{
  int           win_x;
  int           win_y;
  int           img_start_x;
  int           img_start_y;
  int           img_x;
  int           img_y;
}               t_pic;

typedef struct  s_vect
{
  double        vx;
  double        vy;
  double        vz;
}               t_vect;

typedef struct  s_pos
{
  double        x;
  double        y;
  double        z;
}               t_pos;

typedef struct  s_x
{
  double        x1;
  double        x2;
  int           red;
  int           green;
  int           blue;
  int           t;
}               t_x;

typedef struct  s_cam
{
  t_pos         p;
  t_vect        v;
  t_rot         rot;
}               t_cam;

typedef struct  s_sph
{
  t_pos         p;
  double        r;
  t_x           x;
}               t_sph;

typedef struct  s_plan
{
  double        z;
  double        k;
  int           red;
  int           green;
  int           blue;
}               t_plan;

typedef struct  s_cone
{
  t_pos         p;
  double        r;
  t_x           x;
  t_rot         rot;
}               t_cone;

typedef struct  s_cyl
{
  t_pos         p;
  double        r;
  t_x           x;
  t_rot         rot;
}               t_cyl;

typedef struct  s_int
{
  t_cam         c;
  double        k;
  int           t;
}               t_int;

typedef struct	s_data
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*bigData;
  int		x_max;
  int		y_max;
  int		colo;
  int		bpp;
  int		sizeline;
  int		end;
  int		w;
  int		f[256];
  int		timer;
}               t_data;

typedef struct  s_st
{
  t_data        d;
  t_pic         p;
  t_cam         c;
  t_sph         s;
  t_plan        pl;
  t_cone        co;
  t_cyl         cy;
  t_vect        n;
  t_int         x;
  t_cam         l;
  t_file	fi;
  t_sound	sd;
  t_piic	pi;
  pthread_t     threads[5];
}               t_st;

/*
** fonction divers.
*/

void	aff_win(t_st *st, char *name);
//void	aff_pix_img(t_st *st, int x, int y, char *img);
//void	sound_init(t_data *d);
void	my_error(t_st *s, char *error, int i);
char	*get_next_line(const int fd);
char	**my_str_to_wordtab_rt(char *str);
char	*my_strdup(char *str);

/*
** fonction evenement minilibix
*/

//int	manage_expose(void *param);
//void	check_refresh(t_data *d, int keycode);
//void    modify_key(t_data *d, int keycode);
//int	manage_frame(void *param);
//void	fast_way_only(t_data *d);
//void    manage_frame_test_key(t_data *d);
//int	manage_keyPres(int keycode, void *param);
//int	manage_keyRelease(int keycode, void *param);
//int	manage_key(int keycode, void *param);

/*
** fonction rt parsing
*/

void	my_parsing_rt(t_st *s);

/*
** fonction rt affichage
*/

//void	algo_rt(t_data *d, int flew, int flew2);
//void	rotate_x(t_data *d, double angle);
//void	rotate_y(t_data *d, double angle);
//void	rotate_z(t_data *d, double angle);
//void	my_change_color(t_data *d);
//void	move_xyz_all(t_data *d, int which, int value);
//void	part_one(t_data *d);
//void	part_two(t_data *d);
//void	part_tree(t_data *d);
//void	part_four(t_data *d);
//void	part_five(t_data *d);

#endif
