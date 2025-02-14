#include "get_next_line_bonus.h"

static char	*extract_line(char **storage)
{
	char	*newline;
	char	*remaining;
	char	*result;
	size_t	newline_len;
	size_t	remaining_len;

	newline = ft_strchr(*storage, '\n');
	if (newline)
	{
		newline_len = newline - *storage + 1;
		result = ft_strndup(*storage, newline_len);
		remaining_len = ft_strlen(newline + 1);
		remaining = ft_strndup(newline + 1, remaining_len);
		free(*storage);
		*storage = remaining;
	}
	else
	{
		result = ft_strndup(*storage, ft_strlen(*storage));
		free(*storage);
		*storage = NULL;
	}
	return (result);
}

static void	get_next_line_reader(ssize_t *bytes_read, int *fd, char **storage,
		char *buffer)
{
	char	*temp;

	while (1)
	{
		*bytes_read = read(*fd, buffer, BUFFER_SIZE);
		if (*bytes_read <= 0)
			break ;
		buffer[*bytes_read] = '\0';
		temp = ft_strjoin(*storage, buffer);
		free(*storage);
		*storage = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
}

char	*get_next_line(int fd)
{
	static char	*storages[FD_MAX];
	ssize_t		bytes_read;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	get_next_line_reader(&bytes_read, &fd, &storages[fd], buffer);
	if (!storages[fd] || !*storages[fd] || bytes_read < 0)
	{
		free(storages[fd]);
		storages[fd] = NULL;
		return (NULL);
	}
	return (extract_line(&storages[fd]));
}
