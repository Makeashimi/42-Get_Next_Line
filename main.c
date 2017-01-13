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
	int		fd1;
	int		ret1;
	int		fd2;
	int		ret2;
	char	*str1;
	char 	*str2;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	while ((ret1 = get_next_line(fd1, &str1)) > 0  || (ret2 = get_next_line(fd2, &str2)) > 0)
	{
		ft_putstr("ret1 argv[1] : ");
		ft_putnbr(ret1);
		ft_putstr(", line argv[1] : ");
		ft_putstr(str1);

		ft_putstr(" , ret2 argv[2] : ");
		ft_putnbr(ret2);
		ft_putstr(", line argv[2] : ");
		ft_putstr(str2);
		ft_putendl("|");

		ft_memdel((void**)&str1);
		ft_memdel((void**)&str2);
	}
	return (0);
}
