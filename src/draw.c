/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:33:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/06 16:43:03 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_vertical_line(mlx_image_t*	img, int x, t_screenline draw)
{
	int	index;
	
	index = draw.start;
	while (index <= draw.end)
	{
		mlx_put_pixel(img, x, index, draw.color);
		index++;
	}
}