/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rows_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:50:43 by iborge-g          #+#    #+#             */
/*   Updated: 2025/08/05 15:55:17 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_header.h"

int	count_rows(int fd)
{
	char	*line;
	int		y;

	y = 0;
	lseek(fd, 0, SEEK_SET);
	line = get_next_line(fd);
	while (line != NULL)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	return (y);
}

int	count_cols(int fd)
{
	char	*line;
	int		x;
	int		in_word;
	int		len;
	int		cols;

	x = 0;
	cols = 0;
	in_word = 0;
	lseek(fd, 0, SEEK_SET);
	line = get_next_line(fd);
	if (!line)
		return (0);
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	while (line[x])
	{
		if (line[x] != ' ' && !in_word)
		{
			cols++;
			in_word = 1;
		}
		else if (line[x] == ' ')
		{
			in_word = 0;
		}
		x++;
	}
	free(line);
	return (cols);
}
