/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:22:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/16 12:13:15 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_doors_animation(t_game *g, double delta_time)
{
	size_t	i;
	t_door	*d;
	double	now;
	double progress;

	i = 0;
	now = ft_get_time();
	while (i < g->map.doors_info.doors_count)
	{
		d = &g->map.doors_info.doors_array[i++];
		if (d->open && (now - d->timer >= DOOR_OPEN_TIME))
			d->open = false;
		if (d->open && d->anim_state < 1.0)
			d->anim_elapsed += delta_time;
		else if (!d->open && d->anim_state > 0.0)
			d->anim_elapsed -= delta_time;
		d->anim_elapsed = ft_clamp_double(d->anim_elapsed, 0.0, DOOR_ANIM_TIME);
		progress = d->anim_elapsed / DOOR_ANIM_TIME;
		d->anim_state = 0.5 - 0.5 * cos(progress * M_PI);
	}
}
