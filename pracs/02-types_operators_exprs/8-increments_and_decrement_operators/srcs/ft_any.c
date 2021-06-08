int	ft_any(const char *s1, const char *s2)
{
	const char	*s2_pt;
	int			i;

	i = 0;
	while (*(s1 + i)) {
		s2_pt = s2;

		while (*(s1 + i) != *s2_pt && *s2_pt)
			s2_pt++;

		if (*s2_pt)
			return (i);

		i++;
	}
	return (-1);
}

