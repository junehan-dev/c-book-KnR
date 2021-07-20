#ifndef _HISTOGRAM_H_
#define _HISTOGRAM_H_
#include <unistd.h>
#include <stdlib.h>
#define MAXLEN 32
char	*render_horizontal_bar(int occurences);
int		print_bar(const char *src, ssize_t len);
#endif
