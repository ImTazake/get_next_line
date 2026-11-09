#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	t_string	data;

	if (!s1)
		s1 = "";
	data.result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!data.result)
		return (NULL);
	data.i = 0;
	while (s1[data.i])
	{
		data.result[data.i] = s1[data.i];
		data.i++;
	}
	data.j = 0;
	while (s2[data.j])
		data.result[data.i++] = s2[data.j++];
	data.result[data.i] = '\0';
	return (data.result);
}