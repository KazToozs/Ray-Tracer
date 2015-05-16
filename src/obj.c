/*
** obj.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Mar 12 17:26:03 2015 ugo belfiore
** Last update Sat May 16 17:00:56 2015 ugo belfiore
*/

#include "mini.h"

void		plan(t_data *d, int i)
{
  double	tmp_z;

  tmp_z = d->o.view.vz + d->o.pl.high[i];
  if (abs(tmp_z) > 0.00001)
    d->o.pl.flag = -d->o.view.z_eyes / tmp_z;
  if (d->o.pl.flag < d->k && d->o.pl.flag > 0.00001)
    {
      d->k = d->o.pl.flag;
      d->kk = PLANE;
      d->colo = COLOR_BLUE;
    }
}

void		cyl(t_data *d, int i)
{
  d->tmp_i = i;
  translate(d, d->o.cy.x_cyl[i], d->o.cy.y_cyl[i], d->o.cy.z_cyl[i]);
  d->o.cal.a = (d->o.view.vx * d->o.view.vx) + (d->o.view.vy * d->o.view.vy);
  d->o.cal.b = (2 * d->o.cy.x_cyl[i] * d->o.view.vx)
    + (2 * d->o.cy.y_cyl[i] * d->o.view.vy);
  d->o.cal.c = (d->o.cy.x_cyl[i] * d->o.cy.x_cyl[i])
    + pow(d->o.cy.y_cyl[i], 2) - (d->o.cy.r_cyl[i] * d->o.cy.r_cyl[i]);
  inv_translate(d, d->o.cy.x_cyl[i], d->o.cy.y_cyl[i], d->o.cy.z_cyl[i]);
  d->o.cal.delta = (d->o.cal.b * d->o.cal.b) - (4 * d->o.cal.a * d->o.cal.c);
  if (d->o.cal.delta >= 0)
    {
      d->o.cal.x1 = (-d->o.cal.b - sqrt(d->o.cal.delta)) / (2 * d->o.cal.a);
      d->o.cal.x2 = (-d->o.cal.b + sqrt(d->o.cal.delta)) / (2 * d->o.cal.a);
      if (d->o.cal.x1 > 0.000001 && d->o.cal.x1 < d->k &&
	  (d->o.cal.x1 < d->o.cal.x2 || d->o.cal.x2 < 0.000001))
	{
	  d->k = d->o.cal.x1;
	  d->kk = CYLINDER;
	  d->colo = COLOR_GREEN;
	}
      else if (d->o.cal.x2 > 0.000001 && d->o.cal.x2 < d->k &&
	       (d->o.cal.x2 < d->o.cal.x1 || d->o.cal.x1 < 0.000001))
	{
	  d->k = d->o.cal.x2;
	  d->kk = CYLINDER;
	  d->colo = COLOR_GREEN;
	}
    }
}

void		cone(t_data *d, int i)
{
  double	tmp_angle;

  d->tmp_i = i;
  translate(d, d->o.co.x_cone[i], d->o.co.y_cone[i], d->o.co.z_cone[i]);
  tmp_angle = (d->o.co.r_cone[i] * PI) / 180;
  d->o.cal.a = (d->o.view.vx * d->o.view.vx) + (d->o.view.vy * d->o.view.vy)
    - ((d->o.view.vz * d->o.view.vz)
       / (tan(tmp_angle) * tan(tmp_angle)));
  d->o.cal.b = (2 * d->o.co.x_cone[0] * d->o.view.vx)
    + (2 * d->o.co.y_cone[i] * d->o.view.vy)
    - (2 * d->o.co.z_cone[i] * d->o.view.vz
       / (tan(tmp_angle) * tan(tmp_angle)));
  d->o.cal.c = (d->o.co.x_cone[i] * d->o.co.x_cone[i])
    + pow(d->o.co.y_cone[i], 2) - (pow(d->o.co.z_cone[i], 2)
				   / (tan(tmp_angle) * tan(tmp_angle)));
  inv_translate(d, d->o.co.x_cone[i], d->o.co.y_cone[i], d->o.co.z_cone[i]);
  d->o.cal.delta = (d->o.cal.b * d->o.cal.b) - (4 * d->o.cal.a * d->o.cal.c);
  if (d->o.cal.delta >= 0)
    {
      d->o.cal.x1 = (-d->o.cal.b - sqrt(d->o.cal.delta)) / (2 * d->o.cal.a);
      d->o.cal.x2 = (-d->o.cal.b + sqrt(d->o.cal.delta)) / (2 * d->o.cal.a);
      if (d->o.cal.x1 > 0.000001 && d->o.cal.x1 < d->k &&
          (d->o.cal.x1 < d->o.cal.x2 || d->o.cal.x2 < 0.000001))
        {
          d->k = d->o.cal.x1;
	  d->kk = CONE;
          d->colo = COLOR_PURPLE;
        }
      else if (d->o.cal.x2 > 0.000001 && d->o.cal.x2 < d->k &&
	       (d->o.cal.x2 < d->o.cal.x1 || d->o.cal.x1 < 0.000001))
	{
	  d->k = d->o.cal.x2;
	  d->kk = CONE;
          d->colo = COLOR_PURPLE;
	}
    }
}

void		sphere(t_data *d, int i)
{
  d->tmp_i = i;
  translate(d, d->o.sph.x_sphere[i], d->o.sph.y_sphere[i], d->o.sph.z_sphere[i]);
  d->o.cal.a = (d->o.view.vx * d->o.view.vx) + (d->o.view.vy * d->o.view.vy)
    + (d->o.view.vz * d->o.view.vz);
  d->o.cal.b = (2 * d->o.sph.x_sphere[i] * d->o.view.vx)
    + (2 * d->o.sph.y_sphere[i] * d->o.view.vy)
    + (2 * d->o.sph.z_sphere[i] * d->o.view.vz);
  d->o.cal.c = (d->o.sph.x_sphere[i] * d->o.sph.x_sphere[i])
    + (d->o.sph.y_sphere[i] * d->o.sph.y_sphere[i])
    + pow(d->o.sph.z_sphere[i], 2) - (d->o.sph.r_sh[i] * d->o.sph.r_sh[i]);
  inv_translate(d, d->o.sph.x_sphere[i], d->o.sph.y_sphere[i], d->o.sph.z_sphere[i]);
  d->o.cal.delta = (d->o.cal.b * d->o.cal.b) - (4 * d->o.cal.a * d->o.cal.c);
  if (d->o.cal.delta >= 0)
    {
      d->o.cal.x1 = (-d->o.cal.b - sqrt(d->o.cal.delta)) / (2 * d->o.cal.a);
      d->o.cal.x2 = (-d->o.cal.b + sqrt(d->o.cal.delta)) / (2 * d->o.cal.a);
      if (d->o.cal.x1 > 0.000001 && d->o.cal.x1 < d->k &&
	  (d->o.cal.x1 < d->o.cal.x2 || d->o.cal.x2 < 0.000001))
	{
	  d->k = d->o.cal.x1;
	  d->kk = SPHERE;
	  d->colo = COLOR_RED;
	}
      else if (d->o.cal.x2 > 0.000001 && d->o.cal.x2 < d->k &&
	       (d->o.cal.x2 < d->o.cal.x1 || d->o.cal.x1 < 0.000001))
	{
	  d->k = d->o.cal.x2;
          d->kk = SPHERE;
          d->colo = COLOR_RED;
	}
    }
}
