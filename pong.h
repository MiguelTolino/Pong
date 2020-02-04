/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pong.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:14:42 by miguel            #+#    #+#             */
/*   Updated: 2020/01/10 01:13:35 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONG_H
#define PONG_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <time.h>
#define V 20
#define H 80

typedef struct pong
{
    char campo[V][H];
    int pelx, pely;
    int posjugx1;
    int posjugy1;
    int posfinaljugx1, posfinaljugy1;
    int posjugx2;
    int posjugy2;
    int posfinaljugx2, posfinaljugy2;
    int modX, modY, modR1,modR2, limit_raq1, limit_raq2;
    int gol;
} pong;

void fill_campo(pong *var);
void fill_raqueta1(pong *var);
void fill_raqueta2(pong *var);
void fill_pelota(pong *var);
void print_campo(pong *var);
void limits(pong *var);
void update(pong *var);
void gameloop(pong *var);
void fill_game(pong *var);
void delete_raqueta(pong *var);
int  kbhit(void);



#endif