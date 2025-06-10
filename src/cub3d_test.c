/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:49:22 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/10 15:30:57 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	init_game(char *map_name)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	game.map.height = init_map_height(map_name);
	generate_map(map_name, &game.map);
	initialize_player(&game.map, &game.player);
	game.fov_degrees = 66;
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
	game = init_game(argv[1]);
	print_game_info(&game);
	print_game_map(game.map.matrix);
	launch_game(&game);
	return (0);
}