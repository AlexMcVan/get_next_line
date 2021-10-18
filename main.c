/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:20:03 by amarie-c          #+#    #+#             */
/*   Updated: 2021/09/09 14:16:08 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>
//#include <fcntl.h>
// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line.h get_next_line_utils.c

void gnl(char* line)
{
	printf("%s", line);
}

int	main (void)
{
	/*char *c1 ="tapita";
	char *c2 ="yololo \n hihi";

	printf("%s\n",ft_strnjoin(c1, c2, ft_strlen (c2) ));
	printf("%s\n",ft_strndup(c1, ft_strlen(c1)));
	printf("%d\n", ft_strchr(c2, '\n'));*/

	
	int fd = open("essi.txt", O_RDONLY);
		printf("1\n");
	gnl(get_next_line(fd));
		printf("2\n");
	gnl(get_next_line(fd));
	printf("3\n");
	gnl(get_next_line(fd));
	printf("4\n");
	gnl(get_next_line(fd));
	printf("5\n");
	gnl(get_next_line(fd));
	


	return (0);
}
/*lalala
hihi
completa
poulet frit*/
