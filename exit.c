/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:04:43 by miguel            #+#    #+#             */
/*   Updated: 2020/03/09 19:13:51 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

void exit_game()
{
    nodelay(stdscr, 0);
    attron(A_BOLD | A_REVERSE);
    mvprintw(0,0, "PRESS ANY KEY TO EXIT");
    attroff(A_BOLD | A_REVERSE);
    getch();
    endwin();
    exit(1);
}