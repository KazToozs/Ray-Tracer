/*
** wolf3D.h for wolf3D in /home/toozs-_c/ProgElem_test/wolf_3D/include
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Thu Dec 11 09:39:36 2014 cristopher toozs-hobson
** Last update Thu Mar 12 11:07:08 2015 cristopher toozs-hobson
*/

#ifndef RT_H_
#define RT_H_

enum	SHAPE
  {
    SPHERE,
    CONE,
    CYLINDER,
    PLANE
  };

typedef struct	s_data
{
  void		*mlx_pt;
  void		*img_pt;
  void		*win_pt;
  char		*d;
  int		end;
  int		line;
  int		bpp;
  int		red;
  int		green;
  int		blue;
}		t_data;

typedef struct	s_rot
{
  int		x;
  int		y;
  int		z;
}		t_rot;

typedef struct	s_pic
{
  int		win_x;
  int		win_y;
  int		img_start_x;
  int		img_start_y;
  int		img_x;
  int		img_y;
}		t_pic;

typedef struct	s_vect
{
  double	vx;
  double	vy;
  double	vz;
}		t_vect;

typedef struct	s_pos
{
  double	x;
  double	y;
  double	z;
}		t_pos;

typedef struct	s_x
{
  double	x1;
  double	x2;
  int		red;
  int		green;
  int		blue;
  int		t;
}		t_x;

typedef struct	s_cam
{
  t_pos		p;
  t_vect	v;
  t_rot		rot;
}		t_cam;

typedef struct	s_sph
{
  t_pos		p;
  double	r;
  t_x		x;
}		t_sph;

typedef struct	s_plan
{
  double       	z;
  double	k;
  int		red;
  int		green;
  int		blue;
}		t_plan;

typedef struct	s_cone
{
  t_pos		p;
  double	r;
  t_x		x;
  t_rot		rot;
}		t_cone;

typedef struct	s_cyl
{
  t_pos		p;
  double	r;
  t_x		x;
  t_rot		rot;
}		t_cyl;

typedef struct	s_int
{
  t_cam		c;
  double	k;
  int		t;
}		t_int;

typedef struct	s_st
{
  t_data	d;
  t_pic		p;
  t_cam		c;
  t_sph		s;
  t_plan	pl;
  t_cone	co;
  t_cyl		cy;
  t_vect       	n;
  t_int		x;
  t_cam		l;
}		t_st;

void		calculate_pixels(t_st *s);
void		inter_plan(t_st *s, t_cam *c);
void		inter_cyl(t_cam *c, t_cyl *cy);
void		inter_sphere(t_cam *c, t_sph *s);
void		inter_cone(t_cam *c, t_cone *co);
void		translation(t_pos *p, int x, int y, int z);
void		inverse_translation(t_pos *p, int x, int y, int z);
int		shadow_k(t_st *s);
void		camera_control(t_st *s, int keycode);
void		light_control(t_st *s, int keycode);
void		init_cam(t_st *s);
void		init_lit(t_st *s);
void		init_sphere(t_st *s);
void		init_plan(t_st *s);
void		init_cone(t_st *s);
void		init_cyl(t_st *s);
void		manage_events(t_st *strct);
void            put_pixel(int pos_x, int pos_y, t_data *d, t_pic p);
void		light(t_st *s);
void		calculate_k(t_st *s);
void		sphere_control(t_st *s, int keycode);
void		cylinder_control(t_st *s, int keycode);
void		cone_control(t_st *s, int keycode);
void		rotate(t_rot *ror, t_cam *c);
void		inverse_rotate(t_rot *ror, t_cam *c);

#endif
