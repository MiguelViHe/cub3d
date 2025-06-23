/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:46:28 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/23 18:46:05 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		flip_texx(t_ray *ray)
{
	return (TILE_SIZE - ray->tex_info.tx.x - 1);
}

void	calc_wallx_and_texx(t_game *g, t_ray *ray)
{
	if (ray->side == 0)
		ray->tex_info.wallX = g->player.pos.y + ray->perpWallDist * ray->dir.y;
	else
		ray->tex_info.wallX = g->player.pos.x + ray->perpWallDist * ray->dir.x;
	ray->tex_info.wallX -= floor(ray->tex_info.wallX);

	ray->tex_info.tx.x = (int)(ray->tex_info.wallX * TILE_SIZE);
	if ((ray->side == 0 && ray->dir.x > 0) 
			|| (ray->side == 1 && ray->dir.y < 0))
		ray->tex_info.tx.x = flip_texx(ray);
}
void	calc_step_and_pos(double *step, double *pos, int start, int end)
{
	*step = (double)TILE_SIZE / (end - start);
	*pos = (start - screenH / 2 + (end - start) / 2.0) * (*step);
}

void	calc_tex_inf(t_game *g, t_ray *ray)
{
	int		t_dir;
	
	t_dir = get_texture_direction(ray->side, ray->dir);
	ray->tex_info.tx_dir = t_dir;
	ray->tex_info.mlx_tx = g->map.textures[t_dir].texture;
	calc_wallx_and_texx(g, ray);
	calc_step_and_pos(&ray->tex_info.tx_step, &ray->tex_info.tx_pos, 
		ray->draw.start, ray->draw.end);
}