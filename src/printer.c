/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:00:24 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/10 15:33:41 by mvidal-h         ###   ########.fr       */
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
	}
	ft_printf("\n");
}