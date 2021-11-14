#include "get_next_line.h"

char	*get_text(int fd)
{
	char	*buffer;
	int		n;
	char	*aux;
	char	*str;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	n = ft_read(fd, buffer);
	if (n == -1)
	{
		return (NULL);
	}
	aux = NULL;
	while (n > 0)
	{
		str = ft_strjoin(aux, buffer);
		aux = ft_strdup(str);
		free(str);
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		n = read(fd, buffer, BUFFER_SIZE);
		buffer[n] = '\0';
	}
	free(buffer);
	return (aux);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static char	*buffer;

	if (buffer == NULL)
		buffer = get_text(fd);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	i = -1;
	while (buffer[++i] && buffer[i - 1] != '\n')
		line[i] = buffer[i];
	line[i] = '\0';
	if (i == 0)
	{
		free(buffer);
		free(line);
		return (NULL);
	}
	buffer = ft_save_buff(buffer, i);
	return (line);
}
