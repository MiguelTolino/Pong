CC = gcc
CFLAGS = -g -o 
CURSES = -lncurses
NAME = pong
FILES = srcs/*.c
main:
	$(CC) $(FILES) $(CURSES) $(CFLAGS) $(NAME)
