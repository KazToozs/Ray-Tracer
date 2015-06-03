/*
** rotation.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/rotate_tests
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Mar  3 17:34:27 2015 cristopher toozs-hobson
** Last update Wed May 20 16:03:13 2015 ugo belfiore
*/

#include "mini.h"

static void	rotate_x(double *x, double *y, double *z, double a)
{
  double	mat[3][3];
  double	new_x;
  double	new_y;
  double	new_z;

  a = (a * M_PI) / 180;
  mat[0][0] = 1;
  mat[0][1] = 0;
  mat[0][2] = 0;
  mat[1][0] = 0;
  mat[1][1] = cos(a);
  mat[1][2] = -sin(a);
  mat[2][0] = 0;
  mat[2][1] = sin(a);
  mat[2][2] = cos(a);
  new_x = (mat[0][0] * (*x)) + (mat[0][1] * (*y)) + (mat[0][2] * (*z));
  new_y = (mat[1][0] * (*x)) + (mat[1][1] * (*y)) + (mat[1][2] * (*z));
  new_z = (mat[2][0] * (*x)) + (mat[2][1] * (*y)) + (mat[2][2] * (*z));
  *x = new_x;
  *y = new_y;
  *z = new_z;
}

static void	rotate_y(double *x, double *y, double *z, double a)
{
  double	mat[3][3];
  double	new_x;
  double	new_y;
  double	new_z;

  a = (a * M_PI) / 180;
  mat[0][0] = cos(a);
  mat[0][1] = 0;
  mat[0][2] = sin(a);
  mat[1][0] = 0;
  mat[1][1] = 1;
  mat[1][2] = 0;
  mat[2][0] = -(sin(a));
  mat[2][1] = 0;
  mat[2][2] = cos(a);
  new_x = (mat[0][0] * (*x)) + (mat[0][1] * (*y)) + (mat[0][2] * (*z));
  new_y = (mat[1][0] * (*x)) + (mat[1][1] * (*y)) + (mat[1][2] * (*z));
  new_z = (mat[2][0] * (*x)) + (mat[2][1] * (*y)) + (mat[2][2] * (*z));
  *x = new_x;
  *y = new_y;
  *z = new_z;
}

static void	rotate_z(double *x, double *y, double *z, double a)
{
  double	mat[3][3];
  double	new_x;
  double	new_y;
  double	new_z;

  a = (a * M_PI) / 180;
  mat[0][0] = cos(a);
  mat[0][1] = -(sin(a));
  mat[0][2] = 0;
  mat[1][0] = sin(a);
  mat[1][1] = cos(a);
  mat[1][2] = 0;
  mat[2][0] = 0;
  mat[2][1] = 0;
  mat[2][2] = 1;
  new_x = (mat[0][0] * (*x)) + (mat[0][1] * (*y)) + (mat[0][2] * (*z));
  new_y = (mat[1][0] * (*x)) + (mat[1][1] * (*y)) + (mat[1][2] * (*z));
  new_z = (mat[2][0] * (*x)) + (mat[2][1] * (*y)) + (mat[2][2] * (*z));
  *x = new_x;
  *y = new_y;
  *z = new_z;
}

void		rotate(t_rot *rot, t_cam *c)
{
  rotate_x(&c->v.vx, &c->v.vy, &c->v.vz, rot->x);
  rotate_y(&c->v.vx, &c->v.vy, &c->v.vz, rot->y);
  rotate_z(&c->v.vx, &c->v.vy, &c->v.vz, rot->z);
}

void		rotate_inv(t_rot *rot, t_cam *c)
{
  rotate_x(&c->v.vx, &c->v.vy, &c->v.vz, -rot->x);
  rotate_y(&c->v.vx, &c->v.vy, &c->v.vz, -rot->y);
  rotate_z(&c->v.vx, &c->v.vy, &c->v.vz, -rot->z);
}
