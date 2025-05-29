/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:56:52 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/29 08:57:21 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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