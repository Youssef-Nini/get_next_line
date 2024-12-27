
#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *stock = NULL;
	char buffer[BUFFER_SIZE + 1];
	char *tmp;
	ssize_t bytes_read;
	int i = 0;
	int j = 0;

	while(bytes_read = read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[bytes_read] = '\0';

		tmp = ft_strjoin(tmp, stock);

		if (ft_strchr(tmp , '\n'))
			break;
	}
	while(tmp[i] && tmp[i] != '\n')
	{
		stock[i] = tmp[i];
		i++;
	}
	stock[i] = '\0';
	printf("stock : %s\n", stock);
	return stock;
}
int main(){
	int fd = open("file.txt",O_RDONLY);
	printf("fd: %d\n", fd);
	get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// printf("read:%s", get_next_line(fd));
	
}	

