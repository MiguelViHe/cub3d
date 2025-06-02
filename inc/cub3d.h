/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:58:47 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/02 16:56:16 by mvidal-h         ###   ########.fr       */
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

//transform.c
double		deg_to_rad(double degrees);
void		rotate_vector(t_vector *vect, double angle);
t_vector	normalize(t_vector vect);

//printer.c
void		print_game_info(t_game *game);

//calculate_player.c
double		calculate_fov_factor(double fov_degrees);
t_vector	calculate_player_dir(char dir);
t_vector	calculate_plane(t_vector dir, double fov_factor);

//calculate_ray.c
double		calculate_cameraX(int x);
t_vector	calculate_ray_dir(t_vector dir, t_vector plane, double cameraX);
void		set_ray_pos(t_ray *ray, t_game *game);
void		calculate_delta_dist(t_ray *ray);
void		calculate_step_dir(t_ray *ray);
void		calculate_side_dist(t_ray *ray, t_vector *player_pos);

//checkers.c
int			dir_ok(char *dir);

//rotate_player.c
void	rotate_player(t_game *game, double angle);

#endif

