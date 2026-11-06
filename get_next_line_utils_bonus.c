/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhafiz <mhafiz@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-04 15:11:57 by mhafiz            #+#    #+#             */
/*   Updated: 2026-11-04 15:11:57 by mhafiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl_bonus(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strchr_gnl_bonus(char *s, int c)
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

size_t	ft_strlcpy_gnl_bonus(char *dest, char const *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen_gnl_bonus(src);
	i = 0;
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

char	*ft_substr_gnl_bonus(char const *s, unsigned int start, size_t len)
{
	size_t	actual_len;
	size_t	str_len;
	char	*sub;

	if (!s)
		return (NULL);
	str_len = ft_strlen_gnl_bonus(s);
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
	ft_strlcpy_gnl_bonus(sub, s + start, actual_len + 1);
	return (sub);
}

char	*ft_strjoin_gnl_bonus(char *s1, char const *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;

	if (!s1)
	{
		return (ft_substr_gnl_bonus(s2, 0, ft_strlen_gnl_bonus(s2)));
	}
	len1 = ft_strlen_gnl_bonus(s1);
	len2 = ft_strlen_gnl_bonus(s2);
	new_str = malloc(sizeof(char) * (len1 + len2) + 1);
	if (!new_str)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy_gnl_bonus(new_str, s1, len1 + 1);
	ft_strlcpy_gnl_bonus(new_str + len1, s2, len2 + 1);
	free(s1);
	return (new_str);
}
