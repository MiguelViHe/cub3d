/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:50:11 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/12 18:33:01 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//CREATE_COLOR O ALGO ASI

uint32_t	get_wall_color(t_game *g, t_coord map)
{
	char	pos;
	
	pos = g->map.matrix[map.y][map.x];
	if (pos == '1')
		return 0xFF0000FF; // rojo
	if (pos == '2')
		return 0x00FF00FF; // verde
	if (pos == '3')
		return 0x0000FFFF; // azul
	if (pos == '4')
		return 0xFFFF00FF; // amarillo
	return 0xFFA500FF; // naranja por defecto
}

uint32_t darken_color(uint32_t color)
{
	uint8_t r = ((color >> 24) & 0xFF) / 2;
	uint8_t g = ((color >> 16) & 0xFF) / 2;
	uint8_t b = ((color >> 8) & 0xFF) / 2;
	uint8_t a = (color & 0xFF);

	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	set_color_line(t_game *g, t_coord map, int wall_side)
{
	uint32_t	color;

	color = get_wall_color(g, map);
	if (wall_side == 0)
		color = darken_color(color);
	return (color);
}