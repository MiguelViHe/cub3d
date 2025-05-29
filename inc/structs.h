/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:56:52 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/29 17:42:19 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct	s_time
{
	double	prev;
	double	current;
}				t_time;

typedef struct	s_game
{
	t_vector	player_pos;
	t_vector	player_dir;
	double		fov_degrees;
	double		fov_factor;
	t_vector	plane;
	t_time		time;
}				t_game;

typedef struct	s_ray
{
	double		cameraX;
	t_vector	dir;
}				t_ray;