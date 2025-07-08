/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:58:47 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/08 13:42:17 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

#ifndef CUB3D_H
# define CUB3D_H

# define	TITLE "Cub3D"
# define	TILE_SIZE 2048 //No usada. leer draw.c

# define 	MAX_TEXTURES 128 // 1 por cada caracter ASCII válido

//configuration 
# define	TEXTURES 		true
# define	MINIMAP 		false

//window configuration
# define	STRETCH_IMAGE	true
# define	FULLSCREEN		true

// Player configuration
# define	PLAYER_SPEED 3.0
# define	PLAYER_ROTATION_SPEED 1.5
# define	MOUSE_ROTATION_SPEED 0.05
# define	FOV_DEGREES 66.0
# define	MARGIN_WALL 0.2 // Margin representing the body space of the player, used to avoid collisions with walls

// Door configuration
# define	DOOR_SYMBOL 'D' // Symbol representing a door in the map
// # define	DOOR_BASE_SPEED 0.05 // Speed of door opening/closing animation in units per second BUENA
// # define    DOOR_ACCELERATION 0.6   // aceleración (unidades por segundo^2) BUENA
// # define    MAX_DOOR_SPEED   2.0 BUENA
# define    DOOR_ANIM_TIME 3 // segundos



// Raycasting configuration
# define		screenW 1280
# define		screenH 720

// Macros
# define TOGGLE(x) ((x) = !(x))

# include <stdio.h>
# include <stdlib.h> //atoi, atof
# include <math.h>
# include <string.h> //strlen
# include "structs.h"
# include "libft.h"

//doors/actions.c
void		toggle_door(t_door *door);

//doors/animation.c
void		update_doors_animation(t_game *g, double delta_time);

//doors/check_door.c
int			is_door_symbol(char c);
bool		is_door_open(t_game *g, int x, int y);
t_door		*find_door(t_game *g, int x, int y);

//game/game.c
int			launch_game(t_game *game);

//hooks/hooks_utils.c
void		update_mouse_rotation(t_game *g, double rotSpeed);
void		update_player_movement(t_game *g, double moveSpeed, double rotSpeed);
void		update_doors_touch_timer(t_game *g);
void		process_scape_key(t_game *g);
void		process_action_key(t_game *g);

//hooks/hooks.c
void		on_destroy(void *param);
void		on_keypress(mlx_key_data_t keydata, void *param);
void		on_mouse_button(mouse_key_t btn, action_t act, modifier_key_t mod, void *p);
void		on_game_loop(void *param);

//map/check_map.c
int			is_border_elem(t_game *g, char c);
int			check_map(t_game *g);

//map/generate_map_array.c
int			generate_map_array(t_game *g);

//parse/parse_checkers.c
bool		is_reserved_symbol(char c);
int			is_map_line(t_textures *tx, char *line);
int			is_player_inline(char *line);

//parse/parse_doors.c
int			init_doors(t_map *map, t_doors *d_inf);

//parse/parse_file.c
int			parse_file(char *map_name, t_game *game);

//player/calculate_player.c
double		calc_fov_factor(double fov_degrees);
t_vector	calc_player_dir(char dir);
t_vector	calc_plane(t_vector dir, double fov_factor);

//player/initialize_player.c
void		initialize_player(t_map *map, t_player *player);

//player/player_movements.c
void		rotate_player(t_game *game, double angle);
void		move_player_forward(t_game *game, double moveSpeed);
void		move_player_backward(t_game *game, double moveSpeed);
void		strafe_player_left(t_game *game, double moveSpeed);
void		strafe_player_right(t_game *game, double moveSpeed);

//player/player_utils.c
void		can_walk(t_game *game, double new_x, double new_y, t_vector dir);
int			is_wall(t_game *g, double x, double y);
int			is_player(char c);

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
int			cast_all_rays(t_game *g);

//textures/textures.c
int			ft_load_texture(t_game *g, t_textures *texture);

//textures/calculate_texture.c
double		calc_wallx(t_game *g, t_ray *ray);
void		calc_wallx_and_texx(t_game *g, t_ray *ray);
void		calc_step_and_pos(double *step, double *pos, t_ray *r, int lineheight);
int			calc_tex_inf(t_game *g, t_ray *ray);

//checkers.c
int			dir_ok(char *dir);
void		check_arg_cub(char *name);

//color.c
int			set_surface_color(t_game *g, int s);
uint32_t	set_color_line(t_game *g, t_coord map, int wall_side);
uint32_t	darken_color(uint32_t color);

//draw.c
void		draw_vertical_line(t_game *g, int x, t_ray *ray);
void		calc_draw_line(t_game *g, t_ray *ray);

//files.c
int			secure_open(char *map_name);
void		secure_close(int fd);

//freeing.c
void		free_map_array(t_map *map);
void		free_game(t_game *game);
void		free_char_array(char **array);
void		free_textures(t_textures *textures);
int			free_all(t_game *game, char **tokens, char *message);

//ft_get_time.c
double		ft_get_time(void);

//printer.c
void		print_game_info(t_game *game);
void		print_game_map(char **map);
void		print_door_info(t_doors d_inf);

//transform.c
double		deg_to_rad(double degrees);
void		rotate_vector(t_vector *vect, double angle);
t_vector	normalize(t_vector vect);

// utils.c
int			ft_clamp(int value, int min, int max);
void		remove_newline(char *line);
char		*remove_spaces(char *str);
void		fill_with_spaces(char *dest, const char *src, int width);
int			sign(double x);

#endif

