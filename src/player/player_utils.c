/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:39:44 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/03 13:10:18 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_wall(t_game *g, double x, double y)
{
	int		ix;
	int		iy;
	char	c;

	ix = (int)x;
	iy = (int)y;
	if (!g || !g->map.matrix)
		return (1); // Asumimos que es pared si el mapa no existe
	if (iy < 0 || iy >= (int)g->map.height)
		return (1); // Fuera del rango vertical
	if (ix < 0 || ix >= (int)g->map.width)
		return (1); // Fuera del rango horizontal
	c = g->map.matrix[iy][ix];
	if (is_door_symbol(c) && is_door_open(&g->map.doors_info, ix, iy))
		return (0); // Si es una puerta abierta, no es pared
	return (c != '0');
}

void	can_walk(t_game *game, double new_x, double new_y, t_vector dir)
{
	// Mover en X si no hay pared en la posición nueva en X con misma Y
	if (!is_wall(game, new_x + MARGIN_WALL * sign(dir.x), game->player.pos.y))
		game->player.pos.x = new_x;
	// Mover en Y si no hay pared en la posición nueva en Y con misma X
	if (!is_wall(game, game->player.pos.x, new_y + MARGIN_WALL * sign(dir.y)))
		game->player.pos.y = new_y;
}
