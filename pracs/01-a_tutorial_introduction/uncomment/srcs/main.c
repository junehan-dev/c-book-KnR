#include <assert.h>
#include <unistd.h>
#include <string.h>

const char	*strcomment(const char *haystack, const char *needle);
int		main(int argc, const char *argv[])
{
	char		new[64] = {0};
	char 		origin[64] = "this is /* comment */ string /* yetdone */.\0";
	const char	*found;
	const char	*end;

	found = strcomment((const char*)origin, "/*");
	while (found) {
		end = strcomment(found, "*/");
		assert((end - found) == 11);
		write(STDOUT_FILENO, found, end - found + 2);
		write(STDOUT_FILENO, "\n", 1);
		found = strcomment(found + 1, "/*");
	}
	return(0);
}

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

			if (*src_pt == '"')
				qute = ~qute;

		} else {
			while (*(src_pt) && (*src_pt != *needle) && (*src_pt != '"'))
				src_pt++;

			if (*src_pt == *needle) {
				if(!strncmp(src_pt, needle, len))
					return (src_pt);
				src_pt++;
			} else if (*src_pt == '"') {
				qute = ~qute;
				src_pt++;
			}
		}
	}
	return (NULL);
}

size_t	del_content(char *start, char *end)
{
	size_t	ret;

	ret = 0;
	while ((start + ret) < end)
		*(start + ret++) = '\0';
	return (ret);
}

