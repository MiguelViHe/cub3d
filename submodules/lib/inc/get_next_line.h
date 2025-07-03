/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:14:13 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/02 17:25:19 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
//# include <stdlib.h> //malloc
//# include <unistd.h> //files
//# include <fcntl.h>  //O_RDONLY
//# include <stddef.h> //size_t
//# include <limits.h> //OPEN_MAX

char	*get_next_line(int fd);
int		is_eol(char	*str);

#endif
