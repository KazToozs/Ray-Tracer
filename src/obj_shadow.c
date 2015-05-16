/*
** obj.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtv1/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu Mar 12 17:26:03 2015 ugo belfiore
** Last update Sat May 16 16:56:33 2015 ugo belfiore
*/

#include "mini.h"

void		plan_shadow(t_data *d, int i)
{
  double	tmp_z;

  tmp_z = d->o.lum.lz[i] + d->o.pl.high[i];
  if (abs(tmp_z) > 0.00001)
    d->o.pl.flag = -d->o.lum.pz[i] / tmp_z;
  if (d->o.pl.flag < d->k && d->o.pl.flag > 0.000001)
    {
      d->k = d->o.pl.flag;
      d->kk = PLANE;
    }
}

void		cyl_shadow(t_data *d, int i)
{
  d->tmp_i = i;
  translate_shad(d, d->o.cy.x_cyl[i], d->o.cy.y_cyl[i], d->o.cy.z_cyl[i]);
  d->o.cal.a = (d->o.lum.lx[i] * d->o.lum.lx[i]) + (d->o.lum.ly[i] * d->o.lum.ly[i]);
  d->o.cal.b = (2 * d->o.cy.x_cyl[i] * d->o.lum.lx[i])
    + (2 * d->o.cy.y_cyl[i] * d->o.lum.ly[i]);
  d->o.cal.c = (d->o.cy.x_cyl[i] * d->o.cy.x_cyl[i])
    + pow(d->o.cy.y_cyl[i], 2) - (d->o.cy.r_cyl[i] * d->o.cy.r_cyl[i]);
  inv_translate_shad(d, d->o.cy.x_cyl[i], d->o.cy.y_cyl[i], d->o.cy.z_cyl[i]);
  d->o.cal.delta = (d->o.cal.b * d->o.cal.b) - (4 * d->o.cal.a * d->o.cal.c);
  if (d->o.cal.delta >= 0)
    {
      d->o.cal.x1 = (-d->o.cal.b - sqrt(d->o.cal.delta)) / (2 * d->o.cal.a);
      d->o.cal.x2 = (-d->o.cal.b + sqrt(d->o.cal.delta)) / (2 * d->o.cal.a);
      if ((d->o.cal.x1 < d->o.cal.x2)
          && (d->o.cal.x1 < d->k) && (d->o.cal.x1 > 0.000001)
          && (d->o.cal.x2 < 1))
        {
	  d->k = d->o.cal.x1;
	  d->kk = CYLINDER;
        }
      else if ((d->o.cal.x2 < d->o.cal.x1)
               && (d->o.cal.x2 < d->k) && (d->o.cal.x2 > 0.000001)
               && (d->o.cal.x1 < 1))
        {
	  d->k = d->o.cal.x2;
	  d->kk = CYLINDER;
        }
    }
}

void		cone_shadow(t_data *d, int i)
{
  double	tmp_angle;

  d->tmp_i = i;
  translate_shad(d, d->o.co.x_cone[i], d->o.co.y_cone[i], d->o.co.z_cone[i]);
  tmp_angle = (d->o.co.r_cone[i] * PI) / 180;
  d->o.cal.a = (d->o.lum.lx[i] * d->o.lum.lx[i]) + (d->o.lum.ly[i] * d->o.lum.ly[i])
    - ((d->o.lum.lz[i] * d->o.lum.lz[i])
       / (tan(tmp_angle) * tan(tmp_angle)));
  d->o.cal.b = (2 * d->o.co.x_cone[0] * d->o.lum.lx[i])
    + (2 * d->o.co.y_cone[i] * d->o.lum.ly[i])
    - (2 * d->o.co.z_cone[i] * d->o.lum.lz[i]
       / (tan(tmp_angle) * tan(tmp_angle)));
  d->o.cal.c = (d->o.co.x_cone[i] * d->o.co.x_cone[i])
    + pow(d->o.co.y_cone[i], 2) - (pow(d->o.co.z_cone[i], 2)
				   / (tan(tmp_angle) * tan(tmp_angle)));
  inv_translate_shad(d, d->o.co.x_cone[i], d->o.co.y_cone[i], d->o.co.z_cone[i]);
  d->o.cal.delta = (d->o.cal.b * d->o.cal.b) - (4 * d->o.cal.a * d->o.cal.c);
  if (d->o.cal.delta >= 0)
    {
      d->o.cal.x1 = (-d->o.cal.b - sqrt(d->o.cal.delta)) / (2 * d->o.cal.a);
      d->o.cal.x2 = (-d->o.cal.b + sqrt(d->o.cal.delta)) / (2 * d->o.cal.a);
      if ((d->o.cal.x1 < d->o.cal.x2)
          && (d->o.cal.x1 < d->k) && (d->o.cal.x1 > 0.000001)
          && (d->o.cal.x2 < 1))
        {
          d->k = d->o.cal.x1;
	  d->kk = CONE;
        }
      else if ((d->o.cal.x2 < d->o.cal.x1)
               && (d->o.cal.x2 < d->k) && (d->o.cal.x2 > 0.000001)
               && (d->o.cal.x1 < 1))
        {
          d->k = d->o.cal.x2;
          d->kk = CONE;
        }
    }
}

void		sphere_shadow(t_data *d, int i)
{
  d->tmp_i = i;
  translate_shad(d, d->o.sph.x_sphere[i], d->o.sph.y_sphere[i], d->o.sph.z_sphere[i]);
  d->o.cal.a = (d->o.lum.lx[i] * d->o.lum.lx[i]) + (d->o.lum.ly[i] * d->o.lum.ly[i])
    + (d->o.lum.lz[i] * d->o.lum.lz[i]);
  d->o.cal.b = (2 * d->o.sph.x_sphere[i] * d->o.lum.lx[i])
    + (2 * d->o.sph.y_sphere[i] * d->o.lum.ly[i])
    + (2 * d->o.sph.z_sphere[i] * d->o.lum.lz[i]);
  d->o.cal.c = (d->o.sph.x_sphere[i] * d->o.sph.x_sphere[i])
    + (d->o.sph.y_sphere[i] * d->o.sph.y_sphere[i])
    + pow(d->o.sph.z_sphere[i], 2) - (d->o.sph.r_sh[i] * d->o.sph.r_sh[i]);
  inv_translate_shad(d, d->o.sph.x_sphere[i], d->o.sph.y_sphere[i], d->o.sph.z_sphere[i]);
  d->o.cal.delta = (d->o.cal.b * d->o.cal.b) - (4 * d->o.cal.a * d->o.cal.c);
  if (d->o.cal.delta >= 0)
    {
      d->o.cal.x1 = (-d->o.cal.b - sqrt(d->o.cal.delta)) / (2 * d->o.cal.a);
      d->o.cal.x2 = (-d->o.cal.b + sqrt(d->o.cal.delta)) / (2 * d->o.cal.a);
      if ((d->o.cal.x1 < d->o.cal.x2)
	  && (d->o.cal.x1 < d->k) && (d->o.cal.x1 > 0.000001)
	  && (d->o.cal.x2 < 1))
	{
	  d->k = d->o.cal.x1;
	  d->kk = SPHERE;
	}
      else if ((d->o.cal.x2 < d->o.cal.x1)
	       && (d->o.cal.x2 < d->k) && (d->o.cal.x2 > 0.000001)
	       && (d->o.cal.x1 < 1))
	{
	  d->k = d->o.cal.x2;
	  d->kk = SPHERE;
	}
    }
}
