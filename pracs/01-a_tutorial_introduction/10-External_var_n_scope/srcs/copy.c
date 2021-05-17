int		copy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while ((*(dest + i) = *(src + i)))
		i++;

	return (i);
}

