/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:58:47 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/04 16:27:56 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

#define screenWidth 640
#define screenHeight 480

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <stdlib.h> //atoi, atof
# include <math.h>
# include <string.h> //strlen
# include "structs.h"
# include "libft.h"

//transform.c
double		deg_to_rad(double degrees);
void		rotate_vector(t_vector *vect, double angle);
t_vector	normalize(t_vector vect);

//printer.c
void		print_game_info(t_game *game);
void    	print_game_map(char **map);

//calculate_player.c
double		calc_fov_factor(double fov_degrees);
t_vector	calc_player_dir(char dir);
t_vector	calc_plane(t_vector dir, double fov_factor);
void	    initialize_player(t_map *map, t_player *player);

//calculate_ray.c
double		calc_cameraX(int x);
t_vector	calc_ray_dir(t_vector dir, t_vector plane, double cameraX);
void		set_ray_pos(t_ray *ray, t_game *game);
void		calc_delta_dist(t_ray *ray);
void		calc_step_dir(t_ray *ray);
void		calc_side_dist(t_ray *ray, t_vector *player_pos);

//checkers.c
int			dir_ok(char *dir);

//rotate_player.c
void	rotate_player(t_game *game, double angle);

//so_long/generate_map.c
void	generate_map(char *map_name, t_map *map);

//so_long/map_errors.c
void	wrong_map_exit(char *buffer, char *message, int need_free);
void	wrong_generate_map_exit(char *message, int fd);

//so_long/freeing.c
void	free_map_array(t_map *map);

//so_long/files.c
int	    secure_open(char *map_name);
void	secure_close(int fd);

//so_long/check_map.c
int	    init_map_height(char *map_name);

#endif

