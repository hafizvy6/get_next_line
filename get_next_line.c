/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhafiz <mhafiz@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-02 09:06:17 by mhafiz            #+#    #+#             */
/*   Updated: 2026-11-02 09:06:17 by mhafiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (stash);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr_gnl(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
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
	return (ft_substr_gnl(stash, 0, len));
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
	if (stash[len] == '\0')
	{
		free(stash);
		return (NULL);
	}
	extra = ft_substr_gnl(stash, len + 1, ft_strlen_gnl(stash + len + 1));
	free(stash);
	return (extra);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	stash = read_file(fd, stash);
	if (!stash)
	{
		return (NULL);
	}
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = recover_extra(stash);
	return (line);
}
