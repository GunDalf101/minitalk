
SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)
SOURCESBNS = server_bonus.c client_bonus.c
OBJECTSBNS = $(SOURCESBNS:.c=.o)
INCLUDES = minitalk.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server_bonus client_bonus

server: server.o ft_printf
	$(CC) -o $@ $< ft_printf/ft_printf.a

client: client.o ft_printf
	$(CC) -o $@ $< ft_printf/ft_printf.a

server_bonus: server_bonus.o ft_printf
	$(CC) -o $@ $< ft_printf/ft_printf.a

client_bonus: client_bonus.o ft_printf
	$(CC) -o $@ $< ft_printf/ft_printf.a

%.o: %.c minitalk.h
	$(CC) -c $(CFLAGS) $<

ft_printf:
	make -C ft_printf

clean:
	rm -f $(OBJECTS) $(OBJECTSBNS)
	make -C ft_printf clean
	
fclean: clean
	rm -f server client server_bonus client_bonus ft_printf/ft_printf.a

re: fclean all

.PHONY: all bonus ft_printf clean fclean re