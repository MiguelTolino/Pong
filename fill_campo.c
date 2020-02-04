/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_campo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:13:01 by miguel            #+#    #+#             */
/*   Updated: 2020/01/10 00:56:45 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

void fill_campo(pong *var)
{
    int i;
    int j;

    i = 0;
    while (i < V)
    {
        j = 0;
        while (j < H)
        {
            if (i == 0 || i == V - 1)
                var->campo[i][j] = '-';
            else if (j == 0 || j == H - 1)
                var->campo[i][j] = '|';
            else
                var->campo[i][j] = ' ';
            j++;
        }
        i++;
    }
}

void fill_raqueta1(pong *var)
{
    int i;
    int j;

    i = var->posjugx1;
    while (i < var->posfinaljugx1)
    {
        j = var->posjugy1;
        while (j < var->posfinaljugy1)
        {
            var->campo[i][j] = 'X';
            j++;
        }
        i++;
    }
}

void fill_raqueta2(pong *var)
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
            var->campo[i][j] = 'X';
            j++;
        }
        i++;
    }
}

void fill_pelota(pong *var)
{
    var->campo[var->pelx][var->pely] = 'O';
}

void fill_game(pong *var)
{
    fill_campo(var);
    fill_pelota(var);
    fill_raqueta1(var);
    fill_raqueta2(var);
}