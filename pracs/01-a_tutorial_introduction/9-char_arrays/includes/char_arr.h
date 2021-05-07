#ifndef _CHAR_ARR_H_
#define _CHAR_ARR_H_
#include <unistd.h>
typedef	ssize_t	(*callback) (void *src);
ssize_t			ft_readlines(char **dest, int fileno);
void			*strmap(const char *src, callback cmp_func);
char			*ft_str_next_split(const char *src, int c);
#endif
