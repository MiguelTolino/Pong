CC = gcc
CFLAGS = -g -o 
NAME = pong
FILES = fill_campo.c pong.c print_campo.c gameloop.c 
main:
	$(CC) $(FILES) $(CFLAGS) $(NAME)
