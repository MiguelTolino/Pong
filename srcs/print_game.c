/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:13:01 by miguel            #+#    #+#             */
/*   Updated: 2020/03/10 00:39:34 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

void print_line()
{
    int i;

    i = 0;

    while (i < V)
    {
        mvwprintw(win, i, H / 2, "|");
        i++;
    }
    
}

void print_raqueta1(pong *var)
{
    int i;
    int j;

    i = var->posjugx1;
    while (i < var->posfinaljugx1)
    {
        j = var->posjugy1;
        while (j < var->posfinaljugy1)
        {
            wattron(win,A_REVERSE | COLOR_PAIR(1));
            mvwprintw(win, i, j, "%c", ' ');
            wattroff(win,A_REVERSE | COLOR_PAIR(1));
            j++;
        }
        i++;
    }
}

void print_raqueta2(pong *var)
{
    int i;
    int j;

    i = var->posjugx2;
    j = var->posjugy2;
    while (i < var->posfinaljugx2)
    {
        j = var->posjugy2;
        while (j < var->posfinaljugy2)
        {
            wattron(win,A_REVERSE | COLOR_PAIR(3));
            mvwprintw(win, i, j, "%c", ' ');
            wattroff(win,A_REVERSE | COLOR_PAIR(3));
            j++;
        }
        i++;
    }
}

void print_pelota(pong *var)
{
    wattron(win, A_BOLD);
    mvwprintw(win, var->pelx, var->pely, "%c", 'O');
    wattroff(win, A_BOLD);
    wrefresh(win);
}

void print_score(pong *var)
{
    wattron(stdscr, A_BOLD);
    mvwprintw(stdscr, 4,45, "SCORE");

    wattron(stdscr, A_BOLD | COLOR_PAIR(1));
    mvwprintw(stdscr, 5, 15, "PLAYER 1: ", var->gol.player1);
    wattron(stdscr, A_REVERSE);
    wprintw(stdscr, "%i", var->gol.player1);
    wattroff(stdscr, A_BOLD | COLOR_PAIR(1) | A_REVERSE);

    wattron(stdscr, A_BOLD | COLOR_PAIR(3));
    mvwprintw(stdscr, 5, 75, "PLAYER 2: ", var->gol.player2);
    wattron(stdscr, A_REVERSE);
    wprintw(stdscr, "%i", var->gol.player2);
    wattroff(stdscr, A_BOLD | COLOR_PAIR(3) | A_REVERSE);

    attroff(A_BOLD);
    wrefresh(stdscr);
    
}

void print_game(pong *var)
{
    box(win, ACS_VLINE,ACS_HLINE);
    print_line();
    print_pelota(var);
    print_raqueta1(var);
    print_raqueta2(var);
    print_score(var);
    wrefresh(win);
}