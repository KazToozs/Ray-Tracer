/*
** rotation.c for rtv1 in /home/toozs-_c/Prog_tests/rtv1/rotate_tests
** 
** Made by cristopher toozs-hobson
** Login   <toozs-_c@epitech.net>
** 
** Started on  Tue Mar  3 17:34:27 2015 cristopher toozs-hobson
** Last update Wed Jun  3 14:49:31 2015 cristopher toozs-hobson
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

void		rotate(t_rot *rot, t_vect *v, t_pos *p, int type)
{
  if (type == 3)
    {
      rotate_x(&v->vx, &v->vy, &v->vz, rot->x);
      rotate_y(&v->vx, &v->vy, &v->vz, rot->y);
      rotate_z(&v->vx, &v->vy, &v->vz, rot->z);
      rotate_x(&p->x, &p->y, &p->z, rot->x);
      rotate_y(&p->x, &p->y, &p->z, rot->y);
      rotate_z(&p->x, &p->y, &p->z, rot->z);
    }
  else if (type == 2)
    {
      rotate_x(&v->vx, &v->vy, &v->vz, rot->x);
      rotate_y(&v->vx, &v->vy, &v->vz, rot->y);
      rotate_z(&v->vx, &v->vy, &v->vz, rot->z);
    }
  else if (type == 1)
    {
      rotate_x(&p->x, &p->y, &p->z, rot->x);
      rotate_y(&p->x, &p->y, &p->z, rot->y);
      rotate_z(&p->x, &p->y, &p->z, rot->z);
    }
}

void		rotate_inv(t_rot *rot, t_vect *v, t_pos *p, int type)
{
  if (type == 3)
    {
      rotate_x(&v->vx, &v->vy, &v->vz, -rot->x);
      rotate_y(&v->vx, &v->vy, &v->vz, -rot->y);
      rotate_z(&v->vx, &v->vy, &v->vz, -rot->z);
      rotate_x(&p->x, &p->y, &p->z, -rot->x);
      rotate_y(&p->x, &p->y, &p->z, -rot->y);
      rotate_z(&p->x, &p->y, &p->z, -rot->z);
    }
  else if (type == 2)
    {
      rotate_x(&v->vx, &v->vy, &v->vz, -rot->x);
      rotate_y(&v->vx, &v->vy, &v->vz, -rot->y);
      rotate_z(&v->vx, &v->vy, &v->vz, -rot->z);
    }
  else if (type == 1)
    {
      rotate_x(&p->x, &p->y, &p->z, -rot->x);
      rotate_y(&p->x, &p->y, &p->z, -rot->y);
      rotate_z(&p->x, &p->y, &p->z, -rot->z);
    }
}
