/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutdili <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:59:24 by moutdili          #+#    #+#             */
/*   Updated: 2024/11/17 00:48:59 by moutdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char **rem)
{
	char	*line;
	char	*temp;
	char	*newline;

	newline = ft_strchr(*rem, '\n');
	if (newline)
	{
		line = ft_substr(*rem, 0, newline - *rem + 1);
		temp = ft_strdup(newline + 1);
		free(*rem);
		*rem = temp;
	}
	else
		return (line = ft_strdup(*rem), free(*rem), *rem = NULL, line);
	return (line);
}

void	ft_free(char *remainder, char *buffer)
{	
	free(buffer);
	free(remainder);
	remainder = NULL;
}

char	*read_and_append(int fd, char *remainder)
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
			break ;
		buffer[read_bytes] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		temp = ft_strjoin(remainder, buffer);
		free(remainder);
		remainder = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (read_bytes == -1)
		return (ft_free(remainder, buffer), NULL);
	return (free(buffer), remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_and_append(fd, remainder);
	if (!remainder)
		return (NULL);
	if (*remainder == '\0')
		return (free(remainder), remainder = NULL, NULL);
	return (line = extract_line(&remainder), line);
}
