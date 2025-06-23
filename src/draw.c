/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:33:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/23 18:47:01 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(mlx_image_t* img, int x, t_screenline *draw)
{
	int	index;

	index = 0;
	while (index < draw->start)
	{
		// printf("ceiling color: 0x%08X\n", *draw.color_ceiling);
		mlx_put_pixel(img, x, index, *draw->color_ceiling);
		index++;
	}
}

void	draw_floor(mlx_image_t* img, int x, t_screenline *draw)
{
	int	index;

	index = draw->end + 1;
	while (index <= screenH - 1)
	{
		// printf("floor color: 0x%08X\n", *draw.color_floor);
		mlx_put_pixel(img, x, index, *draw->color_floor);
		index++;
	}
}

void	set_color_texture(t_screenline *d, t_tex_inf *ti)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	ti->tx.y = (int)ti->tx_pos & (TILE_SIZE - 1); // clamp con máscara
	ti->tx_pos += ti->tx_step;
	ti->pixel_index = (ti->tx.y * ti->mlx_tx->width + ti->tx.x) * 4;
			
	r = ti->mlx_tx->pixels[ti->pixel_index];
	g = ti->mlx_tx->pixels[ti->pixel_index + 1];
	b = ti->mlx_tx->pixels[ti->pixel_index + 2];
	a = ti->mlx_tx->pixels[ti->pixel_index + 3];
	d->color_wall = (r << 24) | (g << 16) | (b << 8) | a;
}

void	draw_wall(mlx_image_t* img, int x, t_screenline *d, t_tex_inf *ti)
{
	int	index;
	
	index = d->start;
	while (index <= d->end)
	{
		if (TEXTURES)
			set_color_texture(d, ti);
		mlx_put_pixel(img, x, index, d->color_wall);
		index++;
	}
}

void	draw_vertical_line(t_game *g, int x, t_screenline *d, t_tex_inf *tinf)
{
	draw_ceiling(g->data.img, x, d);
	draw_wall(g->data.img, x, d, tinf);
	draw_floor(g->data.img, x, d);
}

void	calc_draw_line(t_game *g, t_ray *ray)
{
	int	lineheight;

	lineheight = (int)(screenH / ray->perpWallDist);
	ray->draw.start = screenH / 2 - lineheight / 2;
	if (ray->draw.start < 0)
		ray->draw.start = 0;
	ray->draw.end = screenH / 2 + lineheight / 2;
	if (ray->draw.end >= screenH)
		ray->draw.end = screenH - 1;
	if (!TEXTURES)
		ray->draw.color_wall = set_color_line(g, ray->map, ray->side);
	ray->draw.color_floor = &g->map.textures[F].color; //Punteros a los clorores ya calculados
	ray->draw.color_ceiling = &g->map.textures[C].color; //Punteros a los clorores ya calculados
	// ray->draw.tex = &ray->tex; // Puntero a la coordenada de textura
	// ray->draw.tex_id = &ray->texture_dir; // Puntero al identificador de la textura a usar
	// ray->draw.darken = &ray->side; // Puntero a la variable side que indica si se debe oscurecer la textura
}
