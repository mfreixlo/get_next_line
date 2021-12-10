#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*aux;
	const char	*str;

	if (!str1 || !str2)
		return (NULL);
	aux = str1;
	str = str2;
	if (str1 <= str2)
	{
		while (n--)
		{
			*aux = *str;
			if (*str == '\n')
				break;
			aux++;
			str++;
		}
	}
	else
	{
		while (n--)
		{	
			aux[n] = str[n];
			if (str[n] == '\n')
				break;
		}
	}
	return (str1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t size1;
	size_t size2;
	size_t size_tot;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	size_tot = size1 + size2;
	new = malloc(sizeof(char) * (size_tot + 1));
	ft_memmove(new, s1, size1);
	ft_memmove(new + size1, s2, size2);
	new[size1 + size2] = '\0';
	free((char*)s1);
	return (new);
}

int ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	c = c % 256;
	while (s[i])
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	return (-1);
}

int main()
{
	char *line;
	int fd;

	fd = open("/home/marta/Documents/42/get_next_line/teste", O_RDONLY);
	
	printf("%s", line);	
	return (0);
}



/*
char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *line;
	ssize_t n;
	int i;

	line = NULL;
	n = read(fd, buffer, BUFFER_SIZE);
	while (n > 0)
	{
		buffer[n] = '\0';
		line = ft_strjoin(line, buffer);
		printf("%s\n", buffer);
		i = ft_strchr(buffer, '\n');
		if (i != -1)
		{
			ft_memmove(buffer, buffer + i, BUFFER_SIZE);
			return (line);
		}
		n = read(fd, buffer, BUFFER_SIZE);
	}
	return (0);
}
*/


