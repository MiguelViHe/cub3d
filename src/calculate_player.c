/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:07:01 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/10 10:36:05 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calc_fov_factor(double fov_degrees)
{
	double	half_angle_rad;

	half_angle_rad = deg_to_rad(fov_degrees / 2);
	return (tanf(half_angle_rad));
}

t_vector	calc_player_dir(char dir)
{
	t_vector	player_dir;

	if (dir == 'N' || dir == 'S')
		player_dir.x = 0;
	if (dir == 'N')
		player_dir.y = -1;
	if (dir == 'S')
		player_dir.y = 1;
	if (dir == 'E' || dir == 'W')
		player_dir.y = 0;
	if (dir == 'E')
		player_dir.x = 1;
	if (dir == 'W')
		player_dir.x = -1;
	return (player_dir);
}

t_vector	calc_plane(t_vector dir, double fov_factor)
{
	t_vector	plane;

	plane.x = -dir.y * fov_factor;
	plane.y = dir.x * fov_factor;
	return (plane);
}

void	initialize_player(t_map *map, t_player *player)
{
	int		i;
	int		j;
	int		found;

	i = 0;
	found = 0;
	while (!found && map->matrix[i])
	{
		j = 0;
		while (!found && map->matrix[i][j] && map->matrix[i][j] != '\n')
		{
			if (map->matrix[i][j] == 'N' || map->matrix[i][j] == 'S' 
				|| map->matrix[i][j] == 'E' || map->matrix[i][j] == 'W')
			{
				player->pos.x = j + 0.5;
				player->pos.y = i + 0.5;
				player->dir = calc_player_dir(map->matrix[i][j]);
				map->matrix[i][j] = '0'; // quitar el simbolo de inicio del jugador del mapa.
				found = 1;
			}
			j++;
		}
		i++;
	}
}
