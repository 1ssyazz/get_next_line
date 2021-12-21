/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 21:10:41 by msukri            #+#    #+#             */
/*   Updated: 2021/06/20 21:10:41 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int		get_next_line(int fd, char **line);
void	ft_solve_n_line(char *buf, ssize_t r, char *tmp, char *n_line);

void	*ft_calloc(size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_memfree(void **ptr);

char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif