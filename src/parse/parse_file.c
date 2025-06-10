/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:40:59 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/10 17:24:18 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_line(char *line)
{
	char	**tokens;

	if (line[0] == '\0' || line[0] == '\n')
		return (0); // Empty line, do nothing
	if (ft_isspace(line[0]) || line[0] == '0')
		return (1); // file starts with the map.
	tokens = ft_split(line, ' ');
	if (tokens == NULL)
	{
		ft_fdprintf(2, "Error\nFailed to allocate memory for tokens.\n");
		exit(EXIT_FAILURE);
	}
	
}

int	parse_file(char *map_name)
{
	int		fd;
	int		error;
	char	*buffer;

	error = 0;
	fd = secure_open(map_name);
	buffer = get_next_line(fd);
	if (buffer == NULL)
		wrong_map_exit(buffer, "Error\nReading line from map or empty map.", 0);
	while (buffer)
	{
		error = check_line(buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	secure_close(fd);
	return (lines);
}