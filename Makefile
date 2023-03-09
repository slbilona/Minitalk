SRCS_SERVER = server.c \

SRCS_CLIENT = client.c \
			index_client.c \

SRCS_SERVER_BONUS = bonus/server_bonus.c \

SRCS_CLIENT_BONUS = bonus/client_bonus.c \
				bonus/index_client_bonus.c \

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

CC = gcc

NAME = minitalk

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

LIBFT = Ma_Libft/libft.a

all : $(NAME)

$(NAME) : client server

client : $(OBJS_CLIENT)
	make -C Ma_Libft
	$(CC) $(OBJS_CLIENT) $(LIBFT) -o client 

server : $(OBJS_SERVER)
	make -C Ma_Libft
	$(CC) $(OBJS_SERVER) $(LIBFT) -o server 

bonus : $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	make -C Ma_Libft
	$(CC) $(OBJS_SERVER_BONUS) $(LIBFT) -o server_bonus
	$(CC) $(OBJS_CLIENT_BONUS) $(LIBFT) -o client_bonus 


clean : 
	make clean -C Ma_Libft
	$(RM) *.o bonus/*.o
	clear
	@echo "🧚 tout propre 🧚"

fclean :
	make fclean -C Ma_Libft
	$(RM) *.o bonus/*.o server client server_bonus client_bonus
	clear
	@echo "🧚 tout propre 🧚"

git : fclean
	git add *
	git commit
	git push

re : fclean all

.PHONY : re fclean clean all
