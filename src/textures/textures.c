/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:11:16 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/27 15:39:30 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_load_texture(t_game *g, t_textures *texture)
{
	if (!texture || !texture->path)
		return (free_all(g, NULL, "Texture doesn't exist"));
	texture->texture = mlx_load_png(texture->path);
	if (!texture->texture)
	{
		ft_fdprintf(2, "Error\n Failed to load texture from path: ");
		ft_fdprintf(2, texture->path);
		ft_fdprintf(2, "\n");
		return (free_all(g, NULL, NULL));
	}
	return (0);
}

// int	get_texture_direction(int side, t_vector ray_dir)
// {
// 	if (side == 0)
// 	{
// 		if (ray_dir.x < 0)
// 			return (EA);
// 		else
// 			return (WE);
// 	}
// 	else
// 	{
// 		if (ray_dir.y < 0)
// 			return (SO);
// 		else
// 			return (NO);
// 	}
// }

int	get_texture_elem_bonus(char e)
{
	if (e == '1')
		return (E1);
	else if (e == '2')
		return (E2);
	else if (e == '3')
		return (E3);
	else if (e == '4')
		return (E4);
	else
		return (-1);
}