##
## Makefile for  in /home/belfio_u/rendu/EXOTEST/FDF
## 
## Made by ugo belfiore
## Login   <belfio_u@epitech.net>
## 
## Started on  Mon Oct 27 15:13:44 2014 ugo belfiore
## Last update Mon Apr 20 09:49:55 2015 ugo belfiore
##

SRC     =       ./src/main.c			\
		./src/my_fucking_parsing_rt.c	\
		./src/sound.c			\
		./src/thread_func.c		\
		./src/my_error.c		\
		./src/get_next_line.c		\
		./src/my_str_to_wordtab_rt.c	\
		./src/my_strdup.c		\
		./src/evenement.c		\
		./src/evenement_keyframe.c	\
		./src/parsing_change.c		\
		./src/aff_pix_img.c		\
		./src/algo_rt.c			\
		./src/obj.c			\
		./src/rotate.c			\
		./src/lum.c


OBJ     =       $(SRC:.c=.o)

NAME    =       rt

LIB     =       ./lib/my/libmy.a

LIBMINI =	./lib/minilibx/libmlx.a

CC      =       clang

CFLAGS  +=      -W -Wall -Wextra -g3

LDFLAGS	=	-L/usr/lib64/X11 -lXext -lX11 -lm -Llib/my/ -lmy -Llib/minilibx/  -lmlx ./lib/libson.so -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f $(NAME)

re: fclean all
