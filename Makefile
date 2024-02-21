CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra

LIBFT				=	./libs/libft.a

SRCS				= 	srcs/models/pile/*.c \
						srcs/models/*.c \
						srcs/models/pile_instruction/*.c \
						srcs/models/push_swap/*.c \
						srcs/controllers/*.c \
						srcs/controllers/parsing/*.c \
						srcs/controllers/small_algo/*.c \
						srcs/views/*.c

NAME				=	push_swap

all: $(NAME)

$(LIBFT):
	@make -C srcs/libft/

$(NAME): $(LIBFT) $(MINILIBX)
	@$(CC) -g3 -o $(NAME) $(CFLAGS) $(SRCS) -L./srcs/libs -lft;

clean:
	rm -f srcs/*/*.o srcs/*/*/*.o srcs/*/*/*/*.o

fclean: clean
	rm -f srcs/libs/*.a *.out $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean test test_v re
