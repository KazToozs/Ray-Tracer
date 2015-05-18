##
## Makefile for  in /home/belfio_u/rendu/MUL/MUL_2014_rtracer
## 
## Made by ugo belfiore
## Login   <belfio_u@epitech.net>
## 
## Started on  Mon May 18 11:47:58 2015 ugo belfiore
## Last update Mon May 18 14:38:30 2015 ugo belfiore
##

SRC     =       ./src/main.c			\
		./src/my_error.c		\
		./src/my_parsing_rt.c		\
		./src/my_str_to_wordtab_rt.c	\
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

OBJ     =       $(SRC:.c=.o)

NAME    =       rt

LIB     =       ./lib/my/libmy.a

LIBMINI =	./lib/minilibx/libmlx.a

CC      =       clang

CFLAGS  +=      -W -Wall -Wextra -g3
CFLAGS	+=	-I./include

LDFLAGS	=	-L/usr/lib64/X11 -lXext -lX11 -lm -Llib/my/ -lmy -Llib/minilibx/  -lmlx ./lib/libson.so -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f $(NAME)

re: fclean all
