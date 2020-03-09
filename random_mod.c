/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:42:31 by miguel            #+#    #+#             */
/*   Updated: 2020/03/09 19:43:25 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pong.h"

void random_mod(pong *var)
{
    srand(time(NULL));
    int random1 = rand() % 2;
    int random2 = rand() % 2;
    if (random1 == 0)
    {
        var->modX = -1;
    }
    else
    {
        var->modX = 1;
    }
    if (random2 == 0)
    {
        var->modY = -1;
    }
    else
    {
        var->modY = 1;
    }
}