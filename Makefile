CC			= gcc

NAME		= givens.a

CFLAGS		= -Wall -Wextra -Werror -g3 -lm

INCLUDE		= include

SRC_DIR		= src

OBJ_DIR		= obj

RM			= rm -f

SOURCES =	givens.c		\
			givens_utils.c	\
			hessenberg.c	\
			main.c			\


SRC	=	$(addprefix $(SRC_DIR)/,$(SOURCES))
#$(info $$SRC is [${SRC}])
OBJS =	$(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))
#$(info $$OBJS is [${OBJS}])

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE)/givens.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re