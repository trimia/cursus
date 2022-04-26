/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:05:59 by mmariani          #+#    #+#             */
/*   Updated: 2022/04/15 19:24:28 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

static char	*readfd(char *line_n, int fd)
{
	char	*buffer;
	int i;

	buffer = (char *) malloc (BUFFER_SIZE + 1);
	// printf("readfdriga21 %p\n",buffer);
	if (!buffer)
		return (NULL);
	while (ft_find(line_n))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if(i > 0)
		{
			buffer[i] = 0;
			line_n = ft_strjoin(line_n, buffer);	
		}
		else
		{
			free(buffer);
			return (line_n);
		}
	}
	free (buffer);
	return (line_n);
}

char	*get_next_line(int fd)
{
	char		*temp;
	int			i;
	int			j;
	static char	*line_n;
		
	i = 0;
	j = 0;
	if (fd > 256 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if(!line_n)
		line_n = ft_strdup("");
		// printf("getnextlineriga55 %p\n",line_n);
	line_n = readfd(line_n, fd);
	while (line_n && line_n[i] && line_n[i] != '\n')
		i++;
	if (i == 0 && line_n[i] != '\n')
		return (NULL);
	temp = (char *) malloc (i + 2);
	// printf("getnextlineriga62 %p\n",temp);
	if (!temp)
		return (NULL);
	while (line_n[j] && line_n[j] != '\n')
	{
		temp[j] = line_n[j];
		j++;
	}	
	if (line_n[j] == '\n')
	{
		temp[j] ='\n';
		j++;
	}
	if (!line_n[j])
		free(line_n);
	line_n = ft_substr(line_n, i + 1, ft_strlen(line_n));
	temp[j] = '\0';
	return (temp);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <limits.h>

// void check_leaks();

// int main ()
// {
// 	int fd;

// 	fd = open("text.txt", O_RDONLY); 
// 	printf("%s",get_next_line(fd));
// }

// #include <stdio.h>
// #include <fcntl.h>
// #include <limits.h>

// void check_leaks();


// int	main(void)
// {
// 	/*
// 	Here, In this code first open() returns 3 because when main process created,
// 	then fd 0, 1, 2 are already taken by stdin, stdout and stderr.
// 	*/
// 	char *temp;
// 	char *temp2;
// 	char *temp3;
// 	char *temp4;
// 	int file_descriptor = open("nl", O_RDONLY);
// 	//printf("file_descriptor: %d \n", file_descriptor);
// 	temp = get_next_line(file_descriptor);
// 	temp2 = get_next_line(file_descriptor);

// 	temp3 = get_next_line(file_descriptor);
// 	temp4 = get_next_line(file_descriptor);
// 	printf("%s", temp);
// 	free(temp);
// 	printf("temp2=%s\n", temp2);
// 	free(temp2);
// 	printf("temp3=%s\n", temp3);
// 	free(temp3);
// 	printf("temp4=%s\n", temp4);
// 	free(temp4);
// 	/*
// 	printf("\n\n");
// 	printf("%s$", get_next_line(file_descriptor));
// 	printf("\n\n");
// 	printf("%s$", get_next_line(file_descriptor));
// 	printf("\n\n");
// 	*/
// }

