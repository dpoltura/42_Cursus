/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:40:27 by user              #+#    #+#             */
/*   Updated: 2023/12/06 19:18:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char const *str);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_buftostr(char *str, int fd);
char	*ft_strjoin_gnl(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_getline(char *str);
char	*ft_clear(char *str);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
