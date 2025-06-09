/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:43:48 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/09 16:46:20 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_time(t_time *time)
{
	time->current = mlx_get_time();
	time->prev = time->current;
}

int	initialize_game(t_game *g)
{
	ft_memset(&g->data, 0, sizeof(t_data));
	g->data.mlx = mlx_init(screenWidth, screenHeight, "mvidal-h", false);
	if (!g->data.mlx)
	{
		ft_fdprintf(2, mlx_strerror(mlx_errno));
		free_map_array(&g->map);
		return (EXIT_FAILURE);
	}
	g->data.img = mlx_new_image(g->data.mlx, screenWidth, screenHeight);
	mlx_get_monitor_size(0, &g->data.screen_width, &g->data.screen_height);
	mlx_image_to_window(g->data.mlx, g->data.img, 0, 0);
	cast_all_rays(g);
	// verify_map_size(&data);
	// load_images(&data);
	// images_to_map(&data);
	mlx_key_hook(g->data.mlx, on_keypress, g);
	mlx_close_hook(g->data.mlx, on_destroy, g);
	mlx_loop_hook(g->data.mlx, on_game_loop, g);
	init_time(&g->time);
	mlx_loop(g->data.mlx);
	return (EXIT_SUCCESS);
}
