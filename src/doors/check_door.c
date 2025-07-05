/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:25:52 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/05 18:22:28 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_door_symbol(char c)
{
	return (c == DOOR_SYMBOL);
}

t_door	*find_door(t_game *g, int x, int y)
{
	size_t	i;
	t_door	*door;
	char	c;

	i = 0;
	c = g->map.matrix[y][x];
	if (!is_door_symbol(c))
		return NULL;
	while (i < g->map.doors_info.doors_count)
	{
		door = &g->map.doors_info.doors_array[i];
		if (door->x == x && door->y == y)
			return door;
		i++;
	}
	return NULL;
}

bool	is_door_open(t_game *g, int x, int y)
{
	t_door	*door;

	door = find_door(g, x, y);
	if (!door)
		return false; // Si no se encuentra la puerta, asumo que está cerrada.
	return (door->anim_state >= 1.0);
}
