/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:20:52 by iborge-g          #+#    #+#             */
/*   Updated: 2025/08/05 15:32:26 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	mem_map(int fd, t_point ***map, t_map *info)
{
	int	i;

	i = 0;
	(*info).cols_num = count_cols(fd);
	(*info).rows_num = count_rows(fd);
	*map = malloc((*info).rows_num * sizeof(t_point *));
	if (!(*map))
	{
		return ;
	}
	while (i < (*info).rows_num)
	{
		(*map)[i] = malloc((*info).cols_num * sizeof(t_point));
		if (!(*map)[i])
		{
			free_map(*map, i);
			*map = NULL;
			return ;
		}
		i++;
	}
}

void	fill_content(t_point ***map, t_map *info, char *line, int y)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (x < (*info).cols_num)
	{
		while (line[i] == ' ')
			i++;
		(*map)[y][x].x = x;
		(*map)[y][x].y = y;
		(*map)[y][x].z = ft_atoi(&line[i]);
		while (line[i] && line[i] != ' ')
			i++;
		x++;
	}
	free(line);
}

void	parse_map(int fd, t_point ***map, t_map *info)
{
	char	*line;
	int		x;
	int		y;
	int		i;

	y = 0;
	mem_map(fd, map, info);
	lseek(fd, 0, SEEK_SET);
	line = get_next_line(fd);
	while (line != NULL)
	{
		fill_content(map, info, line, y);
		y++;
		line = get_next_line(fd);
	}
}
