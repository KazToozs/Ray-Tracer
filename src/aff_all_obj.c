/*
** aff_all_obj.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Jun  2 14:43:23 2015 ugo belfiore
** Last update Tue Jun  2 14:45:30 2015 ugo belfiore
*/

#include "mini.h"

void	plan_print(t_plan *tmp_pl, FILE *fd)
{
  if (tmp_pl != NULL)
    {
      fprintf(fd, "\n#\n# PLAN  high    color   ");
      fprintf(fd, "x_rot        y_rot   z_rot   coef\n#\n\n");
    }
  while (tmp_pl != NULL)
    {
      fprintf(fd, "PLAN\t%d\t%X\t%d %d %d\t%.0f\n", (int)tmp_pl->z,
              tmp_pl->color, tmp_pl->rot.x, tmp_pl->rot.y, tmp_pl->rot.z,
              tmp_pl->coef);
      printf("plan z: %f\n", tmp_pl->z);
      printf("plan color: %X\n", tmp_pl->color);
      printf("plan xrot: %d\n", tmp_pl->rot.x);
      printf("plan yrot: %d\n", tmp_pl->rot.y);
      printf("plan zrot: %d\n", tmp_pl->rot.z);
      printf("plan coef: %f\n\n", tmp_pl->coef);
      tmp_pl = tmp_pl->next;
    }
}

void	sphere_print(t_sph *tmp_s, FILE *fd)
{
  if (tmp_s != NULL)
    {
      fprintf(fd, "\n#\n# SPHERE        x_pos   y_pos   z_pos   radius");
      fprintf(fd, "     color   x_rot   y_rot   z_rot   coef\n#\n\n");
    }
  while (tmp_s != NULL)
    {
      fprintf(fd, "SPHERE\t%d %d %d\t%d\t%X\t%d %d %d\t%.0f\n",
              (int)tmp_s->p.x, (int)tmp_s->p.y, (int)tmp_s->p.z,
              (int)tmp_s->r, tmp_s->x.color, tmp_s->rot.x,
              tmp_s->rot.y, tmp_s->rot.z, tmp_s->x.coef);
      printf("sphere posx: %f\n", tmp_s->p.x);
      printf("sphere posy: %f\n", tmp_s->p.y);
      printf("sphere posz: %f\n", tmp_s->p.z);
      printf("sphere ray: %f\n", tmp_s->r);
      printf("sphere color: %X\n", tmp_s->x.color);
      printf("sphere rotx: %d\n", tmp_s->rot.x);
      printf("sphere roty: %d\n", tmp_s->rot.y);
      printf("sphere rotz: %d\n", tmp_s->rot.z);
      printf("sphere coef: %f\n\n", tmp_s->x.coef);
      tmp_s = tmp_s->next;
    }
}

void	cyl_print(t_cyl *tmp_cy, FILE *fd)
{
  if (tmp_cy != NULL)
    {
      fprintf(fd, "\n#\n# CYLINDER      x_pos   y_pos   z_pos   radius");
      fprintf(fd, "     color   x_rot   y_rot   z_rot   high    coef\n#\n\n");
    }
  while (tmp_cy != NULL)
    {
      fprintf(fd, "CYLINDER\t%d %d %d\t%d\t%X\t%d %d %d\t%d\t%.0f\n",
              (int)tmp_cy->p.x, (int)tmp_cy->p.y, (int)tmp_cy->p.z,
              (int)tmp_cy->r, tmp_cy->x.color, tmp_cy->rot.x, tmp_cy->rot.y,
              tmp_cy->rot.z, tmp_cy->high, tmp_cy->x.coef);
      printf("cyl posx: %f\n", tmp_cy->p.x);
      printf("cyl posy: %f\n", tmp_cy->p.y);
      printf("cyl posz: %f\n", tmp_cy->p.z);
      printf("cyl ray: %f\n", tmp_cy->r);
      printf("cyl color: %X\n", tmp_cy->x.color);
      printf("cyl rotx: %d\n", tmp_cy->rot.x);
      printf("cyl roty: %d\n", tmp_cy->rot.y);
      printf("cyl rotz: %d\n", tmp_cy->rot.z);
      printf("cyl high: %d\n", tmp_cy->high);
      printf("cyl coef: %f\n\n", tmp_cy->x.coef);
      tmp_cy = tmp_cy->next;
    }
}

void	cone_print(t_cone *tmp_c, FILE *fd)
{
  if (tmp_c != NULL)
    {
      fprintf(fd, "\n#\n# CONE          x_pos   y_pos   z_pos   radius");
      fprintf(fd, "     color   x_rot   y_rot   z_rot   high    coef\n#\n\n");
    }
  while (tmp_c != NULL)
    {
      fprintf(fd, "CONE\t%d %d %d\t%d\t%X\t%d %d %d\t%d\t%.0f\n",
              (int)tmp_c->p.x, (int)tmp_c->p.y, (int)tmp_c->p.z,
              (int)tmp_c->r, tmp_c->x.color, tmp_c->rot.x, tmp_c->rot.y,
              tmp_c->rot.z, tmp_c->high, tmp_c->x.coef);
      printf("cone posx: %f\n", tmp_c->p.x);
      printf("cone posy: %f\n", tmp_c->p.y);
      printf("cone posz: %f\n", tmp_c->p.z);
      printf("cone ray: %f\n", tmp_c->r);
      printf("cone high: %d\n", tmp_c->high);
      printf("cone color: %X\n", tmp_c->x.color);
      printf("cone rotx: %d\n", tmp_c->rot.x);
      printf("cone roty: %d\n", tmp_c->rot.y);
      printf("cone rotz: %d\n", tmp_c->rot.z);
      printf("cone coef: %f\n\n", tmp_c->x.coef);
      tmp_c = tmp_c->next;
    }
}
