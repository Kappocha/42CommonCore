/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iborge-g <iborge-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:51:33 by iborge-g          #+#    #+#             */
/*   Updated: 2025/06/12 18:56:08 by iborge-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*ft_strjoin(char const *dst, char const *src);
char	*ft_strchr(char const *s, int c);
int		ft_strlen(char const *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
