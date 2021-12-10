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

char	*ft_memmove(char *str1, char *str2, size_t n)
{
	if (!str1 || !str2)
		return (NULL);
	if (str1 <= str2)
	{
		while (n--)
		{
			*str1 = *str2;
			str1++;
			str2++;
		}
	}
	else
	{
		while (n--)
		{	
			str1[n] = str2[n];
		}
	}
	return (str1);
}

char	*ft_strjoin(char *str1, char *str2, int size1, int size2)
{
	char	*new;

	new = malloc(sizeof(char) * (size1 + size2 + 1));
	ft_memmove(new, str1, size1);
	ft_memmove(new + size1, str2, size2);
	new[size1 + size2] = '\0';
	free(str1);
	return (new);
}

int	ft_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1 * i);
}

void	ft_save_buff(char *buffer, int pos)
{
	int i;
	
	if (pos == ft_strlen(buffer))
	{
		buffer[0] = '\0';
		return ;
	}
	i = 0;
	while (buffer[pos])
	{
		buffer[i] = buffer[pos];
		i++;
		pos++;
	}
	buffer[i] = '\0';
}
