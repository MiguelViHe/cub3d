/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculators.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:07:01 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/29 10:07:42 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	calculate_fov_factor(float fov_degrees)
{
	float	half_angle_rad;

	half_angle_rad = deg_to_rad(fov_degrees / 2.0f);
	return (tanf(half_angle_rad));
}

t_player_dir	calculate_player_dir(char dir)
{
	t_player_dir	player_dir;

	if (dir == 'N' || dir == 'S')
		player_dir.dir_x = 0;
	if (dir == 'N')
		player_dir.dir_y = -1;
	if (dir == 'S')
		player_dir.dir_y = 1;
	if (dir == 'E' || dir == 'W')
		player_dir.dir_y = 0;
	if (dir == 'E')
		player_dir.dir_x = 1;
	if (dir == 'W')
		player_dir.dir_x = -1;
	return (player_dir);
}

t_plane	calculate_plane(t_player_dir dir, float fov_factor)
{
	t_plane	plane;

	plane.plane_x = (-dir.dir_y) * fov_factor;
	plane.plane_y = dir.dir_x * fov_factor;
	return (plane);
}

float	calculate_cameraX(int x)
{
	return (2.0f * x / (float)screenWidth - 1.0f);
}

t_ray_dir	calculate_ray_dir(t_player_dir dir, t_plane plane, float cameraX)
{
	t_ray_dir	ray_dir;

	ray_dir.ray_x = dir.dir_x + plane.plane_x * cameraX;
	ray_dir.ray_y = dir.dir_y + plane.plane_y * cameraX;
	return (ray_dir);
}