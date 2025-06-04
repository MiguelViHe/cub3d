/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:49:22 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/04 17:19:56 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	init_game(char *map_name)
{
	t_game	game;

	game.map.height = init_map_height(map_name);
	generate_map(map_name, &game.map);
	initialize_player(&game.map, &game.player);
	game.fov_degrees = 66;
	game.fov_factor = calc_fov_factor(game.fov_degrees);
	game.player.plane = calc_plane(game.player.dir, game.fov_factor);
	game.time.prev = 0;
	game.time.current = 0;
	return (game);
}

void	setup_dda(t_ray *ray, t_game *game)
{
	set_ray_pos(ray, game);
	calc_delta_dist(ray);
	calc_step_dir(ray);
	calc_side_dist(ray, &game->player.pos);
}

void	raycast_dda(t_ray *ray, t_game *g)
{
	ray->hit = 0;
	while (!ray->hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += + ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (g->map.matrix[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
	}
}

void	cast_all_rays(t_game *g)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < screenWidth)
	{
		ray.cameraX = calc_cameraX(x);
		ray.dir = calc_ray_dir(g->player.dir, g->player.plane, ray.cameraX);
		setup_dda(&ray, g);
		raycast_dda(&ray, g);
		printf("cameraX = %.5f, Columna %d: rayDirX = %.5f, rayDirY = %.5f ", ray.cameraX, x, ray.dir.x, ray.dir.y);
		printf("||||| deltaX = %.5f , deltaY = %.5f ", ray.delta_dist.x, ray.delta_dist.y);
		printf("||||| stepX = %d , stepY = %d ", ray.step.x, ray.step.y);
		printf("||||| sideX = %.5f , sideY = %.5f", ray.side_dist.x, ray.side_dist.y);
		printf("----> choco en [%d,%d] (lado %d)\n", ray.map.x, ray.map.y, ray.side);
		x++;
	}
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
	printf("\nimprimiendo rayos:\n\n");
	cast_all_rays(&game);
	ft_printf("\n");
	print_game_map(game.map.matrix);
	// rotate_player(&game, 90);
	// printf("\nrotando 90 positivos....\n\n");
	// print_game_info(game);
	// rotate_player(&game, 90);
	// printf("\nrotando 90 positivos....\n\n");
	// print_game_info(game);
	// rotate_player(&game, 180);
	// printf("\nrotando 180 positivos....\n\n");
	// print_game_info(game);
	free_map_array(&game.map);
	return (0);
}