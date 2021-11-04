/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:53:21 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/11/04 20:00:48 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	newline_index(char *str)
{
	int	count;

	if (!str)
		return (-1);
	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '\n')
			return (count);
		count++;
	}
	return (-1);
}

static char	*extract(char **save, int read_count)
{
	char	*swp;
	char	*ret;
	int		size;

	if (!**save)
	{
		free(*save);
		return (NULL);
	}
	size = newline_index(*save) + 1;
	if (size == 0)
		size = ft_strlen(*save);
	ret = ft_substr(*save, 0, size);
	swp = ft_substr(*save, size, ft_strlen(*save) - size);
	free(*save);
	if (read_count == 0)
	{
		free(swp);
		*save = NULL;
		return (ret);
	}
	*save = swp;
	return (ret);
}

static void	append(char **save, char *read_buffer, int read_count)
{
	char	*swp;

	if (!read_buffer)
		return ;
	read_buffer[read_count] = 0;
	swp = ft_strjoin(*save, read_buffer);
	free(*save);
	*save = swp;
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		read_buffer[512 + 1];
	int			read_count;
	int			index;

	index = -1;
	if (read(fd, 0, 0))
		return (NULL);
	while (1)
	{
		index = newline_index(save);
		if (index > -1)
			break ;
		read_count = read(fd, read_buffer, 512);
		if (read_count == 0)
			break ;
		if (!save)
			save = ft_substr(read_buffer, 0, read_count);
		else
			append(&save, read_buffer, read_count);
	}
	if (!save)
		return (NULL);
	return (extract(&save, read_count));
}
