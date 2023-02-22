SRCS = ft_memset.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_putchar_fd.c \
	ft_bzero.c \
	ft_putendl_fd.c \
	ft_strrchr.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_putstr_fd.c \
	ft_substr.c \
	ft_isalpha.c \
	ft_split.c \
	ft_tolower.c \
	ft_isascii.c \
	ft_strchr.c \
	ft_toupper.c \
	ft_isdigit.c \
	ft_strdup.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strlcpy.c \
	ft_itoa.c \
	ft_putnbr_fd.c \
	ft_strnstr.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strtrim.c \
	ft_memmove.c \
	ft_striteri.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \

CC = gcc
CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

AR = ar rcs

RM = rm -f

NAME = libft.a

all: $(NAME)

$(NAME) : $(OBJS)
	make -C ft_printf
	$(AR) $(NAME) $(OBJS)

clean :
	make clean -C ft_printf
	$(RM) *.o get_next_line/*.o

fclean :
	make fclean -C ft_printf
	$(RM) $(NAME) *.o get_next_line/*.o

re : fclean all

git : fclean
	git add *
	git commit
	git push

.PHONY : all re clean fclean git
