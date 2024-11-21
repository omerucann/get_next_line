#include "get_next_line.h"

int ft_find(char *s)
{
    unsigned int i;

    if(!s)
        return (-1);
    i = 0;
    while(s[i] != '\n' && s[i] !='\0')
        i++;
    if(s[i] == '\0')
        return (-1);
    return (i);
}
char *ft_create_line(char *buf, int index)
{
    char *line;
    int i;

    line = (char *)malloc((index + 2) * sizeof(char));
    if(!line)
        return (NULL);
    i = 0;
    while(buf[i] != '\n')
    {
        line[i] = buf[i];
        i++;
    }
    line[i] = '\n';
    line[i + 1] = '\0';
    return (line);
}
char *ft_cal_line(char *buf)
{
    char *line;
    int i;

    if(ft_strlen(buf) <= 0)
        return (NULL);
    i = ft_find(buf);
    if(i == -1 || i == ((int)ft_strlen(buf) - 1))
    {
        line = ft_strdup(buf);
        return(line);
    }
    line = ft_create_line(buf, i);
    return (line);
}
char *ft_cal_buf(char *buf)
{
    int i;
    unsigned int len;

    if(!buf)
        return (NULL);
    len = ft_strlen(buf);
    i = ft_find(buf);
    if(i == -1 || ((len - i) == 1))
    {
        free(buf);
        return (NULL);
    }
    buf = ft_substr(buf, (i + 1), (len - i - 1));
    return (buf);
}
char *get_next_line(int fd)
{
    char *buffer;
    char *line;
    int b_read;
    static char *buf[1024];

    if(BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if(!buffer)
        return (NULL);
    b_read = 1;
    while(ft_find(buf) == -1)
    {
        b_read = read(fd, buffer, BUFFER_SIZE);
        if(b_read <= 0)
            break;
        buffer[b_read] = '\0';
        buf[fd] = ft_strjoin(buf, buffer);
    }
    free(buffer);
    if(b_read == -1)
        return (NULL);
    line = ft_cal_line(buf);
    buf[fd] = ft_cal_buf(buf);
    return (line);
}