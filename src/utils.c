/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:37:48 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/06/25 18:14:45 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_clamp(int value, int min, int max)
{
	if (value < min)
		return min;
	if (value > max)
		return max;
	return value;
}

// Función para eliminar el '\n' al final de una línea
void remove_newline(char *line)
{
	int	len;
	
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}
//Elimina los espacios y tabulaciones de un string, dejando solo un espacio después
//del identificador del elemento, y devuelve un nuevo string.
char	*remove_spaces(char *str)
{
	int	i;
	int	j;
	int	space;
	
	i = 0;
	j = 0;
	space = 0;

	char *clean = malloc(strlen(str) + 1);
	if (!clean)
		return (free(str), NULL);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			clean[j++] = str[i];
		else if (str[i] == ' ' && !space)
		{
			clean[j++] = ' ';
			space = 1; // only one space allowed
		}
		i++;
	}
	clean[j] = '\0';
	return (clean);
}

void	fill_with_spaces(char *dest, const char *src, int width)
{
	int	i;

	i = ft_strlcpy(dest, src, width + 1);
	while (i < width)
		dest[i++] = ' ';
	dest[i] = '\0';
}

int sign(double x)
{
	return (x > 0) - (x < 0);
}
