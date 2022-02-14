/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:14:21 by msukri            #+#    #+#             */
/*   Updated: 2022/02/14 14:46:34 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}	

void	*ft_calloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != (char)c)
		if (!str[i++])
			return (NULL);
	return ((char *)&str[i]);
}

char	ft_solve_n_line(char *buf, ssize_t *r, char **n_line, char ***line)
{
	char	*tmp;
	
	while (!ft_strchr(*n_line, '\n') && *r > 0)
	{
		buf[*r] = '\0';
		tmp = ft_strjoin(*n_line, buf);
		ft_memfree((void ***)&n_line);
		*n_line = tmp;
	}
	if (*r == 0)
		**line = ft_strdup(*n_line);
	else if (*r > 0)
		**line = ft_substr(*n_line, 0, (ft_strchr(*n_line, '\n') - *n_line));
	else
		return (-1);
	if (*r > 0)
		tmp = ft_strdup(*n_line + (ft_strlen(**line) + 1));
	else
		tmp = ft_strdup(*n_line + (ft_strlen(**line)));
	ft_memfree((void ***)&n_line);
	*n_line = tmp;
	return (*tmp);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		r;
	char		buf[BUFFER_SIZE + 1];
	static char	*n_line;

	r = 1;
	if (!n_line)
	{
		r = read(fd, buf, BUFFER_SIZE);
		n_line = NULL;
	}
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (n_line == NULL)
		n_line = ft_calloc(1 * sizeof(char));
	else
		NULL;
	ft_solve_n_line(buf, &r, &n_line, &line);
	if (r == 0)
		return (0 * ft_memfree((void ***)&n_line));
	else
		return (1);
}
