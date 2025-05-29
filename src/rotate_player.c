/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:33:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/29 15:30:12 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_game *game, double angle)
{
	double  rad_angle;
	
	rad_angle = deg_to_rad(angle);
	rotate_vector(&game->player_dir, rad_angle);
	rotate_vector(&game->plane, rad_angle);
}