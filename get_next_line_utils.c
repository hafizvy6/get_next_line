/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhafiz <mhafiz@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-02 09:06:14 by mhafiz            #+#    #+#             */
/*   Updated: 2026-11-02 09:06:14 by mhafiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	size_t	i;

	if (!s)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0' && s[i] != (char)c)
	{
		i++;
	}
	if (s[i] == (char)c)
	{
		return ((char *)(s + i));
	}
	return (NULL);
}

size_t	ft_strlcpy_gnl(char *dest, char const *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen_gnl(src);
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	actual_len;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen_gnl(s);
	if (start >= str_len)
	{
		len = 0;
	}
	actual_len = str_len - start;
	if (actual_len > len)
	{
		actual_len = len;
	}
	sub = malloc(actual_len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy_gnl(sub, s + start, actual_len + 1);
	return (sub);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;

	if (!s1)
	{
		return (ft_substr_gnl(s2, 0, ft_strlen_gnl(s2)));
	}
	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	new_str = (char *)malloc(sizeof(char) * ((len1 + len2) + 1));
	if (!new_str)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy_gnl(new_str, s1, len1 + 1);
	ft_strlcpy_gnl(new_str + len1, s2, len2 + 1);
	free(s1);
	return (new_str);
}
