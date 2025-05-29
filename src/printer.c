/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:00:24 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/29 13:47:01 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_game_info(t_game game)
{
	printf("player pos = [%g, %g]\n", game.player_pos.x, game.player_pos.y);
	printf("player dir = [%g, %g]\n", game.player_dir.x, game.player_dir.y);
	printf("fov_degrees = %g\n", game.fov_degrees);
	printf("fov_factor = %g\n", game.fov_factor);
	printf("plane = [%g, %g]\n", game.plane.x, game.plane.y);
	printf("cameraX = %g\n", game.cameraX);
	printf("ray_dir = [%g, %g]\n", game.ray_dir.x, game.ray_dir.y);
}