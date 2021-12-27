/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <amarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:55:49 by amarie-c          #+#    #+#             */
/*   Updated: 2021/12/27 16:28:30 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**create_bis(char **list)
{
	char **list_bis;
	int	i;

	i = 0;
	list_bis = (char**) ft_calloc(list_size(list) + 1, sizeof(char*));
	if(!list_bis)
		return(NULL);
	while (i < list_size(list))
	{
		list_bis[i] = (char*)ft_calloc(ft_strlen(list[i]) + 1, sizeof(char));
		if(!list_bis[i])
			return(NULL);
		ft_memcpy(list_bis[i], list[i], ft_strlen(list[i]));
		i++;
	}
	list_bis[i] = NULL;
	return (list_bis);
}

char	**create_list(int size)
{
	char **list;
	int	i;

	i = 0;
	if (size <= 0)
	{
		list = (char**) ft_calloc( 1, sizeof(char*));
		list[0] = NULL;
		return (list);
	}
	list = (char**) ft_calloc(size + 1, sizeof(char*));
	if(!list)
		return(NULL);
	
	while(i <size )
		{
			list[i] = ft_calloc(1, sizeof(char));
			list[i] ="";
			i++;
		}
	list[size] = NULL;
	return(list);
}

void	fill_bis(char	**m, char	**m_bis, char	**l, char	**l_bis)
{
	int	more_size;
	int	less_size;
	int	buff;
	int	i;
	more_size = list_size(m);
	less_size = list_size(l);
	i = 0;
	buff = fap(l[0]);
	//while( i < second_size)
	while (l[i + 1] != NULL)
	{
		//free(less_bis[i]);
		l_bis[i] = (char*)ft_calloc(ft_strlen(l[i + 1]) + 1, sizeof(char));
		ft_memcpy(l_bis[i], l[i + 1], ft_strlen(l[i + 1]));
		i++;
	}
	m_bis[0] = (char*)ft_calloc(ft_strlen(ft_itoa(buff)) + 1, sizeof(char));
	ft_memcpy(m_bis[0], ft_itoa(buff), ft_strlen(ft_itoa(buff)));
	i = 1;
	while (m[i - 1] != NULL)
	{
		//free(more_bis[i]);
		m_bis[i] = (char*)ft_calloc(ft_strlen(m[i - 1]) + 1,sizeof(char));
		ft_memcpy(m_bis[i], m[i - 1], ft_strlen(m[i - 1]));
		i++;
	}
}

void	push(char	***more, char ***less, int name)
{
	char	**more_bis;
	char	**less_bis;
	more_bis = create_list(list_size(*more) + 1);
	less_bis = create_list(list_size(*less) -1);
	fill_bis(*more, more_bis, *less, less_bis);
	ft_free(*more,list_size(*more));
	ft_free(*less,list_size(*less));
 	*more = more_bis;
 	*less = less_bis;
	if (name == 1)
		write(1,&"pa\n", 3 * sizeof(char));
	if (name == 2)
		write(1,&"pb\n", 3 * sizeof(char));
}
