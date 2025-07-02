/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:56:52 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/27 16:49:49 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "MLX42.h"
# include "libft.h"


typedef struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

// typedef enum e_texture
// {
//     E1,
//     E2,
//     E3,
//     E4,
//     F,
//     C,
//     TEXTURE_COUNT
// }	t_texture;

typedef struct	s_textures
{
	char			symbol;
	char			*path;
	mlx_texture_t	*texture;
	uint32_t		color;
}				t_textures;

typedef struct	s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}				t_player;

typedef struct	s_map
{
	size_t		height;
	size_t		width;
	int			player_count;
	t_list		*map_list;
	char		**matrix;
	t_textures	textures[MAX_TEXTURES];

}				t_map;

typedef struct	s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	int32_t			screen_width; //No se si es necesario, pero lo dejo por si acaso
	int32_t			screen_height; // No se si es necesario, pero lo dejo por si acasou
}				t_data;

typedef struct	s_input
{
	bool	move_forward;
	bool	move_backward;
	bool	move_left;
	bool	move_right;
	bool	rotate_left;
	bool	rotate_right;
}				t_input;

typedef struct	s_game
{
	t_player	player;
	double		fov_degrees;
	double		fov_factor;
	t_map		map;
	t_data		data;
	t_input		input;
	bool		cursor_hidden;
}				t_game;

typedef struct	s_screenline
{
	int			start;
	int			end;
	int			lineheight;
	uint32_t	color_wall;
	uint32_t	*color_floor;
	uint32_t	*color_ceiling;
}				t_screenline;

typedef struct	s_tex_inf
{
	int				tx_dir;		// id de la textura a usar para pintar el muro.
	mlx_texture_t	*mlx_tx;	// Puntero a la textura que indica tx_dir.
	double			wallX;		// Punto exacto de impacto del rayo dentro de la celda del muro (0.0 - 1.0)
	t_coord			tx;			// Columna de textura que se usará para esta franja vertical
	double			tx_step;	// Cuántos píxeles de textura avanzamos por cada píxel vertical en pantalla
	double			tx_pos;		// Posición inicial en la textura.
	int				pixel_index; // Índice del píxel en la textura (para acceder a los colores)
}				t_tex_inf;

typedef struct	s_ray
{
	double			cameraX;		//Normalizacion de las columnas de pixels de la pantalla (-1 .. 0 .. 1)
	t_vector		dir;			//vector que indica la direccion a donde va el rayo.
	t_coord			map;			// posición actual en la grid/mapa
	t_vector		delta_dist;		// distancia a recorrer para pasar a la siguiente línea X o Y
	t_vector		side_dist;		// distancia acumulada desde el origen del rayo a la próxima línea X o Y
	t_coord			step;			// dirección de incremento en X e Y
	int				side;			// 0 si el muro es vertical, 1 si horizontal
	int				hit;			// 0 si aun no ha chocado con un muro, 1 si ha chocado.
	double			perpWallDist;	// distancia corregida hasta la pared perpendicular a plane.
	t_screenline	draw;			// inicio y final de pintado de una linea de pantalla respecto a la distancia del muro.
	t_tex_inf		tex_info;		// Información de textura para pintar el muro.
}				t_ray;

#endif // STRUCTS_H