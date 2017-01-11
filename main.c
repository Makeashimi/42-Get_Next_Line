/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:59:45 by jcharloi          #+#    #+#             */
/*   Updated: 2017/01/05 11:12:01 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		ft_putstr("ret : ");
		ft_putnbr(ret);
		ft_putstr(", line : ");
		ft_putendl(str);
		ft_memdel((void**)&str);
	}
	return (0);
}
