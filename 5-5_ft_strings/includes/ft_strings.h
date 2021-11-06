#ifndef _FT_STRINGS_H_
#define _FT_STRINGS_H_
#include <unistd.h>
char	*ft_strncat(char *restrict dest, const char *restrict src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *restrict dest, const char *restrict src, size_t n);
#endif
