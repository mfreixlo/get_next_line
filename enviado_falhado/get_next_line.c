#include <time.h>
#include <string.h>
#include "get_next_line.h"

int	ft_read(int fd, char *buffer)
{
	int	n;

	if (fd < 0)
	{
		buffer[0] = '\0';
		return (-1);
	}
	n = read(fd, NULL, 0);
	if (n == -1 || BUFFER_SIZE <= 0 || fd < 0)
	{
		buffer[0] = '\0';
		return (-1);
	}
	else
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == 0)
		{
			buffer[0] = '\0';
			return (-1);
		}
		buffer[n] = '\0';
	}
	return (n);
}

char    *get_next_line(int fd)
{
	static char     buffer[BUFFER_SIZE];
	char	    *str;
	int		j;
	int	     n;
//	clock_t start_t, end_t, total_t;	
//	double k;

//	start_t = clock();
	n = 1;
	if (buffer[0] == '\0')
	{
		n = ft_read(fd, buffer);
		if (n == -1)
			return (NULL);
	}
	str = NULL;
	j = 1;
	while (n > 0)
	{
		n = ft_newline(buffer);
		if (n < 0)
		{
			str = ft_strjoin(str, buffer, j - 1, -1 * n);
			j += -1 * n;
		}
		if (n >= 0)
		{
			str = ft_strjoin(str, buffer, j - 1, n + 1);
			ft_save_buff(buffer, n + 1);	
			break ;
		}
		n = ft_read(fd, buffer);
	}
//	end_t = clock();
//	total_t = end_t - start_t;
//	k = (double) total_t / CLOCKS_PER_SEC;
//	printf("start: %ld; end: %ld; Time1 = %f\n",start_t, end_t, k);
	return (str);
}

int main()
{
	int fd;
	char *str;
	clock_t start_t, end_t, total_t;
	int i;

	fd = open("/home/marta/Documents/42/get_next_line/tentativa/gnlTester/files/big_line_no_nl", O_RDONLY);
	//fd = open("/home/marta/Documents/42/get_next_line/tentativa/teste", O_RDONLY);

	str = get_next_line(fd);
//	printf("%s", str);
	free(str);
	
	return (0);
}

