/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:22:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/08 13:36:30 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	update_doors_animation(t_game *g, double delta_time)
// {
// 	size_t	i;
// 	t_door	*door;
// 	double	now;

// 	i = 0;
// 	now = ft_get_time();
// 	while (i < g->map.doors_info.doors_count)
// 	{
// 		door = &g->map.doors_info.doors_array[i];
// 		if (door->open && (now - door->timer >= 5.0)) // Si está abierta pero han pasado 5s sin que el jugador la toque, se cierra
// 			door->open = false;
// 		if (door->open && door->anim_state < 1.0) //Si la quiero abrir(objetivo: door->open) pero no esta del todo abierta (anim_state == 1.0 -> abierta)
// 		{
// 			door->anim_state += DOOR_ANIMATION_SPEED * delta_time;
// 			if (door->anim_state > 1.0)
// 				door->anim_state = 1.0;
// 		}
// 		else if (!door->open && door->anim_state > 0.0) // Si la quiero cerrar (objetivo: !door->open) pero no esta del todo cerrada (anim_state == 0.0 -> cerrada)
// 		{
// 			door->anim_state -= DOOR_ANIMATION_SPEED * delta_time;
// 			if (door->anim_state < 0.0)
// 				door->anim_state = 0.0;
// 		}
// 		i++;
// 	}
// }

// void	update_doors_animation(t_game *g, double delta_time)
// {
// 	size_t	i;
// 	t_door	*door;
// 	double	now;

// 	i = 0;
// 	now = ft_get_time();
// 	while (i < g->map.doors_info.doors_count)
// 	{
// 		door = &g->map.doors_info.doors_array[i];
// 		if (door->open && (now - door->timer >= 5.0)) // Si está abierta pero han pasado 5s sin que el jugador la toque, se cierra
// 			door->open = false;
// 		if (door->open && door->anim_state < 1.0) //Si la quiero abrir(objetivo: door->open) pero no esta del todo abierta (anim_state == 1.0 -> abierta)
// 		{
// 			if (door->anim_state >= 0.75) {
// 				// desacelera en el tramo final
// 				door->current_speed -= DOOR_ACCELERATION * delta_time;
// 				if (door->current_speed < DOOR_BASE_SPEED * 0.1) // pon un límite mínimo
// 					door->current_speed = DOOR_BASE_SPEED * 0.1;
// 			} else {
// 				// sigue acelerando normalmente
// 			door->current_speed += DOOR_ACCELERATION * delta_time;
// 			}
// 			door->anim_state += door->current_speed * delta_time;
// 			if (door->anim_state > 1.0)
// 			{
// 				door->anim_state = 1.0;
// 				door->current_speed = DOOR_BASE_SPEED; // Resetea la velocidad al valor base después de abrir la puerta
// 			}
// 		}
// 		else if (!door->open && door->anim_state > 0.0) // Si la quiero cerrar (objetivo: !door->open) pero no esta del todo cerrada (anim_state == 0.0 -> cerrada)
// 		{
// 			if (door->anim_state <= 0.25) {
// 				// desacelera en el tramo final
// 				door->current_speed -= DOOR_ACCELERATION * delta_time;
// 				if (door->current_speed < DOOR_BASE_SPEED * 0.2)
// 					door->current_speed = DOOR_BASE_SPEED * 0.2;
// 			} else {
// 				// sigue acelerando normalmente
// 				door->current_speed += DOOR_ACCELERATION * delta_time;
// 			}
// 			door->anim_state -= door->current_speed * delta_time;
// 			if (door->anim_state < 0.0)
// 			{
// 				door->anim_state = 0.0;
// 				door->current_speed = DOOR_BASE_SPEED; // Resetea la velocidad al valor base después de cerrar la puerta
// 			}
// 		}
// 		i++;
// 	}
// }

// void	update_doors_animation(t_game *g, double delta_time)
// {
// 	size_t	i;
// 	t_door	*door;
// 	double	now;

// 	i = 0;
// 	now = ft_get_time();
// 	while (i < g->map.doors_info.doors_count)
// 	{
// 		door = &g->map.doors_info.doors_array[i];

// 		// Si la puerta lleva abierta más de 5s, márcala para cerrar
// 		if (door->open && (now - door->timer >= 5.0))
// 			door->open = false;

// 		if (door->open && door->anim_state < 1.0)
// 		{
// 			if (door->anim_state >= 0.9) // últimos 10%
// 			{
// 				// desaceleración más fuerte
// 				door->current_speed -= (2.5 * DOOR_ACCELERATION) * delta_time;
// 				if (door->current_speed < DOOR_BASE_SPEED * 0.4)
// 					door->current_speed = DOOR_BASE_SPEED * 0.4;
// 			}
// 			else
// 			{
// 				// aceleración normal
// 				door->current_speed += DOOR_ACCELERATION * delta_time;
// 				if (door->current_speed > MAX_DOOR_SPEED)
// 					door->current_speed = MAX_DOOR_SPEED;
// 			}

