/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:13:01 by miguel            #+#    #+#             */
/*   Updated: 2020/03/09 19:00:49 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

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
            wattron(win,A_REVERSE | COLOR_PAIR(2));
            mvwprintw(win, i, j, "%c", ' ');
            wattroff(win,A_REVERSE | COLOR_PAIR(2));
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
            wattron(win,A_REVERSE | COLOR_PAIR(2));
            mvwprintw(win, i, j, "%c", ' ');
            wattroff(win,A_REVERSE | COLOR_PAIR(2));
            j++;
        }
        i++;
    }
}

void print_pelota(pong *var)
{
    attron(A_BOLD | COLOR_PAIR(3));
    mvwprintw(win, var->pelx, var->pely, "%c", 'O');
    attroff(A_BOLD | COLOR_PAIR(3));
    wrefresh(win);
}

void print_score(pong *var)
{
    attron(A_BOLD);
    mvwprintw(stdscr, 4,45, "SCORE");

    mvwprintw(stdscr, 5, 15, "PLAYER 1: %i", var->gol.player1);
    mvwprintw(stdscr, 5, 75, "PLAYER 2: %i", var->gol.player2);
    attroff(A_BOLD);
    wrefresh(stdscr);
    
}

void print_game(pong *var)
{
    attron(A_BOLD | COLOR_PAIR(1));
    box(win, ACS_VLINE,ACS_HLINE);
    attroff(A_BOLD | COLOR_PAIR(1));
    print_pelota(var);
    print_raqueta1(var);
    print_raqueta2(var);
    print_score(var);
    wrefresh(win);
}