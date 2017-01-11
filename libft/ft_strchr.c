/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:59:44 by jcharloi          #+#    #+#             */
/*   Updated: 2017/01/05 15:46:35 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr_s;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(s);
	ptr_s = (char*)s;
	while (j <= i)
	{
		if (ptr_s[j] == c)
			return (&ptr_s[j]);
		j++;
	}
	return (NULL);
}
