/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:56:52 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/29 13:40:41 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct	s_game
{
	t_vector	player_pos;
	t_vector	player_dir;
	double		fov_degrees;
	double		fov_factor;
	t_vector	plane;
	double		cameraX;
	t_vector	ray_dir;
}				t_game;