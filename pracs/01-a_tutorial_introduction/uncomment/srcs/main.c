#include <assert.h>
#include <unistd.h>
#include <string.h>

char	*remove_comment(char *src);
int		main(int argc, const char *argv[])
{
	char 	origin[] = "this is /* comment */ string /* yet */.";
	size_t	len;
	size_t	last;
	size_t	i;

	len = strlen(origin);
	remove_comment(origin);
	last = 0;
	
	while (i < len) {
		while (!origin[i] && i < len)
			i++;
		origin[last++] = origin[i++];
	}
	write(STDOUT_FILENO, origin, strlen(origin));
}

ssize_t	comment_strstr(const char *haystack, const char *needle)
{
	char		*src_pt;
	static char qute = 0;

	src_pt = src;
	while (*src_pt) {
		if (*src_pt++ == *needle && !qute) {
			if (*(src_pt) == *(needle + 1))
				return (src_pt - src - 1);
		} else if (*src_pt == '\\' && *(src_pt + 1 == '"')){
			src_pt += 2;
		} else if (*src_pt++ == '"') {
			qute = ~qute;
		} else
			src_pt++;
	}
	return (-1);
}

size_t	del_content(char *start, char *end)
{
	size_t	ret;

	ret = 0;
	while ((start + ret) < end)
		*(start + ret++) = '\0';
	return (ret);
}

char	*remove_comment(char *src)
{
	static char		nend = 0;
	ssize_t			start;
	ssize_t			end;
	char			*ret;

	ret = src + strlen(src);
	if (!nend) {
		if ((start = comment_strstr((const char *)src, "/*")) != -1) {
			end = comment_strstr((const char *)src + start);
			if (end != -1) {
				end += 2;
				del_content(src + start, src + end);
				ret = start + end;
			} else
				ret = (src + start + del_content(src + start, src + start + strlen(src + start)));
				nend = 1;
		}
	} else {
		end = comment_strstr((const char *)src);
		if (end != -1) {
			ret = src + del_content(src, src + end);
		} else {
			ret = src + del_content(src, src + strlen(src));
			nend = 1;
		}
	}
	return (ret);
}
