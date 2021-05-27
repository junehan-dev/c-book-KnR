#include <assert.h>
#include <unistd.h>
#define MAXLEN	2048

char *itoa(char *dest, int v)
{
	char	buf[16];
	int		i;

	i = 0;
	if (!v)
		buf[i++] = '0';
	if (v < 0) {
		buf[16] = '-';
		v = ~v + 1;
	}
	while (v) {
		buf[i++] = v % 10 + '0';
		v /= 10;
	}
	if (buf[16] == '-') {
		buf[16] = 0;
		buf[i++] = '-';
	}
	buf[i] = '\0';
	dest += i;
	i = 0;
	while (buf[i])
		*(--dest) = buf[i++];

	return (dest + i);
}

size_t fstring(char *src, int v[])
{
	char	buf[MAXLEN];
	char	*buf_pt;
	char	*src_pt;
	size_t	ret;

	buf_pt = buf;
	src_pt = src;
	while ((*buf_pt = *src_pt++)) {
		if (*buf_pt == '%' && *src_pt == 'd') {
			buf_pt = itoa(buf_pt, *v++);
			src_pt++;
		} else
			buf_pt++;
	}

	ret = write(STDOUT_FILENO, buf, buf_pt - buf);
	assert(ret == (size_t)(buf_pt - buf));
	return (ret);
}

