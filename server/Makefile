
CC			=		gcc

NAME		=		bomberman

SRC			=		bomberman.c \
					map.c \
					gameloop.c

OBJ			=		$(SRC:%.c=%.o)

LIB_DIR		=		./lib_src

LIB_NAME 	=		$(LIB_DIR)/libmy.a

#LIBMY_SRC 	=		$(LIB_DIR)/my_strcpy.c

#LIB_OBJ		=		$(LIBMY_SRC:%.c=%.o)

LDFLAGS	= -L./lib_src -lmy

RM			=		rm -f

CFLAGS		=		-W -Wall -Werror -g

$(NAME)		:	$(OBJ)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

#all			:
#				$(LIB_NAME) $(NAME)

#$(LIB_NAME) :	$(LIB_OBJ)
#				$ar -rcs $(LIB_NAME) $(LIB_OBJ)
#				ranlib $(LIB_NAME)

clean		:
				$(RM) $(OBJ)
fclean		: clean
				$(RM) $(NAME)
.PHONY		: clean
re			:		fclean $(NAME)

