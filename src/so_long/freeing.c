/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:31:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/09 11:44:46 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map_array(t_map *map)
{
	int	i;

	i = 0;
	while (map->matrix[i])
	{
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
	map->matrix = NULL;
}

void	free_game(t_game *game)
{
	if (game->data.img)
		mlx_delete_image(game->data.mlx, game->data.img);
	mlx_close_window(game->data.mlx);
	if (game->map.matrix)
		free_map_array(&game->map);
	if (game->data.mlx)
		mlx_terminate(game->data.mlx);
	exit(EXIT_SUCCESS);
}
