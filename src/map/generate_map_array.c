/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:40:46 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/30 15:41:15 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	generate_map_array(t_game *g)
{
	t_list	*current_node;
	char	*line;
	int		i;

	g->map.matrix = ft_calloc(g->map.height + 1, sizeof(char *));
	if (g->map.matrix == NULL)
		return (free_all(g, NULL, "allocating memory for map array"));
	current_node = g->map.map_list;
	i = 0;
	while (current_node)
	{
		line = current_node->content;
		g->map.matrix[i] =ft_calloc(g->map.width + 1, sizeof(char));
		if (g->map.matrix[i] == NULL)
			return (free_all(g, NULL, "allocating memory for map array line"));
		fill_with_spaces(g->map.matrix[i], line, g->map.width);
		current_node = current_node->next;
		i++;
	}
	return (0);
}
