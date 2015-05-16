/*
** rotate.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Wed Mar  4 14:47:44 2015 ugo belfiore
** Last update Sun May 17 00:56:04 2015 ugo belfiore
*/

#include "mini.h"

/* void		rotate_x(t_data *d, double angle) */
/* { */
/*   double	mat[3][3]; */
/*   double	tmp_x; */
/*   double	tmp_y; */

/*   tmp_x = d->o.view.vx; */
/*   tmp_y = d->o.view.vy; */
/*   angle = (angle * PI) / 180; */
/*   mat[0][0] = 1; */
/*   mat[0][1] = 0; */
/*   mat[0][2] = 0; */
/*   mat[1][0] = 0; */
/*   mat[1][1] = cos(angle); */
/*   mat[1][2] = -sin(angle); */
/*   mat[2][0] = 0; */
/*   mat[2][1] = sin(angle); */
/*   mat[2][2] = cos(angle); */
/*   d->o.view.vx = (tmp_x * mat[0][0]) + (tmp_y * mat[0][1]) */
/*     + (d->o.view.vz * mat[0][2]); */
/*   d->o.view.vy = (tmp_x * mat[1][0]) + (tmp_y * mat[1][1]) */
/*     + (d->o.view.vz * mat[1][2]); */
/*   d->o.view.vz = (tmp_x * mat[2][0]) + (tmp_y * mat[2][1]) */
/*     + (d->o.view.vz * mat[2][2]); */
/* } */

/* void	rotate_y(t_data *d, double angle) */
/* { */
/*   double	mat[3][3]; */
/*   double	tmp_x; */
/*   double	tmp_y; */

/*   tmp_x = d->o.view.vx; */
/*   tmp_y = d->o.view.vy; */
/*   angle = (angle * PI) / 180; */
/*   mat[0][0] = cos(angle); */
/*   mat[0][1] = 0; */
/*   mat[0][2] = sin(angle); */
/*   mat[1][0] = 0; */
/*   mat[1][1] = 1; */
/*   mat[1][2] = 0; */
/*   mat[2][0] = -sin(angle); */
/*   mat[2][1] = 0; */
/*   mat[2][2] = cos(angle); */
/*   d->o.view.vx = (tmp_x * mat[0][0]) + (tmp_y * mat[0][1]) */
/*     + (d->o.view.vz * mat[0][2]); */
/*   d->o.view.vy = (tmp_x * mat[1][0]) + (tmp_y * mat[1][1]) */
/*     + (d->o.view.vz * mat[1][2]); */
/*   d->o.view.vz = (tmp_x * mat[2][0]) + (tmp_y * mat[2][1]) */
/*     + (d->o.view.vz * mat[2][2]); */
/* } */

/* void	rotate_z(t_data *d, double angle) */
/* { */
/*   double	mat[3][3]; */
/*   double	tmp_x; */
/*   double	tmp_y; */

/*   tmp_x = d->o.view.vx; */
/*   tmp_y = d->o.view.vy; */
/*   angle = (angle * PI) / 180; */
/*   mat[0][0] = cos(angle); */
/*   mat[0][1] = -sin(angle); */
/*   mat[0][2] = 0; */
/*   mat[1][0] = sin(angle); */
/*   mat[1][1] = cos(angle); */
/*   mat[1][2] = 0; */
/*   mat[2][0] = 0; */
/*   mat[2][1] = 0; */
/*   mat[2][2] = 1; */
/*   d->o.view.vx = (tmp_x * mat[0][0]) + (tmp_y * mat[0][1]) */
/*     + (d->o.view.vz * mat[0][2]); */
/*   d->o.view.vy = (tmp_x * mat[1][0]) + (tmp_y * mat[1][1]) */
/*     + (d->o.view.vz * mat[1][2]); */
/*   d->o.view.vz = (tmp_x * mat[2][0]) + (tmp_y * mat[2][1]) */
/*     + (d->o.view.vz * mat[2][2]); */
/* } */
