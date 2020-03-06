/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:13:01 by miguel            #+#    #+#             */
/*   Updated: 2020/03/06 18:16:18 by miguel           ###   ########.fr       */
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
            mvwprintw(win, i, j, "%c", 'X');
            j++;
        }
        i++;
    }
    wrefresh(win);
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
            mvwprintw(win, i, j, "%c", 'X');
            j++;
        }
        i++;
    }
    wrefresh(win);
}

void print_pelota(pong *var)
{
    mvwprintw(win, var->pelx, var->pely, "%c", 'O');
    wrefresh(win);
}

void print_game(pong *var)
{
    box(win, ACS_VLINE,ACS_HLINE);
    print_pelota(var);
    print_raqueta1(var);
    print_raqueta2(var);
    wrefresh(win);
}