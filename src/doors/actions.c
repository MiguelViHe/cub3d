/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:49:11 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/05 17:19:56 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void toggle_door(t_game *g, int x, int y)
{
	t_door	*door;
	char	c;
	
	c = g->map.matrix[y][x];
	if (is_door_symbol(c))
	{
		door = find_door(g, x, y);
		if (door)
			TOGGLE(door->open);
	}
}
