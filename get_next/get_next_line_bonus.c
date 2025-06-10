/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:17:47 by iborge-g          #+#    #+#             */
/*   Updated: 2025/06/05 16:40:56 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 14
#endif

char	*read_and_store(int fd, char *saved)
{
	char	*buf;
	size_t	bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(saved, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		saved = ft_strjoin(saved, buf);
	}
	free(buf);
	return (saved);
}

char	*get_line(char *saved)
{
	size_t	len;
	char	*line;

	len = 0;
	if (!saved || !*saved)
		return (NULL);
	while (saved[len] && saved[len] != '\n')
		len++;
	if (saved[len] == '\n')
		len++;
	line = ft_substr(saved, 0, len);
	return (line);
}

char	*clean_saved(char *saved)
{
	size_t	i;
	char	*rest;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (!saved[i])
	{
		free(saved);
		return (NULL);
	}
	rest = ft_substr(saved, i + 1, ft_strlen(saved) - i - 1);
	free(saved);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*saved[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved[fd] = read_and_store(fd, saved[fd]);
	if (!saved[fd])
		return (NULL);
	line = get_line(saved[fd]);
	saved[fd] = clean_saved(saved[fd]);
	return (line);
}
