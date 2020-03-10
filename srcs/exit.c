/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:04:43 by miguel            #+#    #+#             */
/*   Updated: 2020/03/09 20:51:01 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

void who_win(pong *var)
{
    if (var->gol.player1 > points / 2)
    {
        mvwprintw(stdscr, 0,0, "WINS PLAYER 1!!!!!!!!");
    }
    if (var->gol.player2 > points / 2)
    {
        mvwprintw(stdscr, 0,0, "WINS PLAYER 2!!!!!!!!");
    }
    
}

void exit_game()
{
    nodelay(stdscr, 0);
    attron(A_BOLD | A_REVERSE);
    mvprintw(1,0, "PRESS ANY KEY TO EXIT");
    attroff(A_BOLD | A_REVERSE);
    getch();
    endwin();
    exit(1);
}