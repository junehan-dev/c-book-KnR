void	ft_strcat(char *dest, const char *src)
{
	if (!*src)
		return;
	
	while (*dest)
		dest++;

	while ((*dest = *src) && dest++ && src++)
		;
}