// 			door->anim_state += door->current_speed * delta_time;

// 			if (door->anim_state > 1.0)
// 			{
// 				door->anim_state = 1.0;
// 				door->current_speed = DOOR_BASE_SPEED;
// 			}
// 		}
// 		else if (!door->open && door->anim_state > 0.0)
// 		{
// 			if (door->anim_state <= 0.1) // últimos 10%
// 			{
// 				// desaceleración más fuerte
// 				door->current_speed -= (2.5 * DOOR_ACCELERATION) * delta_time;
// 				if (door->current_speed < DOOR_BASE_SPEED * 0.4)
// 					door->current_speed = DOOR_BASE_SPEED * 0.4;
// 			}
// 			else
// 			{
// 				// aceleración normal
// 				door->current_speed += DOOR_ACCELERATION * delta_time;
// 				if (door->current_speed > MAX_DOOR_SPEED)
// 					door->current_speed = MAX_DOOR_SPEED;
// 			}

// 			door->anim_state -= door->current_speed * delta_time;

// 			if (door->anim_state < 0.0)
// 			{
// 				door->anim_state = 0.0;
// 				door->current_speed = DOOR_BASE_SPEED;
// 			}
// 		}

// 		i++;
// 	}
// }

// void	update_doors_animation(t_game *g, double delta_time) //BUENA
// {
// 	size_t	i;
// 	t_door	*door;
// 	double	now;

// 	i = 0;
// 	now = ft_get_time();
// 	while (i < g->map.doors_info.doors_count)
// 	{
// 		door = &g->map.doors_info.doors_array[i];

// 		// Si la puerta lleva abierta más de 5s, márcala para cerrar
// 		if (door->open && (now - door->timer >= 5.0))
// 			door->open = false;

// 		if (door->open && door->anim_state < 1.0)
// 		{
// 			if (door->anim_state >= 0.85)
// 			{
// 				// ease-out cuadrático
// 				double progress = (door->anim_state - 0.85) / 0.15;
// 				double factor = (1.0 - progress) * (1.0 - progress);
// 				door->current_speed = MAX_DOOR_SPEED * factor;
// 				if (door->current_speed < DOOR_BASE_SPEED * 0.3)
// 					door->current_speed = DOOR_BASE_SPEED * 0.3;
// 			}
// 			else
// 			{
// 				door->current_speed += DOOR_ACCELERATION * delta_time;
// 				if (door->current_speed > MAX_DOOR_SPEED)
// 					door->current_speed = MAX_DOOR_SPEED;
// 			}

// 			door->anim_state += door->current_speed * delta_time;

// 			if (door->anim_state > 1.0)
// 			{
// 				door->anim_state = 1.0;
// 				door->current_speed = DOOR_BASE_SPEED;
// 			}
// 		}
// 		else if (!door->open && door->anim_state > 0.0)
// 		{
// 			if (door->anim_state <= 0.15)
// 			{
// 				// ease-out cuadrático
// 				double progress = door->anim_state / 0.15;
// 				double factor = (progress) * (progress);
// 				door->current_speed = MAX_DOOR_SPEED * factor;
// 				if (door->current_speed < DOOR_BASE_SPEED * 0.3)
// 					door->current_speed = DOOR_BASE_SPEED * 0.3;
// 			}
// 			else
// 			{
// 				door->current_speed += DOOR_ACCELERATION * delta_time;
// 				if (door->current_speed > MAX_DOOR_SPEED)
// 					door->current_speed = MAX_DOOR_SPEED;
// 			}

// 			door->anim_state -= door->current_speed * delta_time;

// 			if (door->anim_state < 0.0)
// 			{
// 				door->anim_state = 0.0;
// 				door->current_speed = DOOR_BASE_SPEED;
// 			}
// 		}

// 		i++;
// 	}
// }

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

		if (door->open && (now - door->timer >= 5.0))
			door->open = false;

		if (door->open && door->anim_state < 1.0)
		{
			door->anim_elapsed += delta_time;
			if (door->anim_elapsed > DOOR_ANIM_TIME)
				door->anim_elapsed = DOOR_ANIM_TIME;

			double progress = door->anim_elapsed / DOOR_ANIM_TIME;
			door->anim_state = 0.5 - 0.5 * cos(progress * M_PI);
		}
		else if (!door->open && door->anim_state > 0.0)
		{
			door->anim_elapsed -= delta_time;
			if (door->anim_elapsed < 0.0)
				door->anim_elapsed = 0.0;

			double progress = door->anim_elapsed / DOOR_ANIM_TIME;
			door->anim_state = 0.5 - 0.5 * cos(progress * M_PI);
		}

		i++;
	}
}



