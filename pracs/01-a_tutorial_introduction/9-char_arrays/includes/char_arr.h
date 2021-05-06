#ifndef _CHAR_ARR_H_
#define _CHAR_ARR_H_
#include <unistd.h>
typedef	ssize_t	(*callback) (void *src);
char			*get_next_line(const char *src);
ssize_t			read_lines(char **dest, int fileno);
void			*strmap(const char *src, callback cmp_func);
#endif
