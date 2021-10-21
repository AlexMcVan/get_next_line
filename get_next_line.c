/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <amarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:12:54 by amarie-c          #+#    #+#             */
/*   Updated: 2021/10/19 11:54:44 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*maj_next_line(char	*result)
{
	char	*proto_next_line;
	int		carriage_return;
	int		start_next_line;

	if (!result)
		return (NULL);
	carriage_return = ft_strchr(result, '\n');
	if (carriage_return == -1)
		return (NULL);
	start_next_line = ft_strchr(result, '\0') - carriage_return;
	proto_next_line = ft_strndup(&result[carriage_return + 1], start_next_line);
	if (!proto_next_line)
	{
		free(proto_next_line);
		return (NULL);
	}
	return (proto_next_line);
}

char	*maj_result(char *result)
{
	char	*new_result;
	int		carriage_return;

	if (!result)
		return (NULL);
	carriage_return = ft_strchr(result, '\n');
	if (carriage_return == -1)
		carriage_return = ft_strchr(result, '\0');
	new_result = ft_strndup(result, carriage_return + 1);
	free (result);
	return (new_result);
}

int	ft_read(char *buffer, int fd)
{
	int		readed;
	char	**ptr;

	ptr = &buffer;
	readed = read(fd, *ptr, BUFFER_SIZE);
	if (readed > 0)
		(*ptr)[readed] = '\0';
	return (readed);
}

char	*get_next_line(int fd)
{
	int			readed;
	char		buffer[BUFFER_SIZE + 1];
	static char	*next_line;
	char		*result;

	buffer[BUFFER_SIZE] = '\0';
	if (fd < 0 || fd == NULL || BUFFER_SIZE <= 0)
		return (NULL);
	readed = -2;
	result = ft_strndup(next_line, ft_strchr(next_line, '\0'));
	while ((readed > 0 && ft_strchr(buffer, '\n') == -1) || readed == -2)
	{
		readed = ft_read(buffer, fd);
		if (readed < 1)
			break ;
		result = ft_strnjoin(result, buffer, readed);
	}
	if (!(*buffer) && readed == 0)
		result = ft_strndup(next_line, ft_strchr(next_line, '\0'));
	free(next_line);
	next_line = maj_next_line(result);
	return (maj_result(result));
}
