/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:31:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/04 14:35:20 by mvidal-h         ###   ########.fr       */
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

// void	free_mlx42_images(t_data *data)
// {
// 	if (data->img.empty)
// 		mlx_delete_image(data->mlx, data->img.empty);
// 	if (data->img.wall)
// 		mlx_delete_image(data->mlx, data->img.wall);
// 	if (data->img.collect)
// 		mlx_delete_image(data->mlx, data->img.collect);
// 	if (data->img.exit_o)
// 		mlx_delete_image(data->mlx, data->img.exit_o);
// 	if (data->img.exit_c)
// 		mlx_delete_image(data->mlx, data->img.exit_c);
// 	if (data->img.player)
// 		mlx_delete_image(data->mlx, data->img.player);
// 	if (data->img.winner)
// 		mlx_delete_image(data->mlx, data->img.winner);
// }

// void	free_mlx42_data(t_data *data)
// {
// 	free_mlx42_images(data);
// 	mlx_close_window(data->mlx);
// 	if (data->map)
// 		free_map_array(data->map);
// 	if (data->mlx)
// 		mlx_terminate(data->mlx);
// 	exit(EXIT_SUCCESS);
// }
