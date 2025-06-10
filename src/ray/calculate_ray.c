/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:54:21 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/05 15:43:35 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calc_cameraX(int x)
{
	return (2 * x / (double)screenWidth - 1);
}

t_vector	calc_ray_dir(t_vector dir, t_vector plane, double cameraX)
{
	t_vector	ray_dir;

	ray_dir.x = dir.x + plane.x * cameraX;
	ray_dir.y = dir.y + plane.y * cameraX;
	return (normalize(ray_dir));
}

void	set_ray_pos(t_ray *ray, t_game *game)
{
	ray->map.x = (int)game->player.pos.x;
	ray->map.y = (int)game->player.pos.y;
}

void	calc_delta_dist(t_ray *ray)
{
	if (ray->dir.x == 0)
		ray->delta_dist.x = INFINITY;
	else
		ray->delta_dist.x = fabs(1 / ray->dir.x); //distancia real (hipotenusa) que recorre el rayo para pasar de una línea vertical a la siguiente (es decir, avanzar una unidad completa en X).
	if (ray->dir.y == 0)
		ray->delta_dist.y = INFINITY;
	else
		ray->delta_dist.y = fabs(1 / ray->dir.y); //distancia real (hipotenusa) que recorre el rayo para pasar de una línea horizontal a la siguiente (es decir, avanzar una unidad completa en Y).
}

void	calc_step_dir(t_ray *ray)
{
	ray->step.x = 0;
	ray->step.y = 0;
	if (ray->dir.x < 0)
		ray->step.x = -1;
	if (ray->dir.x > 0)
		ray->step.x = 1;
	if (ray->dir.y < 0)
		ray->step.y = -1;
	if (ray->dir.y > 0)
		ray->step.y = 1;
}

void	calc_side_dist(t_ray *ray, t_vector *player_pos)
{
	if (ray->step.x < 0)
		ray->side_dist.x = (player_pos->x - ray->map.x) * ray->delta_dist.x;
	else if (ray->step.x > 0)
		ray->side_dist.x = (ray->map.x + 1.0 - player_pos->x) * ray->delta_dist.x;
	else
		ray->side_dist.x = INFINITY;
	if (ray->step.y < 0)
		ray->side_dist.y = (player_pos->y - ray->map.y) * ray->delta_dist.y;
	else if (ray->step.y > 0)
		ray->side_dist.y = (ray->map.y + 1.0 - player_pos->y) * ray->delta_dist.y;
	else
		ray->side_dist.y = INFINITY;
}
