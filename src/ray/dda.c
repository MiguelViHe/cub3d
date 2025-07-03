/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:06:54 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/03 12:50:25 by mvidal-h         ###   ########.fr       */
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

int	is_hit_elem(t_game *g, char **matrix, int y, int x)
{
	char	c;
	t_doors	*d_inf;

	c = matrix[y][x];
	d_inf = &g->map.doors_info;
	if (!g->map.textures[(int)c].texture)
		return (0);
	if (is_door_symbol(c) && is_door_open(d_inf, x, y))
		return (0);
	return (1);
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
		if (is_hit_elem(g, g->map.matrix, ray->map.y, ray->map.x))
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpWallDist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perpWallDist = ray->side_dist.y - ray->delta_dist.y;
}
