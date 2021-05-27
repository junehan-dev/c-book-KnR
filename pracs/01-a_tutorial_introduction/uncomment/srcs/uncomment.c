#include "uncomment.h"
#include <assert.h>
#include <string.h>

//int		main(int argc, const char *argv[])
int		main(void)
{
	char 		origin[64] = "this is \"/* comment */\" string /* yetdone */.\0";
	const char	*found;
	const char	*end;
	size_t		len;
	
	len = strlen(origin);
	found = strcomment((const char*)origin, "/*");
	while (found) {
		end = strcomment(found, "*/");
		assert((end - found) == 11);
		assert(del_content((char *)found, (char *)end + 2) == 13);
		write(STDOUT_FILENO, found, end - found + 2);
		write(STDOUT_FILENO, "\n", 1);
		found = strcomment(found + 1, "/*");
	}

	size_t	i;
	i = 0;
	while (i < len) {
		if (origin[i])
			write(STDOUT_FILENO, origin + i, 1);
		i++;
	}
	return(0);
}


