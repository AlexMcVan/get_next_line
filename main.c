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
#include <unistd.h>
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line.h get_next_line_utils.c

int	main (int argc, char **argv)
{
	(void) argc;
	int fd = open(argv[1], O_RDONLY);
//for  stdin : fd = 1
	//following comments for fd bonus
	//int fd2 = open(argv[2], O_RDONLY);
	char *line = get_next_line(fd);
	//char *line2 = get_next_line(fd2);
	printf("%s", line);
	//printf("%s", line2);
	while (line /* && line2*/)
	{
		line = get_next_line(fd);
		//line2 = get_next_line(fd2);
		printf("%s", line);
		//printf("%s", line2);
	}
	close(fd);
	//close(fd2);
	return (0);
}
