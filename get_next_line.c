
#include "get_next_line.h"
#include <libc.c>

char *get_next_line(int fd)
{
	static char *buffer;
	read(fd, buffer,BUFFER_SIZE);
	return buffer;
}
int main(){
	int fd = open("file.txt",O_RDONLY);
	printf("read:%s", get_next_line(fd);
	
}	

