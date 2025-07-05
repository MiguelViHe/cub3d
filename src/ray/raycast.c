/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:45:42 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/04 13:14:22 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cast_all_rays(t_game *g)
{
	int		x;
	t_ray	ray;

	ft_memset(&ray, 0, sizeof(t_ray));
	x = 0;
	while (x < screenW)
	{
		ray.cameraX = calc_cameraX(x);
		ray.dir = calc_ray_dir(g->player.dir, g->player.plane, ray.cameraX);
		setup_dda(&ray, g);
		raycast_dda(&ray, g);
		calc_draw_line(g, &ray);
		if (TEXTURES)
			if (calc_tex_inf(g, &ray) < 0)
				return (-1);
		draw_vertical_line(g, x, &ray);
		x++;
	}
	return (0);
}
