/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 20:06:41 by miguel            #+#    #+#             */
/*   Updated: 2020/03/09 19:45:19 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

void delete_raqueta1(pong *var)
{
	int i;

	if (var->modR1 == -1)
	{
		i = var->posjugy1;
		while (i < var->posfinaljugy1)
		{
			mvwprintw(win, var->posfinaljugx1 - var->modR1 - 1, i, " ");
			i++;
		}
	}
	if (var->modR1 == 1)
	{
		i = var->posjugy1;
		while (i < var->posfinaljugy1)
		{
			mvwprintw(win, var->posjugx1 - var->modR1, i, " ");
			i++;
		}
	}
}

void delete_raqueta2(pong *var)
{
	int i;

	if (var->modR2 == -1)
	{
		i = var->posjugy2;
		while (i < var->posfinaljugy2)
		{
			mvwprintw(win, var->posfinaljugx2 - var->modR2 - 1, i, " ");
			i++;
		}
	}
	if (var->modR2 == 1)
	{
		i = var->posjugy2;
		while (i < var->posfinaljugy2)
		{
			mvwprintw(win, var->posjugx2 - var->modR2, i, " ");
			i++;
		}
	}
}

void limits(pong *var)
{
	//modificar direccion si toca las bandas
	if (var->pelx == 1 || var->pelx == V - 2)
	{
		var->modX *= -1;
		beep();
	}
	//Subir gol si llega los costados
	if (var->pely == 1 || var->pely == H - 2)
	{
		if (var->pely == 1)
		{
			var->gol.player1++;
		}
		else
		{
			var->gol.player2++;
		}
		mvwprintw(win, var->pelx, var->pely, " ");
		flash();
		var->pelx = V / 2;
		var->pely = H / 2;
		random_mod(var);
	}
	//Cambiar direccion si choca contra raqueta
	if (var->pelx >= var->posjugx1 && var->pelx <= var->posfinaljugx1 && var->pely >= var->posjugy1 && var->pely <= var->posfinaljugy1)
	{
		var->modY *= -1;
		beep();
	}
	if (var->pelx >= var->posjugx2 && var->pelx <= var->posfinaljugx2 && var->pely >= var->posjugy2 && var->pely <= var->posfinaljugy2)
	{
		var->modY *= -1;
		beep();
	}
	//Limitar principio y fin de raqueta1
	if (var->posjugx1 <= 1)
		var->limit_raq1 = 1;
	else if (var->posfinaljugx1 >= V - 1)
		var->limit_raq1 = -1;
	else
		var->limit_raq1 = 0;
	//Limitar principio y fin de raqueta2
	if (var->posjugx2 <= 1)
		var->limit_raq2 = 1;
	else if (var->posfinaljugx2 >= V - 1)
		var->limit_raq2 = -1;
	else
		var->limit_raq2 = 0;
}

void update(pong *var)
{
	int key;
	//Pelota
	var->pelx += var->modX;
	var->pely += var->modY;
	mvwprintw(win, var->pelx - var->modX, var->pely - var->modY, " ");

	key = getch();
	//Raqueta del jugador 1
	if (key == 'w' && var->limit_raq1 != 1)
		var->modR1 = -1;
	else if (key == 's' && var->limit_raq1 != -1)
		var->modR1 = 1;
	else
		var->modR1 = 0;

	var->posjugx1 += var->modR1;
	var->posfinaljugx1 += var->modR1;
	//fill_raqueta1(var);
	delete_raqueta1(var);
	//Raqueta Jugador 2

	if (key == KEY_UP && var->limit_raq2 != 1)
		var->modR2 = -1;
	else if (key == KEY_DOWN && var->limit_raq2 != -1)
		var->modR2 = 1;
	else
		var->modR2 = 0;

	var->posjugx2 += var->modR2;
	var->posfinaljugx2 += var->modR2;
	//fill_raqueta2(var);
	delete_raqueta2(var);
}

int winner(pong *var)
{
	if (var->gol.player1 == (points / 2) + 1 || var->gol.player2 == (points / 2) + 1)
			exit_game();
	return (1);
}

void gameloop(pong *var)
{
	while (winner(var))
	{
		//wclear(win);
		limits(var);
		update(var);
		print_game(var);
		usleep(50000);
	}
}