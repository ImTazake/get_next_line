#include "get_next_line_bonus.h"

static char	*fill_stash(int fd, char *stash)
{
	t_read	data;

	if (ft_strchr(stash, '\n'))
		return (stash);
	data.buffer = malloc(BUFFER_SIZE + 1);
	if (!data.buffer)
		return (free(stash), NULL);
	data.bytes = 1;
	while (data.bytes > 0 && !ft_strchr(stash, '\n'))
	{
		data.bytes = read(fd, data.buffer, BUFFER_SIZE);
		if (data.bytes < 0)
			return (free(data.buffer), free(stash), NULL);
		data.buffer[data.bytes] = '\0';
		data.temp = ft_strjoin(stash, data.buffer);
		if (!data.temp)
			return (free(data.buffer), free(stash), NULL);
		free(stash);
		stash = data.temp;
	}
	free(data.buffer);
	return (stash);
}

static char	*get_line(char *stash)
{
	char	*line;
	size_t	len;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	while (len--)
		line[len] = stash[len];
	return (line);
}

static char	*new_stash(char *stash)
{
	t_string	data;

	data.i = 0;
	while (stash[data.i] && stash[data.i] != '\n')
		data.i++;
	if (!stash[data.i] || !stash[data.i + 1])
		return (free(stash), NULL);
	data.i++;
	data.result = malloc(ft_strlen(stash + data.i) + 1);
	if (!data.result)
		return (free(stash), NULL);
	data.j = 0;
	while (stash[data.i])
		data.result[data.j++] = stash[data.i++];
	data.result[data.j] = '\0';
	free(stash);
	return (data.result);
}

char	*get_next_line(int fd)
{
	static char	*stash[FD_MAX];
	char		*line;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, NULL, 0) < 0)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	stash[fd] = fill_stash(fd, stash[fd]);
	if (!stash[fd] || !*stash[fd])
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	line = get_line(stash[fd]);
	if (!line)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	stash[fd] = new_stash(stash[fd]);
	return (line);
}
