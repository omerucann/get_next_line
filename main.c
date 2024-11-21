#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

 
    fd = open("test.txt", O_RDONLY | O_CREAT | O_WRONLY, 0777);
    write(fd, "Hello\nWorld", 11);
    line = get_next_line(fd);
    close(fd);
    return (0);
}