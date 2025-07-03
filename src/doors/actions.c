/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:49:11 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/03 13:14:18 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void toggle_door(t_game *g, int x, int y)
{
	size_t	i;
	t_door	*door;

	i = 0;
	while (i < g->map.doors_info.doors_count)
	{
		door = &g->map.doors_info.doors_array[i];
		if (door->x == x && door->y == y) {
			//door->open = !door->open; // abrir/cerrar
			TOGGLE(door->open); // abrir/cerrar
			return ;
		}
		i++;
	}
}