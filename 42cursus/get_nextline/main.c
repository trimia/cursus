#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

char *get_next_line(int fd);

int	main()
{
	int		ret;
	int		fd;
	char	*line;


	fd = open("cacca.txt", O_RDONLY);
   line = get_next_line(fd);
	
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	
	close(fd);
	return 0;
}