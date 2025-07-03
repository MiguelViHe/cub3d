/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:00:24 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/03 11:09:41 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_game_info(t_game *game)
{
	printf("player pos = [%g, %g]\n", game->player.pos.x, game->player.pos.y);
	printf("player dir = [%g, %g]\n", game->player.dir.x, game->player.dir.y);
	printf("fov_degrees = %g\n", game->fov_degrees);
	printf("fov_factor = %g\n", game->fov_factor);
	printf("plane = [%g, %g]\n", game->player.plane.x, game->player.plane.y);
}

void	print_game_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		i++;
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	print_door_info(t_doors d_inf)
{
	size_t	i;

	if (d_inf.doors_count == 0)
		ft_printf("No doors in the map.\n");
	else
	{
		ft_printf("Doors info:\n");
		i = 0;
		while (i < d_inf.doors_count)
		{
			printf("Door %zu: Pos = [%d, %d], Open = %d, Animation = %.2f\n",
				i + 1,
				d_inf.doors_array[i].y,
				d_inf.doors_array[i].x,
				d_inf.doors_array[i].open,
				d_inf.doors_array[i].anim_state);
			i++;
		}
	}
}
