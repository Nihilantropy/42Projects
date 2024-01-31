#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// get_next_line_utils.c
size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t sz);
char	*ft_strdup(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t len);
char    *ft_extract_line(char **remaining);
// get_next_line.c
char    *get_next_line(int fd);

#endif
