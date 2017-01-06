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

int		get_next_line(const int fd, char **line)
{
	int				ret;/*Stocker le nombre d'octets de read*/
	char			buf[BUFF_SIZE + 1];/*Le contenu du fichier*/
	int				i;/*Parcourir le buf*/
	char			*result;/*Le resultat du buf lu + le reste*/
	char			*result2;
	static	char	*reste = NULL;/*Le reste du fichier apres le \n*/
	
	ret = 1;
	if (reste == NULL)
		result = ft_strnew(0);
	else
		result = ft_strdup(reste);
	//printf("reste : %s\n", reste);
	while (ft_strsrchi(result, '\n') == -1 && ret)
	{
		result2 = result;
		ret = read(fd, buf, BUFF_SIZE);
		//printf("ret : %d\n", ret);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		result = ft_strjoin(result2, buf);
		//printf("result : %s|\n", result);
		ft_strdel((char**)&result2);
	}
	i = 0;
	//printf("resultt : %s\n", result);
	while (result[i] != '\0' && result[i] != '\n')
		i++;
	*line = ft_strsub(result, 0, i);
	//printf("line : %s\n", *line);
	//printf("ret : %d\n", ret);	
	if (ret == 0 && result[0] == '\0')
			return (0);
	if (result[i] == '\n')
		reste = ft_strdup(&result[i + 1]);/*i + 1 = l'index / &i + 1 = pointeur commencant a i+1 pour continuer la chaine*/
	else
		reste = NULL/*ft_strdup(result)*/;
	return (1);
}
