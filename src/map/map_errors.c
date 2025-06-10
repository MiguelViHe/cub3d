/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:51:23 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/10 12:42:07 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Write the error message in the stderr, free buffer if necessary and exit*/
void	wrong_map_exit(char *buffer, char *message, int need_free)
{
	ft_fdprintf(2, "%s\n", message);
	if (need_free)
		free(buffer);
	exit(EXIT_FAILURE);
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

/*Write the error message in the stderr, close de fd and exit*/
void	wrong_generate_map_exit(char *message, int fd)
{
	ft_fdprintf(2, "%s\n", message);
	secure_close(fd);
	exit(EXIT_FAILURE);
}

/*Write the error message in the stderr, free all in map_copy and exit*/
void	wrong_copy_map_exit(char **copy_array, int pos)
{
	int	j;

	j = 0;
	while (j < pos)
		free(copy_array[j++]);
	free(copy_array);
	ft_fdprintf(2, "Failed to allocate memory for copy_array\n");
	exit (EXIT_FAILURE);
}
