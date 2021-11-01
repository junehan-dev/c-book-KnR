#define ALLOCSIZE	100
#include <stdio.h>
#include <assert.h>

static char	allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

/* return pointer to n characters */
char	*alloc(int n)
{
	allocp = (allocbuf + ALLOCSIZE - allocp >= n) ? allocp + n : allocp;
	return (allocp);
}

void	afree(char *p)
{
	allocp = (p >= allocbuf && p < (allocbuf + ALLOCSIZE)) ? p : allocp;
}

int		main(void)
{
	char		*pt;
	char		*old;
	char		c;
	int			i;

	i = 1;
	old = allocp;
	int max;

	max = 100;
	while (old != alloc(i)) {
		c = 'a';
		pt = old;
		while (pt < (allocp - 1))
			*pt++ = c++;
		max -= (allocp - old);
		*pt = '\0';
		pt++;
		assert(pt == allocp);
		printf("%d: %s\t", i, old);
		printf("left :%d\n", max);
		i++;
		old = allocp;
	}
	assert(100 - (allocp - allocbuf) == max);
	afree(old - 3);
	printf("end : %p, to change :%p\n", allocp, old - 3);
	assert(allocp == (old - 3));

	return (0);
}
