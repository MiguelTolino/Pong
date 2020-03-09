CC = gcc
CFLAGS = -g -o 
CURSES = -lncurses
NAME = pong
FILES = *.c
main:
	$(CC) $(FILES) $(CURSES) $(CFLAGS) $(NAME)
