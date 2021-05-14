#ifndef _FT_CORE_
#define _FT_CORE_
#include <unistd.h>
#endif 
#ifndef _FT_STRING_H_
#define _FT_STRING_H_
#define	BUFSIZE	2048
char	*ft_strreplace(const char *s, const char *from, const char *to);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strndup(const char *s, size_t len);
#endif

