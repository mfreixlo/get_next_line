#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			i++;
		}
	}
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	char	*new;
	int		k;

	new = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	k = 0;
	i = 0;
	if (str1)
		while (str1[i])
			new[k++] = str1[i++];
	i = 0;
	if (str2)
		while (str2[i])
			new[k++] = str2[i++];
	new[k] = '\0';
	free(str2);
	free(str1);
	return (new);
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[j])
	{
		new[i] = str[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_save_buff(char *buffer, int pos)
{
	char	*aux;

	aux = ft_strdup(&buffer[pos]);
	free(buffer);
	return (aux);
}

int	ft_read(int fd, char *buffer)
{
	int	n;

	n = read(fd, NULL, 0);
	if (n == -1 || BUFFER_SIZE <= 0 || fd < 0)
	{
		free(buffer);
		return (-1);
	}
	else
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == 0 || n > 1024)
		{
			free(buffer);
			return (-1);
		}
		buffer[n] = '\0';
	}
	return (n);
}
