CC = gcc
CFLAGS = -g -o 
CURSES = -lncurses
NAME = pong
FILES = print_game.c pong.c init_window.c gameloop.c 
main:
	$(CC) $(FILES) $(CURSES) $(CFLAGS) $(NAME)
