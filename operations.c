/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <amarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:48:45 by amarie-c          #+#    #+#             */
/*   Updated: 2021/12/27 17:00:04 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char	**list, int name)
{
	int	buff;

	if (list[0] && *list[1])
	{
		buff = fap(list[0]);
		free(list[0]);
		list[0] = ft_calloc(ft_strlen(list[1]) + 1, sizeof(char));
		ft_memcpy(list[0], list[1], ft_strlen(list[1]));
		free(list[1]);
		list[1] = ft_calloc(ft_strlen(ft_itoa(buff)) + 1, sizeof(char));
		ft_memcpy(list[1], ft_itoa(buff), ft_strlen(ft_itoa(buff)));
		if (name == 1)
			write(1, &"sa\n", 3 * sizeof(char));
		if (name == 2)
			write(1, &"sb\n", 3 * sizeof(char));
		if (name == 3)
			write(1, &"ss\n", 3 * sizeof(char));
	}
}

void	rotate(char	**list, int name)
{
	int	buff;
	int	i;
	int	nb;

	i = 0;
	nb = list_size(list);
	buff = fap(list[0]);
	while (i < nb - 1)
	{
		free(list[i]);
		list[i] = ft_calloc(ft_strlen(list[i + 1]) + 1, sizeof(char));
		ft_memcpy(list[i], list[i + 1], ft_strlen(list[i + 1]));
		i++;
	}
	free(list[nb -1]);
	list[nb - 1] = ft_calloc(ft_strlen(ft_itoa(buff)) + 1, sizeof(char));
	ft_memcpy(list[nb - 1], ft_itoa(buff), ft_strlen(ft_itoa(buff)));
	if (name == 1)
		write(1, &"ra\n", 3 * sizeof(char));
	if (name == 2)
		write(1, &"rb\n", 3 * sizeof(char));
	if (name == 3)
		write(1, &"rr\n", 3 * sizeof(char));
}

void	reverse_rotate(char	**list, int name)
{
	int	buff;
	int	i;
	int	nb;

	nb = list_size(list);
	i = nb - 1;
	buff = fap(list[nb - 1]);
	while (i > 0)
	{
		free(list[i]);
		list[i] = ft_calloc(ft_strlen(list[i - 1]) + 1, sizeof(char));
		ft_memcpy(list[i], list[i - 1], ft_strlen(list[i - 1]));
		i--;
	}
	free(list[0]);
	list[0] = ft_calloc(ft_strlen(ft_itoa(buff)) + 1, sizeof(char));
	ft_memcpy(list[0], ft_itoa(buff), ft_strlen(ft_itoa(buff)));
	if (name == 1)
		write(1, &"rra\n", 4 * sizeof(char));
	if (name == 2)
		write(1, &"rrb\n", 4 * sizeof(char));
	if (name == 3)
		write(1, &"rrs\n", 4 * sizeof(char));
}

int	is_sorted(char	**list)
{
	int	i;
	int	nb;

	i = 0;
	nb = list_size (list);
	while (i < nb - 1)
	{
		if (fap(list[i]) > fap(list[i + 1]))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
