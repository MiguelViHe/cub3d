/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:22:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/07 13:05:58 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_doors_animation(t_game *g, double delta_time)
{
	size_t	i;
	t_door	*door;
	double	now;

	i = 0;
	now = ft_get_time();
	while (i < g->map.doors_info.doors_count)
	{
		door = &g->map.doors_info.doors_array[i];
		if (door->open && (now - door->timer >= 5.0)) // Si está abierta pero han pasado 5s sin que el jugador la toque, se cierra
			door->open = false;
		if (door->open && door->anim_state < 1.0) //Si la quiero abrir(objetivo: door->open) pero no esta del todo abierta (anim_state == 1.0 -> abierta)
		{
			door->anim_state += DOOR_ANIMATION_SPEED * delta_time;
			if (door->anim_state > 1.0)
				door->anim_state = 1.0;
		}
		else if (!door->open && door->anim_state > 0.0) // Si la quiero cerrar (objetivo: !door->open) pero no esta del todo cerrada (anim_state == 0.0 -> cerrada)
		{
			door->anim_state -= DOOR_ANIMATION_SPEED * delta_time;
			if (door->anim_state < 0.0)
				door->anim_state = 0.0;
		}
		i++;
	}
}
