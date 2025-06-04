/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:53:15 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/04 14:36:35 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	secure_open(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_fdprintf(2, "Error opening file.\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	secure_close(int fd)
{
	if (close(fd) == -1)
	{
		ft_fdprintf(2, "Error closing file.\n");
		exit(EXIT_FAILURE);
	}
}
