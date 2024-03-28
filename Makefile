CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra

LIBFT				=	./libft/libft.a

PATH_CONTROLLERS	=	./srcs/controllers
PATH_MODELS			=	./srcs/models
PATH_VIEWS			=	./srcs/views

SRCS				=	$(PATH_CONTROLLERS)/main.c \
						$(PATH_CONTROLLERS)/big_algo.c \
						$(PATH_CONTROLLERS)/parsing.c \
						$(PATH_CONTROLLERS)/small_algo.c \
\
						$(PATH_MODELS)/algo/algo_utils.c \
						$(PATH_MODELS)/algo/get_ins_nb.c \
						$(PATH_MODELS)/algo/get_target.c \
						$(PATH_MODELS)/algo/ins_utils.c \
						$(PATH_MODELS)/pile/pile_addback.c \
						$(PATH_MODELS)/pile/pile_already_in.c \
						$(PATH_MODELS)/pile/pile_free.c \
						$(PATH_MODELS)/pile/pile_getpos.c \
						$(PATH_MODELS)/pile/pile_issort.c \
						$(PATH_MODELS)/pile/pile_new.c \
						$(PATH_MODELS)/pile/pile_size.c \
						$(PATH_MODELS)/pile_instruction/pile_push.c \
						$(PATH_MODELS)/pile_instruction/pile_reverse_rotate.c \
						$(PATH_MODELS)/pile_instruction/pile_rotate.c \
						$(PATH_MODELS)/pile_instruction/pile_swap.c \
						$(PATH_MODELS)/push_swap/push_swap_free.c \
						$(PATH_MODELS)/push_swap/push_swap_new.c \
						$(PATH_MODELS)/push_swap/push_swap_set_size.c \
						$(PATH_MODELS)/sort_list.c \
\
						$(PATH_VIEWS)/print_error.c \
						$(PATH_VIEWS)/sort_show.c

NAME				=	push_swap

all: $(NAME)

$(LIBFT):
	@make -C srcs/libft/

$(NAME): $(LIBFT)
	@$(CC) -g3 -o $(NAME) $(CFLAGS) $(SRCS) -L./srcs/libft -lft;

clean:
	rm -f ./srcs/models/*.o ./srcs/models/*/*.o ./srcs/controllers/*.o ./srcs/views/*.o 

fclean: clean
	make -C ./srcs/libft/ fclean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
