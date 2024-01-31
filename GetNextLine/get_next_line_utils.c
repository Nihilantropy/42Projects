#include "get_next_line.h"

char    *ft_extract_line(char **remaining)
{
    if (!*remaining || **remaining == '\0')
        return (NULL);
    char    *eol;
    size_t  line_len;
    char    *line;
    char    *new_remaining;

    eol = ft_strchr(*remaining, '\n');
    if (eol != NULL)
        line_len = eol - *remaining + 1;
    else
        line_len = ft_strlen(*remaining);
    if ((line_len + 1) == 0 || (line_len + 1) < line_len)
        return (NULL);
    line = (char *)malloc(line_len + 1);
    if (!line)
        return (NULL);
    ft_strlcpy(line, *remaining, line_len + 1);
    if (eol != NULL)
        new_remaining = ft_strdup(eol + 1);
    else
        new_remaining = NULL;
    free(*remaining);
    *remaining = new_remaining;
    return (line);
}

char *ft_strjoin(const char *s1, const char *s2) 
{
    if (!s1 && !s2)
        return (NULL);
	size_t i;
    size_t sz_join = ft_strlen(s1) + ft_strlen(s2) + 1;
    char *str_join = (char *)malloc(sz_join);
    if (!str_join)
        return (NULL);
	
	i = 0;
    if (s1)
        while (*s1) str_join[i++] = *s1++;
    if (s2)
        while (*s2) str_join[i++] = *s2++;
    str_join[i] = '\0';
    return (str_join);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

    if (!str)
	{
    	return (0);
	}
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return ((char *)str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == (const char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t sz)
{
	size_t	src_sz;
	size_t	i;

	src_sz = ft_strlen(src);
	i = 0;
	if (sz != 0)
	{
		while (src[i] && i < (sz -1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_sz);
}

char	*ft_strdup(const char *str)
{
	if (!str)
		return (NULL);
	size_t	dup_sz;
	char	*dup_str;

	dup_sz = ft_strlen(str) +1;
	dup_str = (char *)malloc(dup_sz);
	if (!dup_str)
		return (0);
	ft_memcpy(dup_str, str, dup_sz);
	return (dup_str);
}

void *ft_memcpy(void *dest, const void *src, size_t len)
{
    if (!dest || !src)
        return (NULL);

    unsigned char *d;
	const unsigned char *s;
	
	d = (unsigned char *)dest;
    s = (const unsigned char *)src;
    while (len--)
        *d++ = *s++;
    return (dest);
}