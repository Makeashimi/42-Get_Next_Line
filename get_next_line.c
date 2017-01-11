/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 17:22:27 by jcharloi          #+#    #+#             */
/*   Updated: 2017/01/06 10:56:44 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		read_buffer(int fd, char **result, char **remain)
{
	char			*result2;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	ret = 1;
	while (ft_strsrchi(*result, '\n') == -1 && ret)
	{
		result2 = *result;
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		*result = ft_strjoin(result2, buf);
		ft_strdel((char**)&result2);
	}
	if (ret == 0 && *result[0] == 0)
	{
		ft_strdel((char**)remain);
		ft_strdel((char**)result);
		return (0);
	}
	return (1);
}

/*
** stock = Contain the return value of read_buffer AND browse result.
** result = Result of buf and remain.
** remain = Remain of the file after the \n.
** stock + 1 = index / &ret + 1 = pointer starting at ret+1 to keep the string.
*/

int		get_next_line(const int fd, char **line)
{
	int				stock;
	char			*result;
	static char		*remain = NULL;

	result = (remain == NULL) ? ft_strnew(0) : ft_strdup(remain);
	ft_strdel((char**)&remain);
	if ((stock = read_buffer(fd, &result, &remain)) == -1)
		return (-1);
	if (stock == 0)
		return (0);
	stock = 0;
	while (result[stock] != '\0' && result[stock] != '\n')
		stock++;
	*line = ft_strsub(result, 0, stock);
	if (result[stock] == '\n')
		remain = ft_strdup(&result[stock + 1]);
	ft_strdel((char**)&result);
	return (1);
}
