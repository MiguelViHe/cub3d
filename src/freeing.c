/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:31:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/12 16:45:55 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_textures *textures)
{
	if (textures->NO)
		free(textures->NO);
	if (textures->SE)
		free(textures->SE);
	if (textures->WE)
		free(textures->WE);
	if (textures->EA)
		free(textures->EA);
	if (textures->F)
		free(textures->F);
	if (textures->C)
		free(textures->C);
	textures->NO = NULL;
	textures->SE = NULL;
	textures->WE = NULL;
	textures->EA = NULL;
	textures->F = NULL;
	textures->C = NULL;
}

int	free_parse_all(t_game *game, char *message)
{
	free_map_array(&game->map);
	free_textures(&game->data.textures);
	ft_lstclear(&game->map.map_list, free);
	ft_fdprintf(2, "Error\n%s\n", message);
	return (-1);
}

void	free_map_array(t_map *map)
{
	int	i;

	if (!map->matrix)
		return;
	i = 0;
	while (map->matrix[i])
	{
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
	map->matrix = NULL;
}

void	free_char_array(char **array)
{
	int	i;

	if (!array)
		return;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
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
