SRCS_SERVER = server.c \

SRCS_CLIENT = client.c \

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CC = gcc

NAME = jsp

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all : $(NAME)
	@echo "test"

$(NAME) : client server

client : $(OBJS_CLIENT)
	$(CC) -o client $(OBJS_CLIENT)

server : $(OBJS_SERVER)
	$(CC) -o server $(OBJS_SERVER)

clean : 
	$(RM) *.o 
	clear
	@echo "🧚 tout propre 🧚"

fclean :
	$(RM) *.o server client
	clear
	@echo "🧚 tout propre 🧚"

git : fclean
	git add *
	git commit
	git push

re : fclean all

.PHONY : re fclean clean all
