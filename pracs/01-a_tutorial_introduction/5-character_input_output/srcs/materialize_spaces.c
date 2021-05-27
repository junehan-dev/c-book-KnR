#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1024

ssize_t	get_str(char *buf)
{
	ssize_t		rb;

	rb = read(STDIN_FILENO, buf, MAXLEN);
	return (rb);
}

char	ft_isblank(int c)
{
	if (c != '\\' && c != '\t' && c != '\b')
		return (0);

	return (1);
}
	

char	*spaces_replace(char *src, ssize_t n)
{
	char	buf[n * 2 + 1];
	char	key;
	int		i;

	i = 0;
	while (i < n) {
		buf[i * 2] = '\\';
		if ((key = *(src + i)) == '\t') {
			buf[i * 2 + 1] = 't';
		} else if (key == '\b') {
			buf[i * 2 + 1] = 'b';
		} else {
			buf[i * 2 + 1] = '\\';
		}
		i++;
	}
	
	return (strdup(buf));
}

ssize_t split_replace(char **dest, const char *src)
{
	ssize_t	ret;
	int		last;
	int		i;

	ret = 0;
	i = 0;
	last = i;
	while (*(src + i)) {
		while (!ft_isblank(*(src + i)) && *(src + i))
			i++;

		*(dest + ret) = strndup((const char *)(src + last), i - last);
		ret++;
		last = i;
		if (*(src + i)) {
			while (ft_isblank(*(src + i)) && *(src + i))
				i++;

			*(dest + ret) = spaces_replace((char *)(src + last), i - last);
			last = i;
			ret++;
		}

		i++;
	}

	return (ret);
}

int		main(void)
{
	char	buf[MAXLEN];
	char	*splited[MAXLEN];
	ssize_t	i, len;

	i = 0;
	get_str(buf);
	len = split_replace(splited, (const char *)buf);
	while (i < len) {
		write(STDOUT_FILENO, splited[i], strlen(splited[i]));
		free(splited[i]);
		i++;
	}

	return (0);
}
