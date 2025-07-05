/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:46:28 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/05 18:18:24 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		flip_texx(t_ray *ray)
{
	return (ray->tex_info.mlx_tx->width - ray->tex_info.tx.x - 1);
}

double	calc_wallx(t_game *g, t_ray *ray)
{
	/*Esta formula tambien vale pero con ella se necesita tener calculado perpWallDist por adelantado:
		if (ray->side == 0)
			ray->tex_info.wallX = g->player.pos.y + ray->perpWallDist * ray->dir.y;
		else
			ray->tex_info.wallX = g->player.pos.x + ray->perpWallDist * ray->dir.x;
		ray->tex_info.wallX -= floor(ray->tex_info.wallX);
	*/

	double	wallx;
	double	map_diff; // distancia del mapa desde el jugador a la pared en X
	double	step_correction; //ajuste para corregir la dirección del paso (+1 o -1)
	double	ratio; // escala la distancia en X y obtener la posición precisa en Y. (y viceversa cuando side 1).

	if (ray->side == 0)
	{
		map_diff = ray->map.x - g->player.pos.x;
		step_correction = (1 - ray->step.x) / 2.0;
		ratio = ray->dir.y / ray->dir.x;
		wallx = g->player.pos.y + (map_diff + step_correction) * ratio;
	}
	else
	{
		map_diff = ray->map.y - g->player.pos.y;
		step_correction = (1 - ray->step.y) / 2.0;
		ratio = ray->dir.x / ray->dir.y;
		wallx = g->player.pos.x + (map_diff + step_correction) * ratio;
	}

	return wallx - floor(wallx);
}

void	calc_wallx_and_texx(t_game *g, t_ray *ray)
{
	char	c;
	t_door	*door;

	ray->tex_info.wallX = calc_wallx(g, ray);
	ray->tex_info.tx.x = (int)(ray->tex_info.wallX * ray->tex_info.mlx_tx->width);
	c = g->map.matrix[ray->map.y][ray->map.x];
	if (is_door_symbol(c))
	{
		door = find_door(g, ray->map.x, ray->map.y);
		if (door)
		{
			ray->tex_info.tx.x -= door->anim_state * ray->tex_info.mlx_tx->width;
			if (ray->tex_info.tx.x < 0)
				ray->tex_info.tx.x = 0;
			else if (ray->tex_info.tx.x >= (int)ray->tex_info.mlx_tx->width)
				ray->tex_info.tx.x = (int)ray->tex_info.mlx_tx->width - 1;
		}
	}
	if ((ray->side == 0 && ray->dir.x > 0) 
			|| (ray->side == 1 && ray->dir.y < 0))
		ray->tex_info.tx.x = flip_texx(ray);
}

void	calc_step_and_pos(double *step, double *pos, t_ray *r, int lineheight)
{
	*step = (double)r->tex_info.mlx_tx->height / lineheight;
	*pos = (r->draw.start - screenH / 2.0 + lineheight / 2.0) * (*step);
}

int	calc_tex_inf(t_game *g, t_ray *ray)
{
	char	map_elem;
	
	map_elem = g->map.matrix[ray->map.y][ray->map.x];
	if (!g->map.textures[(int)map_elem].texture)
		return (free_all(g, NULL, "Texture not loaded for map element"));
	ray->tex_info.tx_dir = (int)map_elem;
	ray->tex_info.mlx_tx = g->map.textures[(int)map_elem].texture;
	calc_wallx_and_texx(g, ray);
	calc_step_and_pos(&ray->tex_info.tx_step, &ray->tex_info.tx_pos, 
		ray, ray->draw.lineheight);
	return (0);
}