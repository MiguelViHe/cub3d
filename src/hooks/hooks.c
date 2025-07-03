/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:04:11 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/03 13:19:24 by mvidal-h         ###   ########.fr       */
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
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
		process_action_key(g);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		process_scape_key(g);
}

void on_mouse_button(mouse_key_t btn, action_t act, modifier_key_t mod, void* p)
{
	(void)mod;
	t_game *g = (t_game *)p;

	if (btn == MLX_MOUSE_BUTTON_LEFT && act == MLX_PRESS)
	{
		mlx_set_cursor_mode(g->data.mlx, MLX_MOUSE_HIDDEN);
		g->cursor_hidden = true;
		mlx_set_mouse_pos(g->data.mlx, screenW / 2, screenH / 2);
	}
}

void on_game_loop(void *param)
{
	t_game	*g;
	double	moveSpeed;
	double	rotSpeedk;
	double	rotSpeedm;

	g = (t_game *)param;
	moveSpeed = g->data.mlx->delta_time * PLAYER_SPEED;
	rotSpeedk = g->data.mlx->delta_time * PLAYER_ROTATION_SPEED;
	if (g->cursor_hidden)
	{
		rotSpeedm = g->data.mlx->delta_time * MOUSE_ROTATION_SPEED;
		update_mouse_rotation(g, rotSpeedm);
	}
	update_player_movement(g, moveSpeed, rotSpeedk);
	if (cast_all_rays(g) < 0)
		exit(-1);
	
}
