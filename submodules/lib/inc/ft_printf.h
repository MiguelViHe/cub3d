/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:46:52 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/05 09:39:06 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
//# include <unistd.h> //Comentadas al incluirlo el libft porque ya la tiene
//# include <stdlib.h> //Comentadas al incluirlo el libft porque ya la tiene
//# include "libft/libft.h" //ADDED

int		ft_printf(char const *str, ...);
int		ft_fdprintf(int fd, char const *str, ...);
int		ft_putoption(int fd, char option, va_list args);
int		ft_putchar(int fd, char c);
int		ft_putstr(int fd, char *str);
//size_t	ft_strlen(const char *s); //ADDED
//size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize); //ADDED
int		ft_digit(int fd, int nbr);
int		ft_putnbr(int fd, int nbr);
int		ft_nbrlen(int nbr);
int		ft_base(int fd, unsigned int nbr, char *base);
int		ft_putnbr_base(int fd, unsigned int nbr, char *base, size_t baselen);
int		ft_nbrlen_base(unsigned int nbr, size_t baselen);
int		ft_putptr(int fd, unsigned long long nbr);
int		ft_putptr_hexa(int fd, unsigned long long nbr);
int		ft_ptrlen_hexa(unsigned long long nbr);

#endif
