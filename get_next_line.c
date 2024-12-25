
#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char tmp[BUFFER_SIZE + 1];
	char stock[BUFFER_SIZE + 1];
	ssize_t bytes_read;
	int i = 0;
	int j = 0;
	if (buffer[0] == '\0')
	{
		bytes_read = read(fd, buffer,BUFFER_SIZE);
		buffer[bytes_read] = '\0';
	}
	// printf("read :%d\n",bytes_read);
	// printf("buffer: %s>>>>>\n ", buffer);
	while(buffer[i] && buffer[i] != '\n')
	{
		stock[i] = buffer[i];
		i++;
	}
	if (buffer[i] = '\n')
		stock[i] = '\n';
	else
		stock[i] = '\0';
	while (buffer[j] !='\0')
	{
		tmp[j] = buffer[j];
		j++;
	}
	tmp[j] = '\0';
	j = 0;
	i++;
	while(tmp[i])
	{
		buffer[j] = tmp[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
	// printf("buffer2: %s\n" , buffer);
	printf("stock: %s", stock);
	printf("buffer: %s", buffer);
	return buffer;
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

