/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:48:25 by miguel            #+#    #+#             */
/*   Updated: 2020/03/09 18:35:16 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

int init_window()
{
    nodelay(stdscr, true);
    clear();
    win = newwin(V, H, 10, 10);
    wbkgd(win, COLOR_PAIR(2));
    refresh();
    return (1);
}