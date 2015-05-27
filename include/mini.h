/*
** mini.h for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Oct 28 09:26:37 2014 ugo belfiore
** Last update Wed May 27 05:30:18 2015 ugo belfiore
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
#define KEY_2 178

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
  char		*buff;
  char		**tab;
  int		fd;
}               t_file;

/*
** data: structure principale contenant les pointeurs
**	de fenêtreet d'image, contient le tableau **tab,
*/

typedef struct  s_rot
{
  int		x;
  int		y;
  int		z;
}		t_rot;

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
  int           color;
  int           t;
  double	coef;
}               t_x;

typedef struct  s_cam
{
  struct s_cam  *prev;
  t_pos         p;
  t_vect        v;
  t_rot         rot;
  int		r;
  int		g;
  int		b;
  int		color;
  int		type;
  int		nbr;
  struct s_cam  *next;
}               t_cam;

typedef struct  s_sph
{
  struct s_sph  *prev;
  t_pos         p;
  double        r;
  t_x           x;
  t_rot         rot;
  struct s_sph  *next;
}               t_sph;

typedef struct  s_plan
{
  struct s_plan *prev;
  double        z;
  double        k;
  double	coef;
  int           color;
  t_rot		rot;
  struct s_plan *next;
}               t_plan;

typedef struct  s_cone
{
  struct s_cone *prev;
  t_pos         p;
  double        r;
  int           high;
  t_x           x;
  t_rot         rot;
  struct s_cone *next;
}               t_cone;

typedef struct  s_cyl
{
  struct s_cyl  *prev;
  t_pos         p;
  double        r;
  int           high;
  t_x           x;
  t_rot         rot;
  struct s_cyl  *next;
}               t_cyl;

typedef struct  s_int
{
  t_cam         c;
  double        k;
  double	kk;
  int           t;
  int		color;
  double	coef;
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
  int		nb_spots;
}               t_data;

typedef struct  s_st
{
  t_data        d;
  t_pic         p;
  t_cam         c;
  t_sph         *s;
  t_plan        *pl;
  t_cone        *co;
  t_cyl         *cy;
  t_vect        n;
  t_int         x;
  t_cam         *l;
  t_file	fi;
  t_sound	sd;
  t_piic	pi;
  pthread_t     threads[5];
}               t_st;

/*
** fonction divers.
*/

void	aff_win(t_st *st, char *name);
void	aff_pix_img(t_st *st, int x, int y, char *img);
void	sound_init(t_st *s);
void	my_error(t_st *s, char *error, int i);
void	aff_error(char *str);
char	*get_next_line(const int fd);
char	**my_str_tab(char *str);
void	my_show_wordtab(char **tab);
char	*my_strdup(char *str);

/*
** fonction evenement minilibix
*/

int	manage_expose(void *param);
void	check_refresh(t_st *s, int keycode);
void    modify_key(t_st *s, int keycode);
int	manage_frame(void *param);
void	fast_way_only(t_st *s);
void    manage_frame_test_key(t_st *s);
int	manage_keyPres(int keycode, void *param);
int	manage_keyRelease(int keycode, void *param);
int	manage_key(int keycode, void *param);

/*
** fonction rt parsing
*/

void	my_parsing_rt(t_st *s);

/*
** fonction rt affichage
*/

void	algo_rt(t_st *s, int flew, int flew2);
void	my_change_color(t_st *s, double cosin, t_cam *l);
void	my_change_color_bis(t_st *s);
void	move_xyz_all(t_st *s, int which, int value);
void	part_one(t_st *s);
void	part_two(t_st *s);
void	part_tree(t_st *s);
void	part_four(t_st *s);
void	part_five(t_st *s);

/*
***************** Proto parsing **************
*/

t_sph   *my_put_sph_list(t_sph *list, t_sph remp);
t_cone  *my_put_cone_list(t_cone *list, t_cone remp);
t_cyl   *my_put_cyl_list(t_cyl *list, t_cyl remp);
t_plan  *my_put_plan_list(t_plan *list, t_plan remp);
t_cam   *my_put_light_list(t_cam *list, t_cam remp);
int     light_len(t_cam *list);
int     cone_len(t_cone *list);
int     cyl_len(t_cyl *list);
int     sphere_len(t_sph *list);
int     plan_len(t_plan *list);
void	rotate(t_rot *rot, t_cam *c);
void	rotate_inv(t_rot *rot, t_cam *c);
void	translation(t_pos *p, int x, int y, int z);
void	inverse_translation(t_pos *p, int x, int y, int z);
void	calculate_k(t_st *s);
void	inter_sphere(t_cam *c, t_sph *s);
void	inter_cone(t_cam *c, t_cone *co);
void	inter_cyl(t_cam *c, t_cyl *cy);
void	inter_plan(t_st *s, t_cam *c);
void	light(t_st *s, t_cam *l);
int	shadow(t_st *s, t_cam *l);
void	move_xyz_all(t_st *s, int which, int value);
char	*my_realloc(char *buffer, int size);
char	**my_realloc_tab(char **buffer, int size);
char    *my_strcpy(char *dest, char *src);
void	aff_all(t_st *s);

#endif
