/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:34:31 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/03 12:26:42 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	count_doors(t_map *map)
{
	size_t	count;
	size_t	y;
	size_t	x;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (is_door_symbol(map->matrix[y][x]))
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	set_doors_array(t_map *map, t_door *doors_array)
{
	size_t	y;
	size_t	x;
	size_t	index;

	index = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (is_door_symbol(map->matrix[y][x]))
			{
				doors_array[index].x = x;
				doors_array[index].y = y;
				doors_array[index].open = 0; // 0 = closed, 1 = open
				doors_array[index].anim_state = 0.0; // Initial animation state
				index++;
			}
			x++;
		}
		y++;
	}
}
			

int	init_doors(t_map *map, t_doors *d_inf)
{
	d_inf->doors_count = count_doors(map);
	if (d_inf->doors_count > 0)
	{
		d_inf->doors_array = ft_calloc(d_inf->doors_count, sizeof(t_door));
		if (!d_inf->doors_array)
			return (-1);
		set_doors_array(map, d_inf->doors_array);
	}
	return (0);
}
