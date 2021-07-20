int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
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

	while (ft_isdigit(*(src + i))) {
		v = *(src + i) - '0';
		ret *= 10;
		ret += v;
		i++;
	}
	if (*src == '-')
		ret = ~ret + 1;

	return (ret);
}
