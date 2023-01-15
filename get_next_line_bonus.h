#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdint.h>
# include <stddef.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char		*custody_line(char *tmp);
char		*output_line(const char *tmp);
char		*read_line(int fd, char *beforsave, ssize_t *ret);
char		*get_next_line(int fd);
size_t		ft_strlen(const char	*str);
char		*ft_strchr(const char	*s, int	c);
size_t		ft_strlcpy(char	*dst, const char	*src, size_t	destsize);
void		*ft_calloc(size_t	n, size_t	size);
char		*ft_strdup(const char	*s1);
char		*ft_strjoin(char const *s1, char const *s2);

#endif