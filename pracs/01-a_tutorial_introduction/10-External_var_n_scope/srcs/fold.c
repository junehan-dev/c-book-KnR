#include <unistd.h>
#include <assert.h>
/*
 * Macros
 */
#define	is_blank(ch) ((ch == ' ' || ch == '\t') ? 1 : 0);
#define	is_column(ch) ((ch == '\n' || ch == '.') ? 1 : 0);
/*
 * Forward functions
 */
ssize_t next_column(const char *src);
ssize_t next_nonblank(const char *src);

int		main(void)
{
	return (0);
}

ssize_t next_nonblank(const char *src)
{
	ssize_t	i;

	i = 0;
	while (*(src + i)) {
		if (!is_blank(*(src + i)))
			return (i);
		i++;
	}

	return (-1);
}

ssize_t next_column(const char *src)
{
	ssize_t	i;

	i = 0;
	while (*(src + i))
		if (is_column(*(src + i++))) {
			while (is_column(*(src + i)))
				;
			return (i);
		}
	return (-1);
}



