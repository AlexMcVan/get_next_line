/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:21:51 by amarie-c          #+#    #+#             */
/*   Updated: 2021/10/19 11:24:19 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

void	ft_free(char *result, int start);
char	*get_next_line(int fd);
void	*ft_calloc(int nbofelements, int sizeofelement);
char	*ft_strnjoin(char *s1, char *s2, int n);
int		ft_strlen(char *s);
int		ft_strchr(char *s, char c);
char	*ft_strndup(char *src, int n);
char	*ft_update_nl(char **next_line, int pos_carriage_return);
char	*ft_output(char **next_line, int pos_carriage_return, int cursor);

#endif
