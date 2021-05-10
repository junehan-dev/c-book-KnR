#ifndef _CHAR_ARR_H_
#define _CHAR_ARR_H_
#include <unistd.h>
#define BUFSIZ	4096
ssize_t			ft_readlines(char **dest, int fileno);
void			*strmap(const char *src, ssize_t (*callback)(void *src));
char			*ft_str_next_split(const char *src, int c);
#endif
