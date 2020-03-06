/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 19:09:15 by miguel            #+#    #+#             */
/*   Updated: 2020/03/06 18:15:52 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

int main()
{
    pong var;
    
    //POSICION
    var.pelx = V / 2;
    var.pely = H / 2;
    var.posjugx1 = 9;
    var.posjugy1 = 2;
    var.posfinaljugx1 = 13;
    var.posfinaljugy1 = 4;
    var.posjugx2 = 9;
    var.posjugy2 = H - 4;
    var.posfinaljugx2 = 13;
    var.posfinaljugy2 = H - 2;

    //MODIFICACION
    var.modX = -1;
    var.modY = -1;

    init_window();
    print_game(&var);
    gameloop(&var);
    getch();
    endwin();
    return (0);
}