/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:49:13 by mmariani          #+#    #+#             */
/*   Updated: 2022/05/13 16:58:16 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

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

static char	*copy(char *line_n, char *temp)
{
	int	j;

	j = 0;
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
	char			*temp;
	unsigned int	i;
	unsigned int	j;
	static char		*line_n = NULL;

	i = 0;
	j = 0;
	if (fd > 256 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_n = readfd(line_n, fd);
	while (line_n && line_n[i] && line_n[i] != '\n')
		i++;
	if (i == 0 && !line_n)
		return (NULL);
	temp = (char *) malloc (i + 2);
	if (!temp)
		return (NULL);
	temp = copy(line_n, temp);
	if (!line_n[j])
		free(line_n);
	else
		line_n = ft_substr(line_n, i + 1, ft_strlen(line_n));
	return (temp);
}
