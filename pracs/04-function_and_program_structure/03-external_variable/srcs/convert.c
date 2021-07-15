
unsigned int	get_operlevel(char src)
{
	int ret;

	ret = (src == '-' || src == '+') ? 1 : 0;
	ret = (src == '*' || src == '/' || src == '%') ? 2 : ret;
	return (ret);
}

int			comp_oper(char dest, char src)
{
	unsigned int	dest_level;
	unsigned int	src_level;
	int	ret;

	dest_level = get_operlevel(dest);
	src_level = get_operlevel(src);
	ret = (dest_level > src_level) ? 1 : 0;
	ret = (dest_level < src_level) ? -1 : ret;
	return (ret);
}


