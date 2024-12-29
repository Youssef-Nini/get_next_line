
#include "get_next_line.h"
char *get_rid_line(char *str)
{
	
}
char *get_next_line(int fd)
{
	static char *stock = NULL;
	char buffer[BUFFER_SIZE + 1];
	char *tmp;
	ssize_t bytes_read;
	int i = 0;
	int j = 0;
	stock = malloc(1);

	while((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		// printf("bytes_read : %d\n" , bytes_read);
		buffer[bytes_read] = '\0';
		// printf("buffer : %s\n ", buffer);

		tmp = ft_strjoin(tmp, buffer);

		if (ft_strchr(tmp , '\n'))
			break;
	}
	while(tmp[i] && tmp[i] != '\n')
	{
		stock[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		stock[i] = '\n';
	else
		stock[i] = '\0';
	tmp = NULL;
	printf("stock : %s", stock);
	return stock;
}
int main(){
	int fd = open("file.txt",O_RDONLY);
	printf("fd: %d\n", fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	// get_next_line(fd);
	// printf("read:%s", get_next_line(fd));
	
}	

