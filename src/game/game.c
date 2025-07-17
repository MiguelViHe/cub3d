/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:43:48 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/17 11:52:40 by mvidal-h         ###   ########.fr       */
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
	g->cursor_hidden = true;
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
	g->data.instance = mlx_image_to_window(g->data.mlx, g->data.img, 0, 0);
	g->map.minimap = ft_create_minimap(g, &g->map);
	ft_set_cursor(g);
	if (cast_all_rays(g) < 0)
		return (-1);
	mlx_key_hook(g->data.mlx, on_keypress, g);
	mlx_mouse_hook(g->data.mlx, on_mouse_button, g);
	mlx_close_hook(g->data.mlx, on_destroy, g);
	mlx_loop_hook(g->data.mlx, on_game_loop, g);
	mlx_loop(g->data.mlx);
	return (EXIT_SUCCESS);
}
