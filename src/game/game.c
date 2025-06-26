/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:43:48 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/26 15:57:52 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_window()
{
	mlx_set_setting(MLX_STRETCH_IMAGE, STRETCH_IMAGE);
	mlx_set_setting(MLX_FULLSCREEN, FULLSCREEN);
}

void	ft_set_cursor(t_game *g)
{
	mlx_set_cursor_mode(g->data.mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(g->data.mlx, screenW / 2, screenH / 2);

}

int	launch_game(t_game *g)
{
	ft_set_window();
	g->data.mlx = mlx_init(screenW, screenH, "mvidal-h", true);
	if (!g->data.mlx)
	{
		ft_fdprintf(2, mlx_strerror(mlx_errno));
		return (free_all(g, NULL, "Error initializing MLX42"));
	}
	g->data.img = mlx_new_image(g->data.mlx, screenW, screenH);
	mlx_get_monitor_size(0, &g->data.screen_width, &g->data.screen_height);
	mlx_image_to_window(g->data.mlx, g->data.img, 0, 0);
	ft_set_cursor(g);
	cast_all_rays(g);
	mlx_key_hook(g->data.mlx, on_keypress, g);
	mlx_cursor_hook(g->data.mlx, on_cursor_move, g);
	mlx_close_hook(g->data.mlx, on_destroy, g);
	mlx_loop_hook(g->data.mlx, on_game_loop, g);
	// init_time(&g->time);
	mlx_loop(g->data.mlx);
	return (EXIT_SUCCESS);
}
