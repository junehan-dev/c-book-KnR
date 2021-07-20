void ft_escape_convert(char *dest, const char *src)
{
	char		*dest_pt;
	const char	*src_pt;
	char		c;

	src_pt = src;	
	dest_pt = dest;
	while (*src_pt)
		switch (c = *src_pt++) {
			case '\t':
				*dest_pt++ = '\\';
				*dest_pt++ = 't';
				break;
			case '\n':
				*dest_pt++ = '\\';
				*dest_pt++ = 'n';
				break;
			default:
				*dest_pt++ = c;
				break;
		}
	*dest_pt = '\0';
}

#include <stdio.h>
int main(void)
{
	char dest[200];
	const char *src = "\\norigin	is	not	\n  this\0";
	ft_escape_convert(dest, src);

	printf("%s", dest);
	return (0);
}
