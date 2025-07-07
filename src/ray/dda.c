/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:06:54 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/07 15:05:27 by mvidal-h         ###   ########.fr       */
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

int	is_hit_elem(t_game *g, int y, int x)
{
	char	c;

	c = g->map.matrix[y][x];
	if (!g->map.textures[(int)c].texture)
		return (0);
	if (is_door_symbol(c) && is_door_open(g, x, y))
		return (0);
	return (1);
}

void	calc_step_dda(t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
}

void	raycast_dda(t_ray *ray, t_game *g)
{
	double	temp_wallx;
	t_door	*door;

	ray->hit = 0;
	ray->hit_door = 0;
	while (!ray->hit)
	{
		calc_step_dda(ray);
		if (!is_hit_elem(g, ray->map.y, ray->map.x))
			continue ;
		door = find_door(g, ray->map.x, ray->map.y);
		if (door)
		{
			temp_wallx = calc_wallx(g, ray); // Calcula la posición del impacto en la pared (wallX)
			if (temp_wallx < door->anim_state) // Si el impacto es en la parte abierta de la puerta
				continue ;
			ray->hit_door = 1; // si no, hemos chocado con una puerta parcialmente abierta
		}
		ray->hit = 1; // Si llegamos aquí, hemos chocado contra algo realmente sólido
	}
	if (ray->side == 0)
		ray->perpWallDist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perpWallDist = ray->side_dist.y - ray->delta_dist.y;
}
