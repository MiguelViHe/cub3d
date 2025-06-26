/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:40:59 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/25 18:20:07 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	all_elem(t_textures *textures)
{
	if (textures[NO].path && textures[SO].path &&
		textures[WE].path && textures[EA].path &&
		textures[F].path && textures[C].path)
		return (1);
	return (0);
}

int	set_texture(char **tokens, t_game *g)
{	
	int	tex_id;
	
	if (!tokens || !tokens[0] || !tokens[1] || tokens[2])
		return (free_all(g, tokens, "bad format in texture"));
	tex_id = -1;
	if (strncmp(tokens[0], "NO", 2) == 0 && !g->map.textures[NO].path)
		tex_id = NO;
	else if (strncmp(tokens[0], "SO", 2) == 0 && !g->map.textures[SO].path)
		tex_id = SO;
	else if (strncmp(tokens[0], "WE", 2) == 0 && !g->map.textures[WE].path)
		tex_id = WE;
	else if (strncmp(tokens[0], "EA", 2) == 0 && !g->map.textures[EA].path)
		tex_id = EA;
	else if (strncmp(tokens[0], "F", 1) == 0 && !g->map.textures[F].path)
		tex_id = F;
	else if (strncmp(tokens[0], "C", 1) == 0 && !g->map.textures[C].path)	
		tex_id = C;
	else
		return (free_all(g, tokens, "Invalid texture or color format"));
	g->map.textures[tex_id].path = ft_strdup(tokens[1]);
	free_char_array(tokens);
	if (tex_id == C || tex_id == F)
		return (set_surface_color(g, tex_id));
	return (ft_load_texture(g, &g->map.textures[tex_id]));
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
	char	*cleaned;

	if (line[0] == '\n')
	{
		if (g->map.map_list == NULL) // empty line before map
			return (0); // continue checking
		return (free_all(g, NULL, "Empty line after map beginning"));
	}
	remove_newline(line);
	if (is_map_line(line))
	{
		if (!all_elem(g->map.textures))
			return (free_all(g, NULL, "Map is not the last element"));
		return (adding_map_line(line, g));
	}
	if (g->map.map_list != NULL)
		return (free_all(g, NULL, "Bad elements in map"));
	cleaned = remove_spaces(line);
	if (!cleaned)
		return (free_all(g, NULL, "Removing spaces from line"));
	tokens = ft_split(cleaned, ' ');
	if (tokens == NULL)
		return (free(cleaned), free_all(g, NULL, "Checking texture or color"));
	return (free(cleaned), set_texture(tokens, g));
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
		if (buffer)
			free(buffer);
		if (!error)
			buffer = get_next_line(fd);
	}
	secure_close(fd);
	if (error)
		return (error);
	if (!all_elem(game->map.textures) && game->map.map_list == NULL)
		return (free_all(game, NULL, "All elemensts are needed"));
	return (check_map(game));
}
