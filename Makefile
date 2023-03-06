SRCS_SERVER = server.c \

SRCS_CLIENT = client.c \
			index_client.c \

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CC = gcc

NAME = jsp

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

LIBFT = Ma_Libft/libft.a

all : $(NAME)

$(NAME) : client server

client : $(OBJS_CLIENT)
	make -C Ma_Libft
	$(CC) -g $(OBJS_CLIENT) $(LIBFT) -o client 

server : $(OBJS_SERVER)
	make -C Ma_Libft
	$(CC) $(OBJS_SERVER) $(LIBFT) -o server 

clean : 
	make clean -C Ma_Libft
	$(RM) *.o 
	clear
	@echo "🧚 tout propre 🧚"

fclean :
	make fclean -C Ma_Libft
	$(RM) *.o server client
	clear
	@echo "🧚 tout propre 🧚"

git : fclean
	git add *
	git commit
	git push

re : fclean all

.PHONY : re fclean clean all
