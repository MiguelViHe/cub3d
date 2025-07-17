/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:49:22 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/17 11:51:35 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	init_game(char *map_name)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (parse_file(map_name, &game) < 0)
		(ft_fdprintf(2, "Error parsing %s\n", map_name), exit(EXIT_FAILURE));
	if (init_doors(&game.map, &game.map.doors_info) < 0)
		(free_all(&game, NULL, "Error initializing doors"), exit(EXIT_FAILURE));
	// print_door_info(game.map.doors_info);
	printf("Map parsed successfully.\n");
	initialize_player(&game.map, &game.player);
	game.fov_degrees = FOV_DEGREES;
	game.fov_factor = calc_fov_factor(game.fov_degrees);
	game.player.plane = calc_plane(game.player.dir, game.fov_factor);
	return (game);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		printf("Bad args. try 'map.cub'\n");
		return (0);
	}
	check_arg_cub(argv[1]);
	game = init_game(argv[1]);
	// print_game_map(game.map.matrix);
	// print_game_info(&game);
	if (launch_game(&game) < 0)
		free_game(&game);
	return (0);
}