/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:33:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/09 16:32:07 by mvidal-h         ###   ########.fr       */
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