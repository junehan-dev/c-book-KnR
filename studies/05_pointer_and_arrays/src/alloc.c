#define ALLOCSIZ 10000

static char	allocbuf[ALLOCSIZ];
static char	*allocp = allocbuf;	

char	*alloc(int n)
{
	if (allocbuf + ALLOCSIZ - allocp >= n) { /* affordable */
		allocp += n;
		return (allocp - n);
	} else
		return (0);
}

void	afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZ)
		allocp = p;
}

