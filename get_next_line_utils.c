#include "get_next_line.h"

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	destsize)
{
	size_t	i;

	i = 0;
	if (destsize == 0)
		return (ft_strlen(src));
	while (i + 1 < destsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char	*s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	if (!s1 || len == SIZE_MAX)
		return (NULL);
	str = malloc(sizeof (char) * (len + 1));
	if (str)
		ft_strlcpy(str, s1, len + 1);
	return (str);
}

char	*ft_strchr(const char	*s, int	c)
{
	int	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	if (s[0] == '\0')
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *) & s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	beforlen;
	size_t	buflen;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (ft_strdup(s2));
	beforlen = ft_strlen(s1);
	buflen = ft_strlen(s2);
	join = ft_calloc((beforlen + buflen + 1), sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (i < beforlen)
		join[i++] = s1[j++];
	j = 0;
	while (j < buflen && s2[j] != '\0')
	{
		join[j] = s2[j++];
	}
	return (join);
}
/*
char	*ft_strjoin(char const *beforsave, char const *buf)
{
	char	*join;
	size_t	beforlen;
	size_t	buflen;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (beforsave == NULL && buf == NULL)
		return (NULL);
	if (beforsave == NULL)
		return (ft_strdup(buf));
	if (buf == NULL)
		return (ft_strdup(beforsave));
	beforlen = ft_strlen(beforsave);
	buflen = ft_strlen(buf);
	join = ft_calloc((beforlen + buflen + 1), sizeof(char));
	if (!join)
		return (NULL);

	while (i < beforlen)
		join[i++] = beforsave[beforlen--];

	while (j < buflen)
		join[i++] = buf[j++];
//	ft_memcpy(join, s1, ft_strlen(s1));
//	ft_strlcat(join, s2, len + 1);
	return (join);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dst;
	s = src;
	i = 0;
	if (dst == src)
		return (d);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

size_t	ft_strlcat(char	*dst, const char	*src, size_t	destsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (destsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (destsize <= dst_len)
		return (destsize + src_len);
	i = 0;
	while (src[i] && (i < (destsize - dst_len - 1)))
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

void	*ft_memset(void	*b,	int	c, size_t	len)
{
	size_t			i;
	unsigned char	*ret;

	i = 0;
	ret = (unsigned char *)b;
	while (i < len)
	{
		ret[i] = (unsigned char)c;
		i++;
	}
	return (ret);
}
*/