/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:54:21 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/02 11:15:48 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calculate_cameraX(int x)
{
	return (2 * x / (double)screenWidth - 1);
}

t_vector	calculate_ray_dir(t_vector dir, t_vector plane, double cameraX)
{
	t_vector	ray_dir;

	ray_dir.x = dir.x + plane.x * cameraX;
	ray_dir.y = dir.y + plane.y * cameraX;
	return (ray_dir);
}

void	set_ray_pos(t_ray *ray, t_game *game)
{
	ray->mapX = (int)game->player_pos.x;
	ray->mapY = (int)game->player_pos.y;
}

t_vector	calculate_delta_dist(t_ray *ray)
{
	//seguir aqui
}