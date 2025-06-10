/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:33:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/10 12:49:24 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_game *game, double angle)
{
	rotate_vector(&game->player.dir, angle);
	rotate_vector(&game->player.plane, angle);
}

void	move_player_forward(t_game *game, double moveSpeed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x + game->player.dir.x * moveSpeed;
	new_y = game->player.pos.y + game->player.dir.y * moveSpeed;
	// Mover en X si no hay pared en la posición nueva en X pero misma Y
	if (game->map.matrix[(int)game->player.pos.y][(int)new_x] == '0')
		game->player.pos.x = new_x;

	// Mover en Y si no hay pared en la posición nueva en Y pero misma X
	if (game->map.matrix[(int)new_y][(int)game->player.pos.x] == '0')
		game->player.pos.y = new_y;
}

void	move_player_backward(t_game *game, double moveSpeed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x - game->player.dir.x * moveSpeed;
	new_y = game->player.pos.y - game->player.dir.y * moveSpeed;
	// Mover en X si no hay pared en la posición nueva en X pero misma Y
	if (game->map.matrix[(int)game->player.pos.y][(int)new_x] == '0')
		game->player.pos.x = new_x;

	// Mover en Y si no hay pared en la posición nueva en Y pero misma X
	if (game->map.matrix[(int)new_y][(int)game->player.pos.x] == '0')
		game->player.pos.y = new_y;
}

void	strafe_player_left(t_game *game, double moveSpeed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x - game->player.plane.x * moveSpeed;
	new_y = game->player.pos.y - game->player.plane.y * moveSpeed;
	// Mover en X si no hay pared en la posición nueva en X pero misma Y
	if (game->map.matrix[(int)game->player.pos.y][(int)new_x] == '0')
		game->player.pos.x = new_x;

	// Mover en Y si no hay pared en la posición nueva en Y pero misma X
	if (game->map.matrix[(int)new_y][(int)game->player.pos.x] == '0')
		game->player.pos.y = new_y;
}

void	strafe_player_right(t_game *game, double moveSpeed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos.x + game->player.plane.x * moveSpeed;
	new_y = game->player.pos.y + game->player.plane.y * moveSpeed;
	// Mover en X si no hay pared en la posición nueva en X pero misma Y
	if (game->map.matrix[(int)game->player.pos.y][(int)new_x] == '0')
		game->player.pos.x = new_x;

	// Mover en Y si no hay pared en la posición nueva en Y pero misma X
	if (game->map.matrix[(int)new_y][(int)game->player.pos.x] == '0')
		game->player.pos.y = new_y;
}
