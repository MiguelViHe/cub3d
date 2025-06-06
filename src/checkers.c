/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:13:20 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/05/29 10:13:58 by mvidal-h         ###   ########.fr       */
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