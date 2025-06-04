/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:49:22 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/04 10:29:06 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	init_game(char *argv[])
{
	t_game	game;

	game.player_pos.x = atof(argv[1]);
	game.player_pos.y = atof(argv[2]);
	game.player_dir = calculate_player_dir(argv[3][0]);
	game.fov_degrees = atof(argv[4]);
	game.fov_factor = calculate_fov_factor(game.fov_degrees);
	game.plane = calculate_plane(game.player_dir, game.fov_factor);
	game.time.prev = 0;
	game.time.current = 0;
	return (game);
}

void	setup_dda(t_ray *ray, t_game *game)
{
	set_ray_pos(ray, game);
	calculate_delta_dist(ray);
	calculate_step_dir(ray);
	calculate_side_dist(ray, &game->player_pos);
}

void	raycast_dda(t_ray *ray)
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
		// if (matrixWorld[ray->map.x][ray->map.y] > 0)
		// 	ray->hit = 1;
	}
}

void	cast_all_rays(t_game *game)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < screenWidth)
	{
		ray.cameraX = calculate_cameraX(x);
		ray.dir = calculate_ray_dir(game->player_dir, game->plane, ray.cameraX);
		setup_dda(&ray, game);
		printf("cameraX = %.5f, Columna %d: rayDirX = %.5f, rayDirY = %.5f ", ray.cameraX, x, ray.dir.x, ray.dir.y);
		printf("||||| deltaX = %.5f , deltaY = %.5f ", ray.delta_dist.x, ray.delta_dist.y);
		printf("||||| stepX = %d , stepY = %d ", ray.step.x, ray.step.y);
		printf("||||| sideX = %.5f , sideY = %.5f\n", ray.side_dist.x, ray.side_dist.y);
		// raycast_dda(&ray, game);
		x++;
	}
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 5 || !dir_ok(argv[3]))
	{
		printf("Bad args. Try x_pos y_pos init_dir (N, S, E or W), fov (in degrees)\n");
		return (0);
	}
	game = init_game(argv);
	print_game_info(&game);
	printf("\nimprimiendo rayos:\n\n");
	cast_all_rays(&game);
	// rotate_player(&game, 90);
	// printf("\nrotando 90 positivos....\n\n");
	// print_game_info(game);
	// rotate_player(&game, 90);
	// printf("\nrotando 90 positivos....\n\n");
	// print_game_info(game);
	// rotate_player(&game, 180);
	// printf("\nrotando 180 positivos....\n\n");
	// print_game_info(game);
	return (0);
}