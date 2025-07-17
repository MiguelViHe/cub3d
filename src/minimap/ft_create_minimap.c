/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:29:23 by daniel            #+#    #+#             */
/*   Updated: 2025/07/17 17:36:51 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_calc_scale(int map_width, int map_height)
{
	double	max_width;
	double	max_height;
	t_vector	scale;

	if (map_width <= 0 || map_height <= 0)
		return (1.0);
	max_width = screenW * MINIMAP_MAX_RATIO;
	max_height = screenH * MINIMAP_MAX_RATIO;
	scale.x = max_width / map_width;
	scale.y = max_height / map_height;
	return (fmin(scale.x, scale.y));
}

t_minimap	ft_create_minimap(t_game *g, t_map *map)
{
	t_minimap	minimap;
	double		scale;

	if (!map)
		return ((t_minimap){0});
	ft_bzero(&minimap, sizeof(t_minimap));
	scale = ft_calc_scale(map->width, map->height);
	minimap.width = ceil(map->width * scale) + 1;
	minimap.height = ceil(map->height * scale) + 1;
	minimap.scale = scale;
	minimap.enabled = MINIMAP;
	minimap.img = mlx_new_image(g->data.mlx, minimap.width, minimap.height);
	if (!minimap.img)
		return ((t_minimap){0});
	return (minimap);
}