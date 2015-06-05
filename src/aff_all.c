/*
** aff_all.c for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer/src
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Thu May 21 14:16:28 2015 ugo belfiore
** Last update Tue Jun  2 17:01:36 2015 ugo belfiore
*/

#include "mini.h"

/*
** printf dans le fichier et dans le terminale les positions caréma & rotation
*/

static void	first_print(t_wild *w, FILE *fd)
{
  fprintf(fd, "#\n# sauvegarde automatique\n# NB: color = 'FFFFFF'\n");
  fprintf(fd, "# NB: coef = [0 ; 100]\n#\n\n");
  fprintf(fd, "#\n# CAMERA-POS	x_eye	y_eye	z_eye\n");
  fprintf(fd, "# CAMERA-ROTATE	x_rot	y_rot	z_rot\n#\n\n");
  fprintf(fd, "CAMERA-POS\t%d\t%d\t%d\n",
	  (int)w->s[0].c.p.x, (int)w->s[0].c.p.y, (int)w->s[0].c.p.z);
  fprintf(fd, "CAMERA-ROTATE\t%d\t%d\t%d\n\n",
	  w->s[0].c.rot.x, w->s[0].c.rot.y, w->s[0].c.rot.z);
  printf("cam x: %.1f\ncam y: %.1f\ncam z: %.1f\n\n",
	 w->s[0].c.p.x, w->s[0].c.p.y, w->s[0].c.p.z);
  printf("cam rotx: %d\ncam roty: %d\ncam rotz: %d\n\n",
	 w->s[0].c.rot.x, w->s[0].c.rot.y, w->s[0].c.rot.z);
}

static void	light_print(t_cam *tmp_l, FILE *fd)
{
  if (tmp_l != NULL)
    fprintf(fd, "#\n# LIGHT	x_pos	y_pos	z_pos		color\n#\n\n");
  while (tmp_l != NULL)
    {
      fprintf(fd, "LIGHT\t%d\t%d\t%d\t%X\n", (int)tmp_l->p.x,
	      (int)tmp_l->p.y, (int)tmp_l->p.z, tmp_l->color);
      printf("lum x: %f\n", tmp_l->p.x);
      printf("lum y: %f\n", tmp_l->p.y);
      printf("lum z: %f\n", tmp_l->p.z);
      printf("lum color: %X\n\n", tmp_l->color);
      tmp_l = tmp_l->next;
    }
}

void		aff_all(t_wild *w)
{
  t_cone	*tmp_c;
  t_cyl		*tmp_cy;
  t_sph		*tmp_s;
  t_cam		*tmp_l;
  t_plan	*tmp_pl;
  FILE		*fd;

  tmp_c = w->s[0].co;
  tmp_cy = w->s[0].cy;
  tmp_s = w->s[0].s;
  tmp_l = w->s[0].l;
  tmp_pl = w->s[0].pl;
  fd = fopen("./maps/sceneSAVE.conf", "w+");
  first_print(w, fd);
  light_print(tmp_l, fd);
  plan_print(tmp_pl, fd);
  sphere_print(tmp_s, fd);
  cyl_print(tmp_cy, fd);
  cone_print(tmp_c, fd);
  fprintf(fd, "\n#\n# done.\n#\n");
  fclose(fd);
}
