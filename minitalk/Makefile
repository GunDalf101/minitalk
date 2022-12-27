
SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = minitalk.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: server.o ft_printf
	$(CC) -o $@ $< ft_printf/ft_printf.a

client: client.o ft_printf
	$(CC) -o $@ $< ft_printf/ft_printf.a

%.o: %.c
	$(CC) -c $(CFLAGS) $?

ft_printf:
	make -C ft_printf

clean:
	rm -f $(OBJECTS)
	make -C ft_printf clean
	
fclean: clean
	rm -f server client ft_printf/ft_printf.a

re: fclean all

.PHONY: all bonus ft_printf clean fclean re