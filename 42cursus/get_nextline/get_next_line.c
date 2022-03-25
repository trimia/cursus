/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariani <mmariani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:05:59 by mmariani          #+#    #+#             */
/*   Updated: 2022/03/25 21:46:46 by mmariani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

static char	*readfd(char *line_n, int fd)
{
	char	*buffer;

	buffer = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_find(line_n))
	{
		if(read(fd, buffer, BUFFER_SIZE)>0)
			line_n = ft_strjoin(line_n, buffer);
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
	int			j;
	static char	*line_n;
	// char		*ritemp;
		
	i = 0;
	j = -1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if(!line_n)
	{
		line_n = ft_strdup("");
	}
	
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
	while (++j <= i)
		temp[j] = line_n[j];	
	if (line_n[i] == '\n')
		temp[j] ='\n';
	temp[j] ='\0';
	// line_n = readfd(line_n, fd);
	// printf("prima %s",line_n);
	line_n = ft_substr(line_n, i+1, (ft_strlen(line_n)-(i+1)));
	// printf("dopo %s",line_n);
	return (temp);

}

// #include <stdio.h>
// #include <fcntl.h>
// #include <limits.h>

// int main ()
// {
// 	int fd;

// 	fd = open("text.txt", O_RDONLY); 
// 	printf("%s",get_next_line(fd));
// }



// #include <stdio.h>
// #include <fcntl.h>
// #include <limits.h>
// int	main(void)
// {
// 	/*
// 	Here, In this code first open() returns 3 because when main process created,
// 	then fd 0, 1, 2 are already taken by stdin, stdout and stderr.
// 	*/
// 	char *temp;
// 	char *temp2;
// 	char *temp3;
// 	int file_descriptor = open("text.txt", O_RDONLY);
// 	//printf("file_descriptor: %d \n", file_descriptor);
// 	temp = get_next_line(file_descriptor);
// 	temp2 = get_next_line(file_descriptor);

// 	temp3 = get_next_line(file_descriptor);
// 	printf("%s", temp);
// 	free(temp);
// 	printf("temp2=%s", temp2);
// 	free(temp2);
// 	printf("temp3=%s", temp3);
// 	free(temp3);
// 	/*
// 	printf("\n\n");
// 	printf("%s$", get_next_line(file_descriptor));
// 	printf("\n\n");
// 	printf("%s$", get_next_line(file_descriptor));
// 	printf("\n\n");
// 	*/
// }

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