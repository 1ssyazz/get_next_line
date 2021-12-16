/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:14:21 by msukri            #+#    #+#             */
/*   Updated: 2021/12/16 16:03:15 by msukri           ###   ########.fr       */
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

int	get_next_line(int fd, char **line)
{
	ssize_t		r;
	char		*buf;
	int			i;
	static char	*next_line;
	char		*tmp;

	r = read(fd, buf, BUFFER_SIZE);
	next_line == NULL;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (next_line == NULL)
		next_line = ft_calloc(1 * sizeof(char));
	else
		NULL;
	while (!ft_strchr(next_line, '\n') && r > 0)
		ft_solve_next_line();
}
