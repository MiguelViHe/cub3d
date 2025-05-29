/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:49:22 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/29 15:47:10 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	init_game(char *argv[])
{
	t_game	game;

	game.player_pos.x = atoi(argv[1]);
	game.player_pos.y = atoi(argv[2]);
	game.player_dir = calculate_player_dir(argv[3][0]);
	game.fov_degrees = atof(argv[4]);
	game.fov_factor = calculate_fov_factor(game.fov_degrees);
	game.plane = calculate_plane(game.player_dir, game.fov_factor);
	game.cameraX = calculate_cameraX(atoi(argv[5]));
	game.ray_dir = calculate_ray_dir(game.player_dir, game.plane, game.cameraX);
	return (game);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 6 || !dir_ok(argv[3]))
	{
		printf("Bad args. Try x_pos y_pos init_dir (N, S, E or W), fov (in degrees) and pixels_column\n");
		return (0);
	}
	game = init_game(argv);
	print_game_info(game);
	rotate_player(&game, 90);
	printf("\nrotando 90 positivos....\n\n");
	print_game_info(game);
	rotate_player(&game, 90);
	printf("\nrotando 90 positivos....\n\n");
	print_game_info(game);
	rotate_player(&game, 180);
	printf("\nrotando 180 positivos....\n\n");
	print_game_info(game);
	return (0);
}