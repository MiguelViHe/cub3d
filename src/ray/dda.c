/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:06:54 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/10 15:07:33 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_dda(t_ray *ray, t_game *game)
{
	set_ray_pos(ray, game);
	calc_delta_dist(ray);
	calc_step_dir(ray);
	calc_side_dist(ray, &game->player.pos);
}

void	raycast_dda(t_ray *ray, t_game *g)
{
	ray->hit = 0;
	while (!ray->hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += + ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (g->map.matrix[ray->map.y][ray->map.x] > '0')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpWallDist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perpWallDist = ray->side_dist.y - ray->delta_dist.y;
}