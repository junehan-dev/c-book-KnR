#include "histogram.h"

ssize_t read_bytes(void)
{
	char	buf[MAXLEN];
	ssize_t	rb;

	rb = read(STDIN_FILENO, buf, MAXLEN);
	return (rb - 1);
}

int	main(void)
{
	int		occurences[MAXLEN] = {0};
	ssize_t	rb;
	int		i;
	char	*pt;

	while ((rb = read_bytes()) != 0)
		occurences[rb - 1] += 1;

	i = 0;
	while (i < MAXLEN) {
		write(STDOUT_FILENO, ": ",2);
		if (occurences[i++]) {
			pt = render_horizontal_bar(occurences[i - 1]);
			print_bar((const char *)pt, occurences[i - 1]);
			free(pt);
		} else
			write(STDOUT_FILENO, "\n", 1);
	}
	return (EXIT_SUCCESS);
}

