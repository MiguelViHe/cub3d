/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:33:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/10 15:04:04 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(mlx_image_t* img, int x, t_screenline draw)
{
	int	index;

	index = 0;
	while (index < draw.start)
	{
		mlx_put_pixel(img, x, index, draw.color_ceiling);
		index++;
	}
}

void	draw_floor(mlx_image_t* img, int x, t_screenline draw)
{
	int	index;

	index = draw.end + 1;
	while (index <= screenHeight - 1)
	{
		mlx_put_pixel(img, x, index, draw.color_floor);
		index++;
	}
}

void	draw_wall(mlx_image_t* img, int x, t_screenline draw)
{
	int	index;
	
	index = draw.start;
	while (index <= draw.end)
	{
		mlx_put_pixel(img, x, index, draw.color_wall);
		index++;
	}
}

void	draw_vertical_line(mlx_image_t* img, int x, t_screenline draw)
{
	draw_ceiling(img, x, draw);
	draw_wall(img, x, draw);
	draw_floor(img, x, draw);
}

void	calc_draw_line(t_game *g, t_ray *ray)
{
	int	lineheight;

	lineheight = (int)(screenHeight / ray->perpWallDist);
	ray->draw.start = screenHeight / 2 - lineheight / 2;
	if (ray->draw.start < 0)
		ray->draw.start = 0;
	ray->draw.end = screenHeight / 2 + lineheight / 2;
	if (ray->draw.end >= screenHeight)
		ray->draw.end = screenHeight - 1;
	ray->draw.color_wall = set_color_line(g, ray->map, ray->side);
	ray->draw.color_floor = darken_color(0xFFFFFFFF);
	ray->draw.color_ceiling = 0x00000000;
}
