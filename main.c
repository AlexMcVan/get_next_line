/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <amarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:20:03 by amarie-c          #+#    #+#             */
/*   Updated: 2021/10/19 11:50:39 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line.h get_next_line_utils.c

void gnl(char* line)
{
	printf("%s", line);
}

int	main (void)
{

	
	int fd = open("essi.txt", O_RDONLY);
	gnl(get_next_line(fd));
	gnl(get_next_line(fd));
	gnl(get_next_line(fd));
	gnl(get_next_line(fd));
	gnl(get_next_line(fd));
	


	return (0);
}