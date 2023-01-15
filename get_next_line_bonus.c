#include "get_next_line_bonus.h"

void	*ft_calloc(size_t	n, size_t	size)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (n && size > SIZE_MAX / n)
		return (NULL);
	len = size * n;
	if (len == 0)
		len = 1;
	str = malloc(len);
	i = 0;
	if (str)
	{
		while (i < len)
			str[i++] = 0;
	}
	return (str);
}

char	*storage_line(char *tmp)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!ft_strchr(tmp, '\n'))
	{
		free(tmp);
		return (NULL);
	}
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	str = ft_strdup(tmp + i + 1);
	if (tmp[i] == '\0')
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (str);
}

char	*output_line(const char *tmp)
{
	char	*str;
	ssize_t	size_str;
	ssize_t	i;

	size_str = 0;
	if (tmp[0] == '\0')
		return (NULL);
	if (!ft_strchr(tmp, '\n'))
		return (ft_strdup(tmp));
	while (tmp[size_str] != '\n')
		size_str++;
	str = (char *)malloc(sizeof(char) * (size_str + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (i <= size_str)
	{
		str[i] = tmp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*read_line(int fd, char *beforsave, ssize_t *ret)
{
	char	*buf;
	char	*save;

	buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buf)
	{
		free(beforsave);
		return (NULL);
	}
	*ret = read(fd, buf, BUFFER_SIZE);
	if (*ret == -1)
	{
		free(beforsave);
		free(buf);
		return (NULL);
	}
	buf[*ret] = '\0';
	save = ft_strjoin(beforsave, buf);
	free(beforsave);
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*next;
	static char	*tmp[1024];
	ssize_t		ret;

	ret = 0;
	if (fd < 0 || BUFFER_SIZE > INT_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	tmp[fd] = read_line(fd, tmp[fd], &ret);
	if (!tmp[fd])
		return (NULL);
	while ((!ft_strchr(tmp[fd], '\n')))
	{
		tmp[fd] = read_line(fd, tmp[fd], &ret);
		if (tmp[fd] == NULL)
			return (NULL);
		if (ret == 0)
			break ;
	}
	next = output_line(tmp[fd]);
	tmp[fd] = storage_line(tmp[fd]);
	return (next);
}
