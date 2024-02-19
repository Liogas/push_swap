CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror  

SRCS		=	ft_char/ft_isalpha.c \
				ft_char/ft_isdigit.c \
				ft_char/ft_isalnum.c \
				ft_char/ft_isascii.c \
				ft_char/ft_isprint.c \
				ft_char/ft_toupper.c \
				ft_char/ft_tolower.c \
\
				ft_mem/ft_memset.c \
				ft_mem/ft_bzero.c \
				ft_mem/ft_memcpy.c \
				ft_mem/ft_memmove.c \
				ft_mem/ft_memchr.c \
				ft_mem/ft_memcmp.c \
\
				ft_str/ft_strlcpy.c \
				ft_str/ft_strlcat.c \
				ft_str/ft_strlen.c \
				ft_str/ft_strchr.c \
				ft_str/ft_strrchr.c \
				ft_str/ft_strncmp.c \
				ft_str/ft_strcmp.c \
				ft_str/ft_strnstr.c \
				ft_str/ft_strupper.c \
				ft_str/ft_strdup.c \
				ft_str/ft_strndup.c \
				ft_str/ft_substr.c \
				ft_str/ft_strjoin.c \
				ft_str/ft_constr.c \
				ft_str/ft_strtrim.c \
				ft_str/ft_split.c \
				ft_str/ft_strmapi.c \
				ft_str/ft_striteri.c \
\
				ft_conv/ft_atoi.c \
				ft_conv/ft_itoa.c \
				ft_conv/ft_utoa.c \
				ft_conv/ft_ptoa.c \
				ft_conv/ft_itoa_hex.c \
\
				ft_put/ft_putchar_fd.c \
				ft_put/ft_putstr_fd.c \
				ft_put/ft_putendl_fd.c \
				ft_put/ft_putnbr_fd.c \
				ft_put/ft_putnbr_u_fd.c \
				ft_put/ft_putnbr_hex_fd.c \
				ft_put/ft_putptr_hex_fd.c \
\
				ft_lst/ft_lstnew.c \
				ft_lst/ft_lstadd_front.c \
				ft_lst/ft_lstsize.c \
				ft_lst/ft_lstlast.c \
				ft_lst/ft_lstadd_back.c \
				ft_lst/ft_lstdelone.c \
				ft_lst/ft_lstclear.c \
				ft_lst/ft_lstiter.c \
				ft_lst/ft_lstmap.c \
\
				ft_alloc/ft_calloc.c 
OBJS		=	$(SRCS:.c=.o)

NAME		=	libft.a
AR			=	ar -rcsv

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $^

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	mv ./libft.a ../libs/libft.a

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
