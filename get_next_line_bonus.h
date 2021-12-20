/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:23:18 by hhamza            #+#    #+#             */
/*   Updated: 2021/12/19 18:51:03 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

// Utils
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		ft_indexof(const char *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(const char *s1, const char *s2);

// Main functions
char	*get_next_line(int fd);
char	*ft_save_remainder(char *line, char *remainder, ssize_t read_size);

#endif