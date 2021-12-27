/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <amarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:44:53 by amarie-c          #+#    #+#             */
/*   Updated: 2021/12/27 17:25:06 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fap(const char *str)
{
	int			i;
	int			signe;
	long int	nb;

	i = 0;
	nb = 0;
	signe = 1;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (str[i])
	{
		if ((str[i] <= '9') && (str[i] >= '0'))
			nb = nb * 10 + (str[i] - '0');
		else
			return (ERROR);
		i++;
	}
	if ((nb > 2147483647) || (nb * signe < -2147483648))
		return (ERROR);
	return ((int)(nb * signe));
}

int	ft_no_double(char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i] != NULL)
	{
		j = i + 1;
		while (list[j] != NULL)
		{
			if (ft_strncmp(list[i], list[j], 10) == 0)
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

void	error_parsing(char	**list, int nb)
{
	ft_free(list, nb);
	write(2, "Error\n", 6 * sizeof(char));
}

char	**parsing(int argc, char **argv)
{
	char	**list;
	int		i;

	i = 1;
	list = (char **)ft_calloc(argc, sizeof(char *));
	if (!list)
		return (NULL);
	list[argc - 1] = NULL;
	while (i < argc)
	{
		list[i - 1] = (char *) ft_calloc(ft_strlen(argv[i]) + 1, sizeof(char));
		list[i - 1] = ft_memcpy(list[i - 1], argv[i], ft_strlen(argv[i]));
		if ((fap(argv[i]) == ERROR) && ft_strncmp("1", argv[i], 2) != 0)
		{
			error_parsing(list, i -1);
			return (NULL);
		}
		i++;
	}
	if (ft_no_double(list) == ERROR)
	{
		error_parsing(list, i -1);
		return (NULL);
	}
	return (list);
}
