/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:49:22 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/28 16:52:14 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h> //atoi, atof
#include <math.h>
#include <string.h> //strlen

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif
#define screenWidth 640
#define screenHeight 480

typedef struct	s_player_pos
{
	float	pos_x;
	float	pos_y;
}				t_player_pos;

typedef struct	s_player_dir
{
	float	dir_x;
	float	dir_y;
}				t_player_dir;

typedef struct	s_plane
{
	float	plane_x;
	float	plane_y;
}				t_plane;

typedef struct	s_ray_dir
{
	float	ray_x;
	float	ray_y;
}				t_ray_dir;

typedef struct	s_game
{
	t_player_pos	player_pos;
	t_player_dir	player_dir;
	float			fov_degrees;
	float			fov_factor;
	t_plane			plane;
	float			cameraX;
	t_ray_dir		ray_dir;
}				t_game;

float	deg_to_rad(float degrees) {
	return degrees * (M_PI / 180.0f);
}

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

t_game	init_game(char *argv[])
{
	t_game	game;

	game.player_pos.pos_x = atoi(argv[1]);
	game.player_pos.pos_y = atoi(argv[2]);
	game.player_dir = calculate_player_dir(argv[3][0]);
	game.fov_degrees = atof(argv[4]);
	game.fov_factor = calculate_fov_factor(game.fov_degrees);
	game.plane = calculate_plane(game.player_dir, game.fov_factor);
	game.cameraX = calculate_cameraX(atoi(argv[5]));
	game.ray_dir = calculate_ray_dir(game.player_dir, game.plane, game.cameraX);
	return (game);
}

int	dir_ok(char *dir)
{
	if (strlen(dir) == 1 
		&& (dir[0] == 'N' 
			|| dir[0] == 'S' 
			|| dir[0] == 'E' 
			|| dir[0] == 'W'))
		return (1);
	return (0);
}

void	print_game_info(t_game game)
{
	printf("player pos = [%f, %f]\n", game.player_pos.pos_x, game.player_pos.pos_y);
	printf("player dir = [%f, %f]\n", game.player_dir.dir_x, game.player_dir.dir_y);
	printf("fov_degrees = %f\n", game.fov_degrees);
	printf("fov_factor = %f\n", game.fov_factor);
	printf("plane = [%f, %f]\n", game.plane.plane_x, game.plane.plane_y);
	printf("cameraX = %f\n", game.cameraX);
	printf("ray_dir = [%f, %f]\n", game.ray_dir.ray_x, game.ray_dir.ray_y);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 6 || !dir_ok(argv[3]))
	{
		printf("Bad args. Try x_pos y_pos init_dir (N, S, E or W), fov (in degrees) and pixels_column\n");
		return (0);
	}
	game = init_game(argv);
	print_game_info(game);
	return (0);
}