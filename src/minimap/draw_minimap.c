/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:12:50 by daniel            #+#    #+#             */
/*   Updated: 2025/07/18 15:26:53 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	get_hit_point(t_game *g, t_ray *ray)
{
	t_vector	hit;

	hit.x = g->player.pos.x + ray->dir.x * ray->perpWallDist;
	hit.y = g->player.pos.y + ray->dir.y * ray->perpWallDist;
	return (hit);
}

void	ft_draw_player_dir(mlx_image_t *img, t_game *g)
{
	t_ray		ray;
	float		x;
	t_vector	start;
	t_vector	end_world;
	t_vector	end_minimap;

	if (!img || !g)
		return;
	start.x = g->player.pos.x * g->map.minimap.scale;
	start.y = g->player.pos.y * g->map.minimap.scale;
	x = 0;
	while (x < g->data.screen_width && x < (float)g->data.img->width)
	{
		ray.cameraX = calc_cameraX(x);
		ray.dir = calc_ray_dir(g->player.dir, g->player.plane, ray.cameraX);
		setup_dda(&ray, g);
		raycast_dda(&ray, g);

		// calcular punto exacto de impacto en el mundo
		end_world = get_hit_point(g, &ray);

		// convertir a píxeles del minimapa
		end_minimap.x = end_world.x * g->map.minimap.scale;
		end_minimap.y = end_world.y * g->map.minimap.scale;

		if (end_minimap.x >= 0 && end_minimap.y >= 0
			&& end_minimap.x < img->width && end_minimap.y < img->height)
			ft_draw_line(img, start, end_minimap, MINIMAP_COLOR_LINE);

		x += MINIMAP_GRANULARITY_LINE;
	}
}

void	ft_draw_player(mlx_image_t *img, t_game *g)
{
	size_t		player_pixel;
	t_vector	pos;

	if (!img || !g)
		return ;
	player_pixel = ceil(g->map.minimap.scale / 2); // Tamaño del jugador en píxeles
	pos.x = g->player.pos.x * (g->map.minimap.scale) - player_pixel / 2; // Escalar la posición del jugador
	pos.y = g->player.pos.y * (g->map.minimap.scale) - player_pixel / 2; // Escalar la posición del jugador
	if (pos.x < 0 || pos.y < 0 || pos.x >= (int)img->width || pos.y >= (int)img->height)
		return ;
	ft_draw_player_dir(img, g); // Dibuja la dirección del jugador
	ft_draw_tile(img, pos, player_pixel, MINIMAP_COLOR_PLAYER); // Dibuja el jugador en rojo
}

void ft_draw_minimap_image(t_minimap *minimap, mlx_t *mlx, t_vector minimap_pos)
{
	if (!minimap || !minimap->img || !mlx)
		return;
	minimap->instance = mlx_image_to_window(mlx, minimap->img, minimap_pos.x, minimap_pos.y);
}

int is_printable_tile(char tile, bool draw_walls)
{
	if (draw_walls)
		return (tile != 'D' && tile != '0' && tile != ' ');
	return (tile == 'D' || tile == '0' || tile == ' ');
}

//añadido parametro draw_walls para decidir si dibujar paredes o no
//si draw_walls es true, se dibujan las paredes, si es false, no se dibujan
//Se usa para poder dibujar los muros despues de dibujar los rayos del jugador.
//ya que si se dibujaban antes los rayos se metian encima de los muros.
//de esta manera los muros al ser pintados despues tapan a los rayos que se pasan. 
void ft_draw_minimap_grid(mlx_image_t *img, t_map *map, double scale, bool draw_walls)
{
	size_t	x;
	size_t	y;
	char	tile;

	if (!img || !map || !img->pixels)
		return ;
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			tile = map->matrix[y][x];
			if (is_printable_tile(tile, draw_walls))
				ft_draw_by_tile(tile, img, 
					(t_vector){x * scale, y * scale}, scale);
			y++;
		}
		x++;
	}
}

void ft_draw_minimap(t_minimap *minimap, t_game *g)
{
	t_vector	draw_pos;

	if (!minimap->img || !MINIMAP || !g || !g->data.mlx)
		return ;
	ft_bzero(&draw_pos, sizeof(t_vector));
	draw_pos.x = g->data.screen_width - minimap->width - 10; // 10 pixels from the right edge
	draw_pos.y = 40;
	if (!minimap->img->instances)
		ft_draw_minimap_image(minimap, g->data.mlx, draw_pos);
	ft_draw_minimap_grid(minimap->img, &g->map, minimap->scale, false);
	ft_draw_player(minimap->img, g);
	ft_draw_minimap_grid(minimap->img, &g->map, minimap->scale, true);
	mlx_set_instance_depth(&minimap->img->instances[minimap->instance], 1);
	mlx_set_instance_depth(&g->data.img->instances[g->data.instance], 0);
}
