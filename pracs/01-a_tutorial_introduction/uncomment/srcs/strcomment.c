#include <string.h>

const char	*strcomment(const char *haystack, const char *needle)
{
	const char	*src_pt;
	size_t		len;
	static char qute = 0;

	len = strlen(needle);
	src_pt = haystack;
	while (*src_pt) {
		if (qute) {
			while (*src_pt != '"' && *src_pt)
				src_pt++;

			if (*src_pt++ == '"')
				qute = 0;

		} else {
			while (*(src_pt) && (*src_pt != *needle) && (*src_pt != '"'))
				src_pt++;

			if (*src_pt == *needle) {
				if(!strncmp(src_pt, needle, len))
					return (src_pt);
				src_pt++;
			} else if (*src_pt == '"') {
				qute = 1;
				src_pt++;
			}
		}
	}
	return (NULL);
}
