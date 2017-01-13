/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 12:42:08 by jcharloi          #+#    #+#             */
/*   Updated: 2017/01/11 16:29:58 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 7

# include "Libft/libft.h"
# include <fcntl.h>

typedef struct	s_gnl
{
	int			fd;
	char		*remain;
} 				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
