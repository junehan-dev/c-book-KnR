int	ft_ishex(int c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);

	return (-1);
}

int	ft_htoi(const char *src)
{
	int	ret;
	int	i;
	int	v;

	ret = 0;
	i = 0;
	if (*src == '-' || *src ==  '+')
		i++;

	while ((v = ft_ishex(*(src + i))) != -1) {
		ret *= 16;
		ret += v;
		i++;
	}
	if (*src == '-')
		ret = ~ret + 1;

	return (ret);
}

#include <stdio.h>
int	main(int argc, const char *argv[])
{
	int	ret;

	if (argc == 2) {
		ret = ft_htoi(argv[1]);
		printf("Input:\t%s\n", argv[1]);
		printf("integer:\t%d\n", ret);
		printf("tohex:\t%x\n", ret);
		return (0);	
	}

	return (0);
}
