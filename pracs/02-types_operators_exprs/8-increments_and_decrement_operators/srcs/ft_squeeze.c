void	ft_squeeze(char *s1, const char *s2)
{
	int			i;
	char		*s1_pt;
	const char	*s2_pt;

	s1_pt	= s1;
	i 		= 0;

	while (*s1_pt) {
		s2_pt	= s2;

		while (*s1_pt != *s2_pt && *s2_pt)
			s2_pt++;

		if (!*s2_pt)
			*(s1 + i++) = *(s1_pt);
		s1_pt++;
	}
	*(s1 + i) = '\0';
}

