/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:38:56 by amarie-c          #+#    #+#             */
/*   Updated: 2021/09/09 14:16:02 by amarie-c         ###   ########.fr       */
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
	if (!(*s2))
		return (NULL);
	dest = ft_calloc(ft_strlen(s1) + n + 1, sizeof(char));
	if (!dest)
		return (NULL);
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
	return (dest);
}

int	ft_strlen(char *s)
{
	int	i;
	if (!s || !(*s))
		return(0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*dest;

	i = 0;
	if (!src || n <= 0)
		return (NULL);
	while (src[i] && i < n)
		i++;
	dest = (char *)ft_calloc((i + 1), sizeof(char));
	if (dest == NULL)
		return (NULL);
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
		return (NULL);
	i = 0;
	while (i < size)
		((char *)space)[i++] = 0;
	return (space);
}