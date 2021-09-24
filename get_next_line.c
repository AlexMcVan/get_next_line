/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:38:15 by amarie-c          #+#    #+#             */
/*   Updated: 2021/09/09 14:16:00 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



void	ft_free(char *result, int start)
{
	start ++;
	while (result[start++] != '\0')
		free(&result[start]);
}

char	*get_next_line(int fd)
{	
	int			readed;
	char		*buffer;
	static char	*next_line;
	//int			carriage_return;
	char		*result;

	if (fd < 0) //max depend systeme, à voir pour la valeur (si j'en mets un) | fd > 1024)
		return (NULL);
	readed = 1;
	printf("avant a\n");	
	result = ft_strndup(next_line, ft_strlen(next_line));
	printf("a");

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	printf("b\n");
	while (readed > 0 && ft_strchr(buffer, '\n') == -1)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		buffer[readed] = '\0';
		result = ft_strnjoin(result, buffer, readed);
	}
	//free(buffer);
	printf("c\n");
	free (next_line);
	printf("d\n");
	next_line = ft_strndup(&buffer[ft_strchr(buffer, '\n') + 1], ft_strlen(result)- ft_strchr(buffer, '\n'));
	printf("e\n");
	//ft_free(result,ft_strchr(buffer, '\n') + 1 );
	printf("f\n");
	return (result);
}
