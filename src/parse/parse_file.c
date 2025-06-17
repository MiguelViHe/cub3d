/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:40:59 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/17 18:41:08 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	all_elem(t_textures *textures)
{
	if (textures->NO && textures->SE && textures->WE && textures->EA
		&& textures->F && textures->C)
		return (1);
	return (0);
}

int	set_texture(char **tokens, t_game *g)
{
	if (!tokens || !tokens[0] || !tokens[1] || tokens[2])
		return (free_all(g, tokens, "bad format in texture"));
	if (strncmp(tokens[0], "NO", 2) == 0 && !g->data.textures.NO)
		g->data.textures.NO = ft_strdup(tokens[1]);
	else if (strncmp(tokens[0], "SO", 2) == 0 && !g->data.textures.SE)
		g->data.textures.SE = ft_strdup(tokens[1]);
	else if (strncmp(tokens[0], "WE", 2) == 0 && !g->data.textures.WE)
		g->data.textures.WE = ft_strdup(tokens[1]);
	else if (strncmp(tokens[0], "EA", 2) == 0 && !g->data.textures.EA)
		g->data.textures.EA = ft_strdup(tokens[1]);
	else if (strncmp(tokens[0], "F", 1) == 0 && !g->data.textures.F)
	{
		g->data.textures.F = ft_strdup(tokens[1]); //aqui y ademas trim en colores
		return (set_surface_color(g, 'F'));
	}
	else if (strncmp(tokens[0], "C", 1) == 0 && !g->data.textures.C)
	{
		g->data.textures.C = ft_strdup(tokens[1]);
		return (set_surface_color(g, 'C'));
	}
	else
		return (free_all(g, tokens, "Invalid texture or color format"));
	return (0);
}

int	is_map_line(char *line)
{
	int not_all_spaces;

	not_all_spaces = 0;
	while (*line)
	{
		if (*line != ' ' && *line != '0' && *line != '1' &&
			*line != 'N' && *line != 'S' && *line != 'E' && *line != 'W')
			return (0);
		if (*line != ' ')
			not_all_spaces = 1;
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
	int		is_mapline;

	if (line[0] == '\n')
	{
		if (g->map.map_list == NULL) // empty line before map
			return (0); // continue checking
		return (free_all(g, NULL, "Empty line after map beginning"));
	}
	remove_newline(line);
	is_mapline = is_map_line(line);
	if (is_mapline)
	{
		if (!all_elem(&g->data.textures))
			return (free_all(g, NULL, "Map is not the last element"));
		return (adding_map_line(line, g));
	}
	if (!is_mapline && g->map.map_list != NULL)
		return (free_all(g, NULL, "Bad elements in map"));
	tokens = ft_split(line, ' ');
	if (tokens == NULL)
		return (free_all(g, NULL, "Checking texture or color"));
	return (set_texture(tokens, g));
}

int	parse_file(char *map_name, t_game *game)
{
	int		fd;
	int		error;
	char	*buffer;

	error = 0;
	fd = secure_open(map_name);
	buffer = get_next_line(fd);
	if (buffer == NULL)
		wrong_map_exit(buffer, "Error\nReading line from file", -1);
	while (buffer && !error)
	{
		error = parse_line(buffer, game);
		free(buffer);
		if (!error)
			buffer = get_next_line(fd);
	}
	secure_close(fd);
	if (error)
		return (error);
	if (!all_elem(&game->data.textures) && game->map.map_list == NULL)
		return (free_all(game, NULL, "All elemensts are needed"));
	return (check_map(game));
}
