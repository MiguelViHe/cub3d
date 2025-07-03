/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:31:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/03 10:45:21 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_textures *textures)
{
	int	i;

	i = 0;
	while (i < MAX_TEXTURES)
	{
		if (textures[i].texture)
		{
			mlx_delete_texture(textures[i].texture);
			textures[i].texture = NULL;
		}
		if (textures[i].path)
		{
			free(textures[i].path);
			textures[i].path = NULL;
		}
		i++;
	}
}

int	free_all(t_game *game, char **tokens, char *message)
{
	if (tokens)
		free_char_array(tokens);
	free_map_array(&game->map);
	free_textures(game->map.textures);
	ft_lstclear(&game->map.map_list, free);
	if (game->map.doors_info.doors_array)
		free(game->map.doors_info.doors_array);
	if (message)
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
	if (game->data.mlx)
	mlx_terminate(game->data.mlx);
	free_all(game, NULL, NULL);
	exit(EXIT_SUCCESS);
}
