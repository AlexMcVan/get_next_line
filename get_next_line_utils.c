/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <amarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:42:12 by amarie-c          #+#    #+#             */
/*   Updated: 2021/10/15 17:27:30 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = ft_calloc(ft_strchr(s1, '\0') + n + 1, sizeof(char));
	if (!dest || !(s2))
	{
		free (dest);
		return (NULL);
	}	
	if (s1)
	{
		while (s1[i] != '\0')
		{
			dest[i] = s1[i];
			i++;
		}
	}
	while (s2[j] != '\0' && j < n)
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s || !(*s))
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (-1);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*dest;

	i = 0;
	if (!src || n <= 0 || !(*src))
		return (NULL);
	while (src[i] && i < n)
		i++;
	dest = (char *)ft_calloc((i + 1), sizeof(char));
	if (dest == NULL)
	{
		free(dest);
		return (NULL);
	}
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_calloc(int nbofelements, int sizeofelement)
{
	void	*space;
	int		size;
	int		i;

	size = nbofelements * sizeofelement;
	space = (void *)malloc((nbofelements) * sizeofelement);
	if (space == NULL)
	{
		free(space);
		return (NULL);
	}
	i = 0;
	while (i < size)
		((char *)space)[i++] = 0;
	return (space);
}
