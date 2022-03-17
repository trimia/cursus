#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int		get_next_line(int fd, char **line);

int	main()
{
	int		ret;
	int		fd;
	char	*line;

//*line�� ����� ���·� get_next_line �Լ��� �Ѿ

	fd = open("text.txt", O_RDONLY);
	while ((ret = (get_next_line(fd, &line)) > 0))
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	
	close(fd);
	return 0;
}