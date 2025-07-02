/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:09:36 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/02 12:10:26 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Función para eliminar el '\n' al final de una línea
void remove_newline(char *line)
{
	int	len;
	
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

void	copy_info_color(char *str, char *clean, int *j, int *i)
{
	while (str[*i])
	{
		if (ft_isdigit(str[*i]) || str[*i] == ',')
			clean[(*j)++] = str[*i];
		(*i)++;
	}
}

void	copy_info_texture(char *str, char *clean, int *j, int *i)
{
		// Copiar simbolo de textura
		clean[(*j)++] = str[(*i)++];
		// Saltar espacios tras el número
		while (ft_isspace(str[*i]))
			(*i)++;
		// Insertar espacio
		clean[(*j)++] = ' ';
		// Copiar el resto tal cual (conservando espacios en el path)
		while (str[*i])
			clean[(*j)++] = str[(*i)++];
}


/*Setea la linea de textura o color dejándola con un único espacio
 entre información y devuelve un nuevo string.*/
char	*remove_spaces(char *str)
{
	int		i = 0;
	int		j = 0;
	char	*clean;
	char	id;

	if (!str)
		return (NULL);
	clean = malloc(strlen(str) + 3); //+2 por si viene sin ningún espacios y +1 para el '\0'
	if (!clean)
		return (NULL);
	while (ft_isspace(str[i]))
		i++;
	id = str[i];
	clean[j++] = str[i++];
	while (ft_isspace(str[i]))
		i++;
	clean[j++] = ' ';
	if (id == 'F' || id == 'C')
		copy_info_color(str, clean, &j, &i);
	else if (id == 'T')
		copy_info_texture(str, clean, &j, &i);
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
