#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_read
{
	char		*buffer;
	char		*temp;
	ssize_t		bytes;
}	t_read;

typedef struct s_string
{
	char		*result;
	size_t		i;
	size_t		j;
}	t_string;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);

#endif