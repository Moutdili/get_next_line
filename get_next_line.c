#include "get_next_line.h"

static char	*extract_line(char **remainder)
{
    char	*line;
    char	*temp;
    char	*newline;

    newline = ft_strchr(*remainder, '\n');
    if (newline)
    {
        line = ft_substr(*remainder, 0, newline - *remainder + 1);
        temp = ft_strdup(newline + 1);
        free(*remainder);
        *remainder = temp;
    }
    else
    {
        line = ft_strdup(*remainder);
        free(*remainder);
        *remainder = NULL;
    }
    return (line);
}

static char	*read_and_append(int fd, char *remainder)
{
    char	*buffer;
    char	*temp;
    int		read_bytes;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);

    while (1)
    {
        read_bytes = read(fd, buffer, BUFFER_SIZE);
        if (read_bytes <= 0)
            break;
        buffer[read_bytes] = '\0';
        if (!remainder)
            remainder = ft_strdup("");
        temp = ft_strjoin(remainder, buffer);
        free(remainder);
        remainder = temp;
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(buffer);
    return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (!remainder)
        remainder = ft_strdup("");
    if (fd < 0 || BUFFER_SIZE <= 0 )
        return (NULL);
    remainder = read_and_append(fd, remainder);
    if (!remainder)
        return (NULL);
    if (*remainder == '\0')
    {
        free(remainder);
        remainder = NULL;
        return (NULL);
    }
    line = extract_line(&remainder);
    return (line);
}
