/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gain_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <amarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:43:46 by amarie-c          #+#    #+#             */
/*   Updated: 2021/12/27 16:54:47 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(char **a, char **b)
{
	ft_free(a, list_size(a));
	ft_free(b, list_size(b));
}

void	ft_sort(char **a, char **b)
{
	if (list_size(a) <= 5)
		ft_sort_small(a, b);
	else
		ft_sort_big(a, b);
}
