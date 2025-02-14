#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define FD_MAX 65535

char	*get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *string, int searchedChar);
char	*ft_strndup(const char *string, size_t n);

size_t	ft_strlen(const char *theString);

#endif