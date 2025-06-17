/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:50:11 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/17 17:39:18 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_to_hex(t_game *game, char *color_text, uint32_t *color)
{
	int		r;
	int		g;
	int		b;
	char	**tokens;

	tokens = ft_split(color_text, ',');
	if (!tokens)
		return (free_all(game, NULL, "setting floor or ceiling color"));
	if (!tokens[0] || !tokens[1] || !tokens[2] || tokens[3])
		return (free_all(game, tokens, "Invalid color format"));
	r = ft_atoi(tokens[0]);
	g = ft_atoi(tokens[1]);
	b = ft_atoi(tokens[2]);
	free_char_array(tokens);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (free_all(game, NULL, "Color must be 'R,G,B' with values 0–255"));
	*color = (r << 24) | (g << 16) | (b << 8) | 0xFF;
	return (0);
}

int	set_surface_color(t_game *g, char surface)
{

	if (surface == 'F')
		return (color_to_hex(g, g->data.textures.F, &g->data.color_floor));
	else if (surface == 'C')
		return (color_to_hex(g, g->data.textures.C, &g->data.color_ceiling));
	return (free_all(g, NULL, "Invalid surface type"));
}

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