/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smiranda <smiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:23:34 by smiranda          #+#    #+#             */
/*   Updated: 2024/06/19 15:15:37 by smiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*line_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_buffer = ft_get_buffer(fd, line_buffer);
	if (!line_buffer)
		return (NULL);
	line = ft_get_line(line_buffer);
	line_buffer = ft_get_rest(line_buffer);
	return (line);
}

char	*ft_get_buffer(int fd, char *line_buffer)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!gnl_strchr(line_buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(line_buffer);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line_buffer = gnl_strjoin(line_buffer, buffer);
		if (!line_buffer)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (line_buffer);
}

char	*ft_get_line(char *line_buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!line_buffer[i])
		return (NULL);
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
	{
		line[i] = line_buffer[i];
		i++;
	}
	if (line_buffer[i] == '\n')
	{
		line[i] = line_buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_rest(char *line_buffer)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (line_buffer[i] && line_buffer[i] != '\n')
		i++;
	if (!line_buffer[i])
		return (free(line_buffer), NULL);
	rest = (char *)malloc((ft_strlen(line_buffer) - i + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (line_buffer[i])
		rest[j++] = line_buffer[i++];
	rest[j] = '\0';
	i = -1;
	while (rest[++i])
		line_buffer[i] = rest[i];
	line_buffer[i] = '\0';
	free(rest);
	return (line_buffer);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		count;

// 	count = 0;
// 	fd = open("output1.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error opening file");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		count++;
// 		printf("[%d]:%s", count, line);
// 		free(line);
// 		line = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }