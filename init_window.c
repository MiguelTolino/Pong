/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:48:25 by miguel            #+#    #+#             */
/*   Updated: 2020/03/06 20:35:20 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

int init_window()
{
    initscr();
    noecho();
    nodelay(stdscr,true);
    clear();
    win = newwin(V, H, 10, 10);
    keypad(stdscr, TRUE);
    refresh();
    return (1);
}