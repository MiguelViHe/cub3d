/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:13:20 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/01 16:31:27 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	dir_ok(char *dir)
{
	if (strlen(dir) == 1 
		&& (dir[0] == 'N' 
			|| dir[0] == 'S' 
			|| dir[0] == 'E' 
			|| dir[0] == 'W'))
		return (1);
	return (0);
}

/*Check if the map file extension is ".cub". Error and exit if not*/
void	check_arg_cub(char *name)
{
	int	len_total;
	int	len_name;

	len_total = ft_strlen(name);
	len_name = len_total - 4;
	if (!(len_total > 4 && ft_strncmp(name + len_name, ".cub", 4) == 0
			&& name[len_total - 5] != '/'))
	{
		ft_fdprintf(2, "Error\nWrong map extension.\n");
		exit(EXIT_FAILURE);
	}
}