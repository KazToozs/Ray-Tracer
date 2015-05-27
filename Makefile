##
## Makefile for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer
## 
## Made by ugo belfiore
## Login   <belfio_u@epitech.net>
## 
## Started on  Mon May 18 11:47:58 2015 ugo belfiore
## Last update Wed May 27 09:55:03 2015 pallua_j
##

SRC     =       ./src/main.c			\
		./src/my_error.c		\
		./src/my_parsing_rt.c		\
		./src/my_str_to_wordtab_rt.c	\
		./src/my_show_wordtab.c		\
		./src/get_next_line.c		\
		./src/sound.c			\
		./src/evenement.c		\
		./src/evenement_keyframe.c	\
		./src/thread_func.c		\
		./src/algo_rt.c			\
		./src/aff_pix_img.c		\
		./src/my_obj_list.c		\
		./src/my_change_color.c		\
		./src/rotation.c		\
		./src/obj.c			\
		./src/translations.c		\
		./src/calculate_k.c		\
		./src/lum.c			\
		./src/shadow.c			\
		./src/move_xyz_all.c		\
		./src/my_realloc.c		\
		./src/my_strcpy.c		\
		./src/my_strdup.c		\
		./src/aff_all.c			\

OBJ     =       $(SRC:.c=.o)

NAME    =       rt

LIB     =       -L./lib/my -lmy

LIBMINI =	-L./lib/minilibx -lmlx

CC      =       gcc

CFLAGS  +=      -W -Wall -Wextra -g3
CFLAGS	+=	-I./include

LDFLAGS	=	$(LIB) $(LIBMINI) -L/usr/lib64/X11 -lXext -lX11 -lm ./lib/libson.so -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f $(NAME)

re: fclean all
