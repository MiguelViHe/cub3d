/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:25:52 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/03 13:13:58 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_door_symbol(char c)
{
	return (c == DOOR_SYMBOL);
}

bool	is_door_open(t_doors *d, int x, int y)
{
	size_t	i;

	i = 0;
	while (i < d->doors_count)
	{
		if (d->doors_array[i].x == x && d->doors_array[i].y == y)
			return (d->doors_array[i].open);
		i++;
	}
	return (false); // Si no se encuentra la puerta, consideramos que está cerrada
}