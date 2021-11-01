#include <stdio.h>

int	strcmp(const char *s1, const char *s2)
{
	if (*s1 && *s1 == *s2)
		while (*++s1 == *++s2 && *s1)
			;

	return (*s1 - *s2);
}

int main(int argc, const char *argv[])
{
	int	ret;
	
	if (argc != 3)
		return (1);

	ret = strcmp(argv[1], argv[2]);
	!ret ?
		printf("equal\n") : ((ret > 0) ?
			printf("s1 bigger %d\n", ret) : printf("s2 bigger %d\n", ret)
		);

	return (0);
}
