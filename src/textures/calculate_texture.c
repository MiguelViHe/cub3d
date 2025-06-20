/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:46:28 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/20 15:37:14 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		flip_texx(t_ray *ray)
{
	return (TILE_SIZE - ray->tex.x - 1);
}

void	calc_wallx_and_texx(t_game *g, t_ray *ray)
{
	if (ray->side == 0)
		ray->wallX = g->player.pos.y + ray->perpWallDist * ray->dir.y;
	else
		ray->wallX = g->player.pos.x + ray->perpWallDist * ray->dir.x;
	ray->wallX -= floor(ray->wallX);

	ray->tex.x = (int)(ray->wallX * TILE_SIZE);
	if (ray->side == 0 && ray->dir.x > 0 
			|| (ray->side == 1 && ray->dir.y < 0))
		ray->tex.x = flip_texx(ray);
}