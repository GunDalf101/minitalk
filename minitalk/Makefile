NAME = Minitalk
CLIENT = client
SERVER = server

SRCC = client.c
SRCS =    server.c

    
#INC        =    ./inc/minitalk.h

CC            =    gcc
CFLAG        =    -Wall -Wextra -Werror
RM            =    rm -f



all:$(CLIENT) $(SERVER)

$(SERVER): $(SRCS)
    $(CC) $(CFLAGS) $(SRCS) -o $<
    

$(CLIENT): $(SRCC)
    $(CC) $(CFLAGS) $(SRCC) -o $<
