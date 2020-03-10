/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 19:09:15 by miguel            #+#    #+#             */
/*   Updated: 2020/03/09 19:44:56 by miguel           ###   ########.fr       */
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
    var.gol.player1 = 0;
    var.gol.player2 = 0;

    //MODIFICACION
	random_mod(&var);
    

    initscr();
    noecho();
    keypad(stdscr, TRUE);

    menu();
    init_window();
    print_game(&var);
    gameloop(&var);
    exit_game();
    return (0);
}