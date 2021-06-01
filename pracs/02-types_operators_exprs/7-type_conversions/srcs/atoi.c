int	atoi(char s[])
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while ((s[i] - '0') >= 0 && (s[i] - '0') <= 9)
		n = 10 * n + (s[i++] - '0');

	return (n);
}
