/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:05:59 by mmariani          #+#    #+#             */
/*   Updated: 2022/05/03 20:06:13 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

static char	*readfd(char *line_n, int fd)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = (char *) malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_find(line_n))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
			break ;
		buffer[i] = 0;
		line_n = ft_strjoin(line_n, buffer);
		if (i < BUFFER_SIZE)
			break ;
	}
	free (buffer);
	return (line_n);
}

static char	*copy(char *line_n, char *temp, int j)
{
	while (line_n[j] && line_n[j] != '\n')
	{
		temp[j] = line_n[j];
		j++;
	}	
	if (line_n[j] == '\n')
	{
		temp[j] = '\n';
		j++;
	}
	temp[j] = '\0';
	if (!line_n[j])
		free (line_n);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*temp;
	int			i;
	int			j;
	static char	*line_n[FOPEN_MAX] = {};

	i = 0;
	j = 0;
	if (fd > FOPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_n[fd] = readfd(line_n[fd], fd);
	while (line_n[fd] && line_n[fd][i] && line_n[fd][i] != '\n')
		i++;
	if (i == 0 && !line_n[fd])
		return (NULL);
	temp = (char *) malloc (i + 2);
	if (!temp)
		return (NULL);
	temp = copy(line_n[fd], temp, j);
	if (!line_n[fd][j])
		free(line_n);
	line_n[fd] = ft_substr(line_n[fd], i + 1, ft_strlen(line_n[fd]));
	return (temp);
}
