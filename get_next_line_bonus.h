/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhafiz <mhafiz@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-11-04 15:12:17 by mhafiz            #+#    #+#             */
/*   Updated: 2026-11-04 15:12:17 by mhafiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define GNL_MAX_FD 2048

size_t	ft_strlen_gnl_bonus(const char *s);
char	*ft_strchr_gnl_bonus(char *s, int c);
char	*ft_substr_gnl_bonus(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl_bonus(char *s1, char const *s2);
char	*get_next_line_bonus(int fd);

#endif
