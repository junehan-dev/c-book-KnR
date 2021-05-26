#include <assert.h>
#include <unistd.h>
#include <string.h>

char	*strcomment(const char *haystack, const char *needle);
char	*remove_comment(char *src);
int		main(int argc, const char *argv[])
{
	char	new[40] = {0};
	char 	origin[40] = "this is /* comment */ string /* yet */.";
	char	*found;
	size_t	len;
	size_t	last;
	size_t	i;

	len = strlen(origin);
	while ((found = commment_strcomment))
	found = comment(origin);
	assert(ret == (origin + strlen(origin)));
	write(STDOUT_FILENO, "RESULT: ", 8);
	last = 0;
	
	i = 0;
	while (i < len) {
		while (!origin[i] && i < len)
			i++;
		new[last++] = origin[i++];
	}
	write(STDOUT_FILENO, new, strlen(new));
	write(STDOUT_FILENO, "\n", 1);
}

char	*strcomment(const char *haystack, const char *needle)
{
	char	*src_pt;
	static char qute = 0;

	src_pt = (char *)haystack;
	while (*src_pt) {
		if (*src_pt++ == *needle && !qute) {
			if (*(src_pt) == *(needle + 1))
				return (src_pt - 1);
		} else if (*src_pt == '\\' && *(src_pt + 1) == '"'){
			src_pt += 2;
		} else if (*src_pt == '\\' && !*(src_pt + 1)) {
			return (-1);
		} else if (*src_pt++ == '"') {
			qute = ~qute;
		} else
			src_pt++;
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

