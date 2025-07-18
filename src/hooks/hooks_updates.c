/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_updates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:56:14 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/18 10:50:13 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_mouse_rotation(t_game *g, double rotSpeed)
{
	static bool first = true;
	int	xpos;
	int	ypos;
	int	delta_x;

	/*Para que la primera vez no se mueva el raton porque podria ser que el
	 puntero estuviera totalmente a la derecha o izquierda de la pantalla y 
	entonces se moveria un salto raro hacia esa direccion. De esta manera la
	 primera ves solo centra sin mover y no hay un salto exagerado.*/
	if (first) 
	{
		first = false;
		mlx_set_mouse_pos(g->data.mlx, screenW / 2, screenH / 2);
		return ;
	}
	mlx_get_mouse_pos(g->data.mlx, &xpos, &ypos);
	delta_x = xpos - (screenW / 2);
	delta_x = ft_clamp(delta_x, -50, 50);
	rotate_player(g, delta_x * rotSpeed);
	mlx_set_mouse_pos(g->data.mlx, screenW / 2, screenH / 2);
}

void	update_player_movement(t_game *g, double moveSpeed, double rotSpeed)
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

void	update_doors_touch_timer(t_game *g)
{
	t_door *door;

	door = find_door(g, (int)g->player.pos.x, (int)g->player.pos.y);
	if (door && door->open)
		door->timer = ft_get_time();
}

void	update_minimap(t_game *g)
{
	if (!g || !g->map.minimap.img)
		return ;
	if (g->map.minimap.enabled)
		ft_draw_minimap(&g->map.minimap, g);
}