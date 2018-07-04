##
## makefile for  in /home/coquel-l/C/libmy
## 
## Made by Coquelet Loïc
## Login   <coquel_l@etna-alternance.net>
## 
## Started on  Sat Oct 21 15:16:11 2017 Coquelet Loïc
## Last update Sat Oct 21 15:49:40 2017 Coquelet Loïc
##

CC	= gcc
NAME	= libmy.a
SRC	= my_putchar.c \
	my_isneg.c \
	my_put_nbr.c \
	my_swap.c \
	my_putstr.c \
	my_strlen.c \
	my_getnbr.c \
	my_strcpy.c \
	my_strncpy.c \
	my_strcmp.c \
	my_strncmp.c \
	my_strcat.c \
	my_strncat.c \
	my_strstr.c \
	my_strdup.c \
	my_putstrwnl.c \
	my_str_to_wordtab.c
OBJS	= $(SRC:%.c=%.o)
RM	= rm -f
CFLAGS	= -W -Wall -Werror
all	: $(NAME)
$(NAME)	: $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
clean	:
	$(RM) $(OBJS)
fclean	: clean
	$(RM) $(NAME)
.PHONY	: clean
re	: clean all
