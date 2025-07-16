/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:37:48 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/07/16 11:56:44 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_clamp(int value, int min, int max)
{
	if (value < min)
		return min;
	if (value > max)
		return max;
	return value;
}

double	ft_clamp_double(double value, double min, double max)
{
	if (value < min)
		return min;
	if (value > max)
		return max;
	return value;
}

int sign(double x)
{
	return (x > 0) - (x < 0);
}
