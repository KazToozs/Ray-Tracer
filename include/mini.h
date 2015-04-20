/*
** mini.h for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Oct 28 09:26:37 2014 ugo belfiore
** Last update Mon Apr 20 08:23:25 2015 ugo belfiore
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
#include "fmod.h"
#include <pthread.h>

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

typedef struct	s_pic
{
  void		*pros;
  int		save1;
  int		save2;
  char          *pData;
  int           bpp;
  int           size;
  int           end;
}		t_pic;

typedef struct	s_lum
{
  double	*x_lum;
  double	*y_lum;
  double	*z_lum;
  int		check;
  double	px;
  double	py;
  double	pz;
  double	lx;
  double	ly;
  double	lz;
  double	sx;
  double	sy;
  double	sz;
  int		debug;
}		t_lum;

/*
** view (coordonnée et vercteur)
*/

typedef struct	s_view
{
  double	vx;
  double	vy;
  double	vz;
  int		x_eyes;
  int		y_eyes;
  int		z_eyes;
  double	rotangx;
  double	rotangy;
  double	rotangz;
  int		check;
  int		check2;
}		t_view;

/*
** objet plan
*/

typedef struct	s_plan
{
  int		*high;
  int		check;
  double	flag;
  int		*color_plan;
}		t_plan;

/*
** objet sphere
*/

typedef struct	s_sphere
{
  int		*x_sphere;
  int		*y_sphere;
  int		*z_sphere;
  int		*r_sh;
  int		*color_sphere;
  double	*rotx;
  double	*roty;
  double	*rotz;
  int		debug;
  int		check;
}		t_sphere;

/*
** objet cylindre
*/

typedef struct	s_cyl
{
  int		*x_cyl;
  int		*y_cyl;
  int		*z_cyl;
  int		*r_cyl;
  int		*color_cyl;
  double	*rotx;
  double	*roty;
  double	*rotz;
  int		*high;
  int		debug;
  int		check;
}		t_cyl;

/*
** objet cone
*/

typedef struct	s_cone
{
  int		*x_cone;
  int		*y_cone;
  int		*z_cone;
  int		*r_cone;
  int		*color_cone;
  double	*rotx;
  double	*roty;
  double	*rotz;
  int		*high;
  int		debug;
  int		check;
}		t_cone;

/*
** calcule intersection
*/

typedef struct	s_calc
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	x1;
  double	x2;
  double	sca;
  double	norm;
  double	norl;
  double	cosy;
}		t_calc;

/*
** structure objet du raytracer
*/

typedef struct	s_obj
{
  t_calc	cal;
  t_view	view;
  t_lum		lum;
  t_sphere	sph;
  t_plan	pl;
  t_cyl		cy;
  t_cone	co;
}		t_obj;

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
  int		f[256];
  int		timer;
  double	k;
  t_file	fi;
  t_sound	sd;
  t_pic		p;
  t_obj		o;
}               t_data;

/*
** fonction divers.
*/

void	aff_win(t_data *d, char *name);
void	aff_pix_img(t_data *d, int x, int y, char *img);
void	sound_init(t_data *d);
void	my_error(t_data *d, char *error, int i);
char	*get_next_line(const int fd);
char	**my_str_to_wordtab_rt(char *str);
char	*my_strdup(char *str);

/*
** fonction evenement minilibix
*/

int	manage_expose(void *param);
void	check_refresh(t_data *d, int keycode);
void    modify_key(t_data *d, int keycode);
int	manage_frame(void *param);
void	fast_way_only(t_data *d);
void    manage_frame_test_key(t_data *d);
int	manage_keyPres(int keycode, void *param);
int	manage_keyRelease(int keycode, void *param);
int	manage_key(int keycode, void *param);

/*
** fonction rt parsing
*/

void	my_fucking_parsing_rt(t_data *d);

/*
** fonction rt affichage
*/

void	init_sphere(t_data *d);
void	init_cyl(t_data *d);
void	init_cone(t_data *d);
void	algo_rt(t_data *d, int flew, int flew2);
void	sphere(t_data *d, int i);
void	cyl(t_data *d, int i);
void	cone(t_data *d, int i);
void	plan(t_data *d, int i);
void	rotate_x(t_data *d, double angle);
void	rotate_y(t_data *d, double angle);
void	rotate_z(t_data *d, double angle);
void	lum(t_data *d, int i);
void	my_change_color(t_data *d);

#endif
