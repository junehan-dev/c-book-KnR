#include "uncomment.h"

//int		main(int argc, const char *argv[])
int		main(void)
{
	char 		origin[64] = "this is /* comment */ string /* yetdone */.\0";
	const char	*found;
	const char	*end;

	found = strcomment((const char*)origin, "/*");
	while (found) {
		end = strcomment(found, "*/");
		assert((end - found) == 11);
		write(STDOUT_FILENO, found, end - found + 2);
		write(STDOUT_FILENO, "\n", 1);
		found = strcomment(found + 1, "/*");
	}
	return(0);
}


