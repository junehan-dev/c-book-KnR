int	ft_ishex(int c)
{
	const char hexvals = "0123456789abcdef";

	if (c >= '0' && c <= '9')
		return (c - '0');
	
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);

	return (-1);
}

int	ft_htoi(const char *src)
{
	
}
