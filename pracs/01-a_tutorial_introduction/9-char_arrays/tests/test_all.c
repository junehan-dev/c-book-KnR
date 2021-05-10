#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "char_arr.h"

void	test_strmap(void);
void	test_get_next_line(void);
void	test_read_lines(void);

int		main(void)
{
	test_strmap();
	test_get_next_line();
	test_read_lines();
}

ssize_t	str_longerthan_10(void *src)
{
	char	*src_pt;
	int		ret;

	src_pt = (char *)src;
	ret = strlen(src_pt);
	if (ret < 10)
		ret = 0;

	return (ret);
}

void	test_read_lines(void)
{
	char	*dest[46];
	int		fd;
	ssize_t	rl;
	int		cl;

	assert(get_next_line(NULL) == NULL);
	fd = open("./README.rst", O_RDONLY);
	assert(fd != 0);
	rl = read_lines(dest, fd);
	close(fd);
	cl = 0;

	while (cl < rl) {
		printf("frees %d: %s\n", cl, dest[cl]);
		free(dest[cl]);
		//assert(dest[cl] == NULL);
		printf("freed %d: %s\n", cl, dest[cl]);
		cl++;
	}
}

void	test_strmap(void)
{
	assert(str_longerthan_10("1234567890") == 10);
	assert(str_longerthan_10("124567890") == 0);
	assert(strcmp(strmap("1234567890", str_longerthan_10), "1234567890") == 0);
	assert(strmap("123456789", str_longerthan_10) == NULL);
}


void	test_get_next_line(void)
{
	const char *src = "hello\nworld\0";
	const char *src_pt;

	src_pt = get_next_line(src);
	write(STDOUT_FILENO, src_pt, 5);
	assert(!strncmp(src, src_pt, 5));
	free((void *)src_pt);

	src_pt = get_next_line(src);
	write(STDOUT_FILENO, (src_pt), 5);
	assert(!strncmp(src + 6, src_pt, 5));
	free((void *)src_pt);

	src_pt = get_next_line(src);
	assert(src_pt == NULL);
	if (src_pt)
		free((void *)src_pt);

	assert(get_next_line(NULL) == NULL);
	src_pt = get_next_line(src);
	write(STDOUT_FILENO, src_pt, 5);
	assert(!strncmp(src, src_pt, 5));
	free((void *)src_pt);

	src_pt = get_next_line(src);
	write(STDOUT_FILENO, (src_pt), 5);
	assert(!strncmp(src + 6, src_pt, 5));
	free((void *)src_pt);

	src_pt = get_next_line(src);
	assert(src_pt == NULL);
	if (src_pt)
		free((void *)src_pt);
	assert(get_next_line(NULL) == NULL);
}

