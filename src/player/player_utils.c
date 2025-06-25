/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:39:44 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/25 10:06:41 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	can_walk(t_game *game, double new_x, double new_y, t_vector dir)
{
	// Mover en X si no hay pared en la posición nueva en X con misma Y
	if (!is_wall(game, new_x + MARGIN_WALL * sign(dir.x), game->player.pos.y))
		game->player.pos.x = new_x;
	// Mover en Y si no hay pared en la posición nueva en Y con misma X
	if (!is_wall(game, game->player.pos.x, new_y + MARGIN_WALL * sign(dir.y)))
		game->player.pos.y = new_y;
}
