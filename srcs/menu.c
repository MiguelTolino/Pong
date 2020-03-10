/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:31:45 by miguel            #+#    #+#             */
/*   Updated: 2020/03/09 20:45:11 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

void menu()
{

    if (has_colors())
    {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_BLACK, COLOR_WHITE);
        init_pair(3, COLOR_BLUE, COLOR_BLACK);
    }
    attron(COLOR_PAIR(1) | A_BOLD);
    mvprintw(0, 0, "PONG");
  
    attroff(COLOR_PAIR(1) | A_BOLD);
    mvprintw(1, 0, "----");
    attron(A_BOLD);
    mvprintw(2, 0, "CONTROLLER");
    attroff(A_BOLD);
    mvprintw(3, 0, "----------");
    mvprintw(4, 0, "PLAYER 1: W -> UP   |   S -> DOWN");
    mvprintw(5, 0, "PLAYER 2: ARROW UP -> UP  |   ARROW DOWN -> DOWN");
     attron(A_BOLD);
    mvprintw(7, 0, "NUMBER OF POINTS");
    attroff(A_BOLD);
    mvprintw(8, 0, "----------------");
    mvprintw(9, 0, "BEST OF 7");
    attron(A_ITALIC | A_REVERSE | A_BOLD);
    mvprintw(11, 0, "PRESS ANY KEY TO START");
    attroff(A_ITALIC | A_REVERSE | A_BOLD);
    refresh();
    getch();
}