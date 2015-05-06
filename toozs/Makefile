##
## Makefile for rtv1 in /home/toozs-_c/Prog_tests/rtv1
## 
## Made by cristopher toozs-hobson
## Login   <toozs-_c@epitech.net>
## 
## Started on  Sun Mar  1 08:53:45 2015 cristopher toozs-hobson
## Last update Wed Mar 11 13:56:45 2015 cristopher toozs-hobson
##

SRC	=	sources/event_functions.c		\
		sources/image_functions.c		\
		sources/rotation.c			\
		sources/obj.c				\
		sources/translations.c			\
		sources/calculate_k.c			\
		sources/camera_control.c		\
		sources/light_control.c			\
		sources/initialize_objects.c		\
		sources/initialize_projectors.c		\
		sources/calculate_lighting.c		\
		sources/object_control.c		\
		sources/main.c

COMP	=	$(SRC:.c=.o)

CC	=	gcc

NAME	=	rtv1

CFLAGS	=	-W -Wall -Wextra

CFLAGS	+=	-I./include

LFLAGS	=	-L./include/ -lm -L/usr/lib64/X11 -lmlx -lXext -lX11


all: $(NAME)

$(NAME): $(COMP)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(LFLAGS);

clean:
	rm -f $(COMP)

fclean: clean
	rm -f $(NAME)

re: fclean all
