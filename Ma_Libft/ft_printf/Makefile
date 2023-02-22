SRCS = ft_check.c \
	ft_putchar.c \
	ft_put_u.c \
	ft_printf.c \
	ft_put_d.c \
	ft_put_x.c \
	ft_put_c.c \
	ft_put_s.c \
	ft_put_xmaj.c \
	ft_put_p.c \

CC = gcc
CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

AR = ar rcs

RM = rm -f

all : $(NAME)
	
$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean : 
	$(RM) *.o

fclean :
	$(RM) $(NAME) *.o

re : fclean all

.PHONY : all re fclean clean
