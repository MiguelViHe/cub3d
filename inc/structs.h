/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:56:52 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/03 17:37:15 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

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
	t_coord		map;			// posición actual en la grid/mapa
	t_vector	delta_dist;		// distancia a recorrer para pasar a la siguiente línea X o Y
	t_vector	side_dist;		// distancia acumulada desde el origen del rayo a la próxima línea X o Y
	t_coord		step;			// dirección de incremento en X e Y
	int			side;			// 0 si el muro es vertical, 1 si horizontal
	int			hit;			// 0 si aun no ha chocado con un muro, 1 si ha chocado.
	double		perpWallDist;	// distancia corregida hasta la pared
}				t_ray;