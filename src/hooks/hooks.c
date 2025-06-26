/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:04:11 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/26 16:47:40 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	on_destroy(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	free_game(g);
}

void	on_keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*g;
	bool	pressed;

	g = (t_game *)param;
	pressed = (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT);
	if (keydata.key == MLX_KEY_W)
		g->input.move_forward = pressed;
	if (keydata.key == MLX_KEY_S)
		g->input.move_backward = pressed;
	if (keydata.key == MLX_KEY_A)
		g->input.move_left = pressed;
	if (keydata.key == MLX_KEY_D)
		g->input.move_right = pressed;
	if (keydata.key == MLX_KEY_LEFT)
		g->input.rotate_left = pressed;
	if (keydata.key == MLX_KEY_RIGHT)
		g->input.rotate_right = pressed;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_printf("Bye!\n");
		free_game(g);
	}
}

void on_cursor_move2(double xpos, double ypos, void *param)
{
	t_game	*g;
	double	rotSpeed;
	double	delta_x;
	static double	last_x = -1;

	(void)ypos; // Unused parameter
	g = (t_game *)param;
	if (last_x < 0)
		last_x = xpos;
	else
	{
		delta_x = xpos - last_x;
		ft_clamp(delta_x, -0.5, 0.5); // Clamp the delta to avoid excessive rotation
		rotSpeed = delta_x * CURSOR_ROTATION_SPEED;
		rotate_player(g, rotSpeed);
		last_x = xpos;
	}
}

void	on_cursor_move(double xpos, double ypos, void *param)
{
	t_game	*g;
	double rotSpeed;
	double	delta_x;
	static bool skip_next = false;

	(void)ypos; // Unused parameter
	g = (t_game *)param;
	if (skip_next)
		skip_next = false;
	else
	{
		delta_x = xpos - (screenW / 2);
		delta_x = ft_clamp(delta_x, -50, 50); // Clamp the delta to avoid excessive rotation
		rotSpeed = delta_x * CURSOR_ROTATION_SPEED;
		rotate_player(g, rotSpeed);
		skip_next = true; // Skip the next call to avoid jitter
		mlx_set_mouse_pos(g->data.mlx, screenW / 2, screenH / 2);
	}
}

void handle_input(t_game *g, double moveSpeed, double rotSpeed)
{
	if (g->input.move_forward)
		move_player_forward(g, moveSpeed);
	if (g->input.move_backward)
		move_player_backward(g, moveSpeed);
	if (g->input.move_left)
		strafe_player_left(g, moveSpeed);
	if (g->input.move_right)
		strafe_player_right(g, moveSpeed);
	if (g->input.rotate_left)
		rotate_player(g, -rotSpeed);
	if (g->input.rotate_right)
		rotate_player(g, rotSpeed);
}

void on_game_loop(void *param)
{
	t_game	*g;
	double	moveSpeed;
	double	rotSpeed;

	g = (t_game *)param;
	// upgrade_frameTime(&g->time);
	// printf("Frame_time: %.3f - delta_time: %.3f\n", g->time.frameTime, g->data.mlx->delta_time);
	moveSpeed = g->data.mlx->delta_time * PLAYER_SPEED;
	rotSpeed = g->data.mlx->delta_time * PLAYER_ROTATION_SPEED;
	handle_input(g, moveSpeed, rotSpeed);
	cast_all_rays(g);
	// Mostrar FPS (opcional)
	//printf("FPS: %.1f\n", 1.0 / g->time.frameTime);
}
