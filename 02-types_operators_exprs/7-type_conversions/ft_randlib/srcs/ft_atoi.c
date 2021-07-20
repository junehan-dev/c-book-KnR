int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');

	return (-1);
}

int		ft_atoi(const char *src)
{
	int	ret;
	int	i;
	int	v;

	ret = 0;
	i = 0;
	if (*src == '-' || *src ==  '+')
		i++;

	while ((v = ft_isdigit(*(src + i))) != -1) {
		ret *= 10;
		ret += v;
		i++;
	}
	if (*src == '-')
		ret = ~ret + 1;

	return (ret);
}
