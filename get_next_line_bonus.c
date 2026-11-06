/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhafiz <mhafiz@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-04 15:13:27 by mhafiz            #+#    #+#             */
/*   Updated: 2026-11-04 15:13:27 by mhafiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_file(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (stash);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr_gnl_bonus(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_gnl_bonus(stash, buffer);
		if (!stash)
			break ;
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	len;

	if (!stash || !*stash)
	{
		return (NULL);
	}
	len = 0;
	while (stash[len] != '\0' && stash[len] != '\n')
	{
		len++;
	}
	if (stash[len] == '\n')
	{
		len++;
	}
	return (ft_substr_gnl_bonus(stash, 0, len));
}

static char	*recover_extra(char *stash)
{
	size_t	len;
	char	*extra;

	len = 0;
	while (stash[len] != '\0' && stash[len] != '\n')
	{
		len++;
	}
	extra = ft_substr_gnl_bonus(stash, len + 1,
			ft_strlen_gnl_bonus(stash + len + 1));
	free(stash);
	return (extra);
}

char	*get_next_line_bonus(int fd)
{
	static char	*stash[GNL_MAX_FD];
	char		*line;

	if (fd < 0 || fd >= GNL_MAX_FD || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	stash[fd] = read_file(fd, stash[fd]);
	if (!stash[fd])
	{
		free(stash[fd]);
		return (NULL);
	}
	line = extract_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = recover_extra(stash[fd]);
	return (line);
}
