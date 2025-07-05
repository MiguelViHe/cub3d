/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:06:54 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/05 18:07:39 by mvidal-h         ###   ########.fr       */
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

// void	raycast_dda(t_ray *ray, t_game *g)
// {
// 	ray->hit = 0;
// 	while (!ray->hit)
// 	{
// 		if (ray->side_dist.x < ray->side_dist.y)
// 		{
// 			ray->side_dist.x += ray->delta_dist.x;
// 			ray->map.x += ray->step.x;
// 			ray->side = 0;
// 		}
// 		else
// 		{
// 			ray->side_dist.y += + ray->delta_dist.y;
// 			ray->map.y += ray->step.y;
// 			ray->side = 1;
// 		}
// 		if (is_hit_elem(g, g->map.matrix, ray->map.y, ray->map.x))
// 		{
// 			ray->hit = 1;
// 			ray->hit_door = ray_hit_parcial_open_door(g, ray);
// 		}
// 	}
// 	if (ray->side == 0)
// 		ray->perpWallDist = ray->side_dist.x - ray->delta_dist.x;
// 	else
// 		ray->perpWallDist = ray->side_dist.y - ray->delta_dist.y;
// }


// void raycast_dda(t_ray *ray, t_game *g) //AQUI
// {
// 	t_door	*door;
// 	double	aux_wallX;

// 	while (!ray->hit)
// 	{
// 		if (ray->side_dist.x < ray->side_dist.y)
// 		{
// 			ray->side_dist.x += ray->delta_dist.x;
// 			ray->map.x += ray->step.x;
// 			ray->side = 0;
// 		}
// 		else
// 		{
// 			ray->side_dist.y += ray->delta_dist.y;
// 			ray->map.y += ray->step.y;
// 			ray->side = 1;
// 		}
// 		if (!is_hit_elem(g, ray->map.y, ray->map.x))
// 			continue;
// 		door = find_door(g, ray->map.x, ray->map.y);
// 		if (door)
// 		{
// 			// Calcula posición del impacto en la pared (wallX)
// 			aux_wallX = calc_wallx(g, ray);
// 			// Si la puerta está más abierta que el punto del impacto, seguimos buscando
// 			if (aux_wallX < door->anim_state) //PUNTO CLAVE
// 				continue;
// 			ray->hit_door = 1;
// 		}
// 		ray->hit = 1;
// 	}
// 	// Calcula distancia perpendicular para corrección visual
// 	if (ray->side == 0)
// 		ray->perpWallDist = ray->side_dist.x - ray->delta_dist.x;
// 	else
// 		ray->perpWallDist = ray->side_dist.y - ray->delta_dist.y;
// }

void	raycast_dda(t_ray *ray, t_game *g)
{
	double	temp_wallx;

	ray->hit = 0;
	while (!ray->hit)
	{
		// Avanza al siguiente bloque
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

		if (!is_hit_elem(g, ray->map.y, ray->map.x))
			continue;

		char c = g->map.matrix[ray->map.y][ray->map.x];
		if (is_door_symbol(c))
		{
			t_door *door = find_door(g, ray->map.x, ray->map.y);
			temp_wallx = calc_wallx(g, ray);
			// El signo aquí es < para comprobar si el rayo impacta con la parte cerrada
			if (temp_wallx < door->anim_state)
				continue;
			ray->hit_door = 1;
		}
		// Si llegamos aquí, hemos chocado contra algo realmente sólido
		ray->hit = 1;
	}
	// Calcula la distancia perpendicular
	if (ray->side == 0)
		ray->perpWallDist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perpWallDist = ray->side_dist.y - ray->delta_dist.y;
}
