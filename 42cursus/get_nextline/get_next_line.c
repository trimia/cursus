/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:05:59 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/16 20:36:41 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*line_n;
	char		*temp;
		
	line_n = NULL;
	temp = NULL;
	buffer = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	while (!ft_find(line_n, '\n') && read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line_n = ft_strjoin(line_n, buffer);
		ft_memcpy(line_n, temp);
		
	}
	return (temp);
}

#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

// int main(int argc, char **argv)
// {
// 	int fd, ret, line_count;
// 	char *line;

// 	line_count = 1;
// 	ret = 0;
// 	line = NULL;
// 	if (argc == 2)
// 	{
// 		fd = open(argv[1], O_RDONLY);
// 		while ((ret = get_next_line(fd, &line)) > 0)
// 		{
// 			printf(" \n [ Return: %d ] | A line has been read #%d => %s\n", ret, line_count, line);
// 			line_count++;
// 			free(line);
// 		}
// 		printf(" \n [ Return: %d ] A line has been read #%d: %s\n", ret, line_count++, line);
// 		printf("\n");
// 		if (ret == -1)
// 			printf("-----------\n An error happened\n");
// 		else if (ret == 0)
// 		{
// 			printf("-----------\n EOF has been reached\n");
// 			free(line);
// 		}
// 		close(fd);
// 	}
// 	if (argc == 1)
// 	{
// 		while ((ret = get_next_line(0, &line)) > 0)
// 		{
// 			printf("[Return: %d] Line #%d: %s\n", ret, line_count, line);
// 			line_count++;
// 		}
// 		if (ret == -1)
// 			printf("\n An error happened\n");
// 		else if (ret == 0)
// 			printf("\n EOF has been reached\n");
// 		close(fd);
// 	}
// 	return (0);
// }