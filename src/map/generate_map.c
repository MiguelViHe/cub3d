/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:34:03 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/12 18:06:31 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	generate_map(char *map_name, t_map *map)
{
	int		fd;
	size_t	i;
	char	*buffer;

	fd = secure_open(map_name);
	map->matrix = ft_calloc(map->height + 1, sizeof(char *));
	if (map->matrix == NULL)
		wrong_generate_map_exit("Error allocating memory for map array", fd);
	i = 0;
	buffer = get_next_line(fd);
	while (buffer)
	{
		map->matrix[i++] = buffer;
		buffer = get_next_line(fd);
	}
	if (i != map->height)
	{
		free_map_array(map);
		wrong_generate_map_exit("Error reading lines to generate the map", fd);
	}
	secure_close(fd);
}
