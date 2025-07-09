/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_process_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:53:12 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/09 13:53:27 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Esta funcion se encarga de abrir o cerrar una puerta al pulsar la tecla E.
Busca la puerta en la dirección en la que está mirando el jugador y la abre o
 cierra.
Si la puerta se abre, se actualiza el temporizador para que se cierre 
automáticamente después de un tiempo.*/

void process_e_key(t_game *g)
{
	t_door *door;

	int target_x = (int)(g->player.pos.x + g->player.dir.x);
	int target_y = (int)(g->player.pos.y + g->player.dir.y);
	door = find_door(g, target_x, target_y);
	if (door)
	{
		toggle_door(door);
		// door->current_speed = DOOR_BASE_SPEED; // Resetea la velocidad al valor base al pulsar para abrir o cerrar la puerta //BUENA
		if (door->open) //si la acabo de abrir actualizao el tiempo.
			door->timer = ft_get_time();
	}
}

void process_scape_key(t_game *g)
{
	if (g->cursor_hidden)
	{
		mlx_set_cursor_mode(g->data.mlx, MLX_MOUSE_NORMAL);
		g->cursor_hidden = false;
	}
	else
	{
		ft_printf("Bye!\n");
		free_game(g);
	}
}

void process_key(t_game *g, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
		process_e_key(g);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		process_scape_key(g);
}

