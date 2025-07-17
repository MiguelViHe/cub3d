/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 09:49:05 by daniel            #+#    #+#             */
/*   Updated: 2025/07/17 16:10:45 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_tile(mlx_image_t *img, t_vector vtile, size_t size, uint32_t color)
{
	int	x;
	int	y;

	if (!img || vtile.x < 0 || vtile.y < 0
		|| vtile.x + (int)size > (int)img->width || vtile.y + (int)size > (int)img->height)
		return ;
	y = 0;
	while (y < (int)size)
	{
		x = 0;
		while (x < (int)size)
		{
			int px = vtile.x + x;
			int py = vtile.y + y;
			if (px >= 0 && py >= 0 && px < (int)img->width && py < (int)img->height)
				mlx_put_pixel(img, px, py, color);
			x++;
		}
		y++;
	}
}

void	ft_draw_line(mlx_image_t *img, t_vector e1, t_vector e2, uint32_t color)
{
	t_vector	dist; // Distancia entre posicion de jugador y pared donde choca el rayo
	int			steps; // mayor numero de pasos entre horizontal y vertical para que la linea sea continua
	t_vector	inc; // incremento en x e y para llegar a la pared (e2) desde el jugador (e1)
	t_vector	aux; // coordenada auxiliar para recorrer los pasos entre e1 y e2

	if (!img || e1.x < 0 || e1.y < 0 || e2.x < 0 || e2.y < 0
		|| e1.x >= (int)img->width || e1.y >= (int)img->height
		|| e2.x >= (int)img->width || e2.y >= (int)img->height)
		return ;
	dist.x = e2.x - e1.x;
	dist.y = e2.y - e1.y;
	steps = fmax(fabs(dist.x), fabs(dist.y));
	inc.x = dist.x / steps;
	inc.y = dist.y / steps;
	aux.x = e1.x;
	aux.y = e1.y;
	while (steps-- >= 0)
	{
		mlx_put_pixel(img, (int)aux.x, (int)aux.y, color);
		aux.x += inc.x;
		aux.y += inc.y;
	}
}

void ft_draw_by_tile(char tile, mlx_image_t *img, t_vector pos, double scale)
{
	uint32_t color;

	if (tile == '0')
		color = MINIMAP_COLOR_FLOOR; // Color for floor tiles
	else if (tile == ' ')
		color = MINIMAP_COLOR_EMPTY; // Color for empty tiles
	else if (tile == 'D')
		color = MINIMAP_COLOR_DOOR; // Color for door tiles
	else
		color = MINIMAP_COLOR_WALL; // Default color for walls
	ft_draw_tile(img, pos, ceil(scale), color);
}