#include <ctype.h>

double	ft_atof(const char s[])
{
	double	val, power;
	int		i, sign;

	i = 0;
	while (isspace(s[i]))
		i++;

	sign = (s[i] == '-' && isdigit(s[++i])) ? -1 : 1;
	val = 0;
	while (isdigit(s[i])) {
		val *= 10;
		val += (s[i++] - '0');
	}

	power = (s[i++] == '.') ? 1 : 0;
	if (!power)
		return (val);

	while (isdigit(s[i])) {
		val *= 10;
		val += (s[i++] - '0');
		power *= 10;
	}

	return (sign * val / power);
}

#include <stdio.h>

int		main(int argc, const char *argv[])
{
	if (argc != 2)
		return (0);

	printf("%f", atof(argv[1]));
	return (0);
}
