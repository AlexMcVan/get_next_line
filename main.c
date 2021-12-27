/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <amarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:23:03 by amarie-c          #+#    #+#             */
/*   Updated: 2021/12/27 17:21:51 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_min(int nb, char **list)
{
	int	i;
	int	min;

	i = 0;
	min = 1;
	while (i < list_size(list))
	{
		if (fap(list[i]) < nb)
			min = 0;
		i++;
	}
	return (min);
}

int	is_max(int nb, char **list)
{
	int	i;
	int	max;

	i = 0;
	max = 1;
	while (i < list_size(list))
	{
		if (fap(list[i]) > nb)
			max = 0;
		i++;
	}
	return (max);
}

int	list_size(char **list)
{
	int	i;

	i = 0;
	while (list[i] != NULL)
		i++;
	return (i);
}

void	ft_free(char **list, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

int	main(int argc, char **argv)
{
	char	**a;
	char	**b;

	if (argc > 1)
	{
		b = (char **)ft_calloc(1, sizeof(char *));
		if (!b)
			return (ERROR);
		b[0] = NULL;
		a = parsing(argc, argv);
		if (!a || a == NULL)
			return (ERROR);
		if (is_sorted(a) == SUCCESS)
		{
			free_all(a, b);
			return (SUCCESS);
		}
		a = ft_ranked(a);
		ft_sort(a, b);
		free_all(a, b);
	}
	return (SUCCESS);
}
