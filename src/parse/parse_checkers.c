/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:40:04 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/01 19:53:43 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_special_symbol(char c)
{
	return (c == ' ' || c == '0' 
			|| c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static bool	is_color_symbol(char c)
{
	return (c == 'F' || c == 'C');
}

bool	is_reserved_symbol(char c)
{
	return (is_color_symbol(c) || is_special_symbol(c));
}

int	is_map_line(t_textures *tx, char *line)
{
	int		not_all_spaces;
	char	c;

	not_all_spaces = 0;
	while (*line)
	{
		c = *line;
		if (!is_special_symbol(c))
		{
			if (c == 'F' || c == 'C')
				return (0); // F y C son reservados para colores, no pueden ir en el mapa
			if (!tx[(int)c].path)
				return (0);
			not_all_spaces = 1;
		}
		line++;
	}
	return (not_all_spaces); // returns 1 if there is at least one non-space character
}

int	is_player_inline(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' 
			|| line[i] == 'W')
			return (1); // found a player character
		i++;
	}
	return (0); // no player character found
}