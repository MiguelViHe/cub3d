/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:11:16 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/20 13:09:47 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_load_texture(t_game *g, t_textures *texture)
{
	if (!texture || !texture->path)
		return (free_all(g, NULL, "Texture doesn't exist"));
	texture->texture = mlx_load_png(texture->path);
	if (!texture->texture)
	{
		ft_fdprintf(2, "Error\n Failed to load texture from path: ");
		ft_fdprintf(2, texture->path);
		ft_fdprintf(2, "\n");
		return (free_all(g, NULL, NULL));
	}
	return (0);
}

// int ft_init_textures(t_game *game, t_map *map)
// {
// 	int	i;
	
// 	i = 0;
// 	while (i < TEXTURE_COUNT - 2) // Exclude F and C
// 	{
// 		printf("Loading texture %d: %s\n", i, map->textures[i].path);
// 		if (ft_load_texture(game, &map->textures[i]) < 0)
// 			return (-1);
// 		i++;
// 	}
// 	return (0);
// }