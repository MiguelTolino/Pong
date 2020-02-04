/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 20:06:41 by miguel            #+#    #+#             */
/*   Updated: 2020/01/10 01:17:41 by miguel           ###   ########.fr       */
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
			var->campo[var->posfinaljugx1 - var->modR1 - 1][i] = ' ';
			i++;
		}
	}
	if (var->modR1 == 1)
	{
		i = var->posjugy1;
		while (i < var->posfinaljugy1)
		{
			var->campo[var->posjugx1 - var->modR1][i] = ' ';
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
			var->campo[var->posfinaljugx2 - var->modR2 - 1][i] = ' ';
			i++;
		}
	}
	if (var->modR2 == 1)
	{
		i = var->posjugy2;
		while (i < var->posfinaljugy2)
		{
			var->campo[var->posjugx2 - var->modR2][i] = ' ';
			i++;
		}
	}
}

void limits(pong *var)
{
	//modificar direccion si toca las bandas
	if (var->pelx == 1 || var->pelx == V - 2)
		var->modX *= -1;
	//Subir gol si llega los costados
	if (var->pely == 1 || var->pely == H - 2)
		var->gol++;
	//Cambiar direccion si choca contra raqueta
	if (var->pelx >= var->posjugx1 && var->pelx <= var->posfinaljugx1 && var->pely >= var->posjugy1 && var->pely <= var->posfinaljugy1)
		var->modY *= -1;
	if (var->pelx >= var->posjugx2 && var->pelx <= var->posfinaljugx2 && var->pely >= var->posjugy2 && var->pely <= var->posfinaljugy2)
		var->modY *= -1;
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
	char key;
	//Pelota
	var->pelx += var->modX;
	var->pely += var->modY;
	fill_pelota(var);
	var->campo[var->pelx - var->modX][var->pely - var->modY] = ' ';

	//Raqueta del jugador 1
	if (1)
	{
		key = getchar();
		if (key == 'w' && var->limit_raq1 != 1)
			var->modR1 = -1;
		else if (key == 's' && var->limit_raq1 != -1)
			var->modR1 = 1;
		else
			var->modR1 = 0;
	}
	var->posjugx1 += var->modR1;
	var->posfinaljugx1 += var->modR1;
	fill_raqueta1(var);
	delete_raqueta1(var);

	//Raqueta Jugador 2

	if (1)
	{
		key = getchar();
		if (key == 'o' && var->limit_raq2 != 1)
			var->modR2 = -1;
		else if (key == 'l' && var->limit_raq2 != -1)
			var->modR2 = 1;
		else
			var->modR2 = 0;
	}
	var->posjugx2 += var->modR2;
	var->posfinaljugx2 += var->modR2;
	fill_raqueta2(var);
	delete_raqueta2(var);
}

void gameloop(pong *var)
{
	var->gol = 0;
	while (!var->gol)
	{
		system("clear");
		print_campo(var);
		limits(var);
		update(var);
		usleep(50000);
	}
}