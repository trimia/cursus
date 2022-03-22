/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:05:59 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/22 21:26:10 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

static char	*readfd(char *line_n, int fd)
{
	char		*buffer;
	buffer = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE) > 0 && !ft_find(line_n))
	{
		line_n = ft_strjoin(line_n, buffer);
		// if (ft_find(line_n))
		// 	break;
	}
	free (buffer);
	return (line_n);
}

// char	*get_next(char *line_n)
// {
// 	char	*temp;
// 	int		i;

// 	i = 0;
// 	if (!line_n)
// 		return(NULL);
// 	while (line_n[i] != '\n')
// 		i++;
// 	temp = (char *) malloc (sizeof(char) * i);
// 	if (!temp)
// 		return (NULL);
// 	temp = ft_strdup("");
// 	while (*line_n != '\n')
// 		*temp++ = *line_n++;
	
// 	if (*line_n++ == '\n')
// 		temp[i] ='\n';
// 	else
// 		temp[i] ='\0';
// 	// free (line_n);
// 	return (temp - i);
// }

char	*get_next_line(int fd)
{
	char		*temp;
	int			i;
	static char	*line_n;
		
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line_n = readfd(line_n, fd);
	// temp = get_next(line_n);
	// // free(line_n);
	// return (temp);

	
	if (!line_n)
		return(NULL);
	while (line_n[i] != '\n')
		i++;
	temp = (char *) malloc (sizeof(char) * i + 1);
	if (!temp)
		return (NULL);
	temp = ft_strdup("");
	while (*line_n != '\n')
		*temp++ = *line_n++;
	
	if (*line_n++ == '\n')
		temp[i] ='\n';
	temp[i + 1] ='\0';
	// line_n -= i;
	return (temp - i);

}

#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int main ()
{
	int fd;

	fd = open("text.txt", O_RDONLY); 
	printf("%s",get_next_line(fd));

}



#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
int	main(void)
{
	/*
	Here, In this code first open() returns 3 because when main process created,
	then fd 0, 1, 2 are already taken by stdin, stdout and stderr.
	*/
	char *temp;
	char *temp2;
	int file_descriptor = open("text.txt", O_RDONLY);
	//printf("file_descriptor: %d \n", file_descriptor);
	temp = get_next_line(file_descriptor);
	temp2 = get_next_line(file_descriptor);
	printf("%s", temp);
	free(temp);
	printf("%s", temp2);
	free(temp2);
	/*
	printf("\n\n");
	printf("%s$", get_next_line(file_descriptor));
	printf("\n\n");
	printf("%s$", get_next_line(file_descriptor));
	printf("\n\n");
	*/
	return (0);
}

// char	*get_next_line(int fd)
// {
// 	int	rd;
// 	int	i = 0;
// 	char	c;
// 	char	*buffer = malloc(9999);

// 	while ((rd = read(fd, &c, 1) > 0))
// 	{
// 		buffer[i] = c;
// 		i++;
// 		if (c == '\n')
// 			break ;
// 	}
// 	if ((!buffer[i - 1] && !rd) || rd == -1)
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	i++;
// 	buffer[i] = '\0';
// 	return (buffer);
// }