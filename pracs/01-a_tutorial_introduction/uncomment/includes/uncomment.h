#ifndef _UNCOMMENT_H_
#define _UNCOMMENT_H_
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#define	MAXLEN	4096
const char	*strcomment(const char *haystack, const char *needle);
size_t		del_content(char *start, char *end);
#endif
