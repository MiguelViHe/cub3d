/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:40:59 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/02 14:12:29 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	elems_required_loaded(t_textures *textures)
{
	int	i;

	i = 0;
	//1. Colores de techo y suelo definidos
	if (!textures['F'].path || !textures['C'].path)
		return (0);
	// 2. Al menos una textura para algún símbolo (excepto F y C o espacio)
	while (i < MAX_TEXTURES)
	{
		if (i != 'F' && i != 'C' && textures[i].path)
			return (1); // hay al menos una textura válida.
		i++;
	}
	return (0); // no hay textura para ningún símbolo del mapa
}

int	set_texture(char **tks, t_game *g)
{
	int	result;
	
	if (ft_pmatch_str(tks[0], "F", 1) || ft_pmatch_str(tks[0], "C", 1))
	{
		if (!tks[1] || tks[2])
			return (free_all(g, tks, "Bad format for color"));
		if (g->map.textures[(int)tks[0][0]].path)
			return (free_all(g, tks, "Duplicate floor/ceiling"));
		g->map.textures[(int)tks[0][0]].path = ft_strdup(tks[1]);
		result = set_surface_color(g, tks[0][0]);
	}
	else if (ft_pmatch_str(tks[0], "T", 1) && tks[1] && tks[2] && !tks[3])
	{
		if (is_reserved_symbol(tks[1][0]))
			return (free_all(g, tks, "Cannot redefine reserved symbol"));
		if (g->map.textures[(int)tks[1][0]].path)
			return (free_all(g, tks, "Duplicate texture"));
		g->map.textures[(int)tks[1][0]].symbol = tks[1][0];
		g->map.textures[(int)tks[1][0]].path = ft_strdup(tks[2]);
		result = ft_load_texture(g, &g->map.textures[(int)tks[1][0]]);
	}
	else
		return (free_all(g, tks, "Unknown config line. Expected F, C or T"));
	return (free_char_array(tks), result);
}

int	adding_map_line(char *line, t_game *g)
{
	t_list	*new_node;

	g->map.player_count += is_player_inline(line);
	if (g->map.player_count > 1)
		return (free_all(g, NULL, "Too many players in the map"));
	new_node = ft_lstnew(ft_strdup(line));
	if (!new_node)
		return (free_all(g, NULL, "Adding map line"));
	ft_lstadd_back(&g->map.map_list, new_node);
	g->map.height++;
	if (g->map.width < ft_strlen(line))
		g->map.width = ft_strlen(line);
	return (0); // valid map line, continue checking
}


int	parse_line(char *line, t_game *g)
{
	char	**tokens;
	char	*cleaned;

	if (line[0] == '\n')
	{
		if (g->map.map_list == NULL) // empty line before map
			return (0); // continue checking
		return (free_all(g, NULL, "Empty line after map beginning"));
	}
	remove_newline(line);
	if (is_map_line(g->map.textures, line))
	{
		if (!elems_required_loaded(g->map.textures))
			return (free_all(g, NULL, "Missing required elem or is after map"));
		return (adding_map_line(line, g));
	}
	if (g->map.map_list != NULL)
		return (free_all(g, NULL, "Bad elements in map"));
	cleaned = remove_spaces(line);
	if (!cleaned)
		return (free_all(g, NULL, "Removing spaces from line"));
	tokens = ft_split(cleaned, ' ');
	if (!tokens || !tokens[0])
		return (free(cleaned), free_all(g, NULL, "Invalid texture or color"));
	return (free(cleaned), set_texture(tokens, g));
}

int	parse_file(char *map_name, t_game *g)
{
	int		fd;
	int		error;
	char	*buffer;

	error = 0;
	fd = secure_open(map_name);
	buffer = get_next_line(fd);
	if (buffer == NULL)
		return (free_all(g, NULL, "Reading line from file"));
	while (buffer && !error)
	{
		error = parse_line(buffer, g);
		free(buffer);
		if (!error)
			buffer = get_next_line(fd);
	}
	secure_close(fd);
	if (error)
		return (error);
	if (!elems_required_loaded(g->map.textures) || !g->map.map_list)
		return (free_all(g, NULL, "Required elems and map are needed"));
	return (check_map(g));
}
