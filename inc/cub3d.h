/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:58:47 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/29 10:14:19 by mvidal-h         ###   ########.fr       */
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

//transform.h
float			deg_to_rad(float degrees);

//printer.h
void			print_game_info(t_game game);

//calculators.h
float			calculate_fov_factor(float fov_degrees);
t_player_dir	calculate_player_dir(char dir);
t_plane			calculate_plane(t_player_dir dir, float fov_factor);
float			calculate_cameraX(int x);
t_ray_dir		calculate_ray_dir(t_player_dir dir, t_plane plane, float cameraX);

//checkers.c
int	dir_ok(char *dir);

#endif

