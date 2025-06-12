/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:58:47 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/12 17:58:46 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

#define screenWidth 1920
#define screenHeight 1080

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <stdlib.h> //atoi, atof
# include <math.h>
# include <string.h> //strlen
# include "structs.h"
# include "libft.h"

//game/game.c
int		launch_game(t_game *game);

//hooks/hooks.c
void	on_destroy(void *param);
void	on_keypress(mlx_key_data_t keydata, void *param);
void	on_game_loop(void *param);

//map/check_map.c
int		check_map(t_game *g);

//map/generate_map.c
void		generate_map(char *map_name, t_map *map);

//map/map_errors.c
void		wrong_map_exit(char *buffer, char *message, int need_free);
void		wrong_generate_map_exit(char *message, int fd);
void		check_arg_cub(char *name);

//parse/parse_file.c
int			parse_file(char *map_name, t_game *game);

//player/calculate_player.c
double		calc_fov_factor(double fov_degrees);
t_vector	calc_player_dir(char dir);
t_vector	calc_plane(t_vector dir, double fov_factor);
void		initialize_player(t_map *map, t_player *player);
int			is_player(char c);

//player/player_movements.c
void		rotate_player(t_game *game, double angle);
void		move_player_forward(t_game *game, double moveSpeed);
void		move_player_backward(t_game *game, double moveSpeed);
void		strafe_player_left(t_game *game, double moveSpeed);
void		strafe_player_right(t_game *game, double moveSpeed);

//ray/calculate_ray.c
double		calc_cameraX(int x);
t_vector	calc_ray_dir(t_vector dir, t_vector plane, double cameraX);
void		set_ray_pos(t_ray *ray, t_game *game);
void		calc_delta_dist(t_ray *ray);
void		calc_step_dir(t_ray *ray);
void		calc_side_dist(t_ray *ray, t_vector *player_pos);

//ray/dda.c
void		setup_dda(t_ray *ray, t_game *game);
void		raycast_dda(t_ray *ray, t_game *g);

//ray/raycast.c
void		cast_all_rays(t_game *g);

//checkers.c
int			dir_ok(char *dir);

//color.c
uint32_t	set_color_line(t_game *g, t_coord map, int wall_side);
uint32_t	darken_color(uint32_t color);

//draw.c
void		draw_vertical_line(mlx_image_t*	img, int x, t_screenline draw);
void		calc_draw_line(t_game *g, t_ray *ray);

//files.c
int			secure_open(char *map_name);
void		secure_close(int fd);

//freeing.c
void		free_map_array(t_map *map);
void		free_game(t_game *game);
void		free_char_array(char **array);
void		free_textures(t_textures *textures);
int			free_parse_all(t_game *game, char *message);

//printer.c
void		print_game_info(t_game *game);
void		print_game_map(char **map);

//time.c
// void		init_time(t_time *time);
// void		upgrade_frameTime(t_time *time);

//transform.c
double		deg_to_rad(double degrees);
void		rotate_vector(t_vector *vect, double angle);
t_vector	normalize(t_vector vect);
void		remove_newline(char *line);
void		fill_with_spaces(char *dest, const char *src, int width);

#endif

