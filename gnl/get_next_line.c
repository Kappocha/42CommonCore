/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:51:24 by iborge-g          #+#    #+#             */
/*   Updated: 2025/06/18 19:07:53 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 14
#endif

static char	*clearsaved(char *ptr_nl, char *saved)
{
	char	*temp;

	if (!saved)
		return (NULL);
	if (ptr_nl)
	{
		temp = ft_substr(ptr_nl + 1, 0, ft_strlen(ptr_nl + 1));
		free(saved);
		if (!temp)
			return (NULL);
		return (temp);
	}
	else
	{
		free(saved);
		return (NULL);
	}
}

char	*add_until_nl(int fd, char *saved)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*tmp;

	while (!saved || !ft_strchr(saved, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(saved, buffer);
		free(saved);
		saved = tmp;
		if (!saved)
			return (NULL);
	}
	return (saved);
}

char	*get_next_line(int fd)
{
	static char		*saved;
	char			*ptr_nl;
	char			*rturn;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved = add_until_nl(fd, saved);
	if (!saved || saved[0] == '\0'){
		free(saved);
		saved = NULL;
		return (NULL);
	}
	ptr_nl = ft_strchr(saved, '\n');
	if (ptr_nl)
		rturn = ft_substr(saved, 0, ptr_nl - saved + 1);
	else
		rturn = ft_substr(saved, 0, ft_strlen(saved));
	if (!rturn){
		free(saved);
		saved = NULL;
		return (NULL);
	}
	saved = clearsaved(ptr_nl, saved);
	return (rturn);
}
