/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:56:52 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/29 12:37:13 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_player_pos
{
	double	pos_x;
	double	pos_y;
}				t_player_pos;

typedef struct	s_player_dir
{
	double	dir_x;
	double	dir_y;
}				t_player_dir;

typedef struct	s_plane
{
	double	plane_x;
	double	plane_y;
}				t_plane;

typedef struct	s_ray_dir
{
	double	ray_x;
	double	ray_y;
}				t_ray_dir;

typedef struct	s_game
{
	t_player_pos	player_pos;
	t_player_dir	player_dir;
	double			fov_degrees;
	double			fov_factor;
	t_plane			plane;
	double			cameraX;
	t_ray_dir		ray_dir;
}				t_game;