#include <stdio.h>
#define mysquare(x) x*x
#define max(A, B) ((A) > (B) ? (A) : (B))
#define dprint(expr)	printf(#expr " = %g\n", expr)
#define dprint_rev(expr)	printf("%g = " #expr "\n", expr)
#define paste(front, back)	front ## back
#define paste_two(front, back)	(#front #back)

int	main(void)
{ int i, j;

	i = 4;
	j = 5;
	printf("%d\n", max(i++, j++));
	printf("i: %d, j: %d\n", i, j);
	printf("%d\n", mysquare(j));
	printf("%d\n", mysquare(j+1));
	dprint(i / j);
	dprint_rev(i / j);
	const char *mystr1 = "HELLO";
	const char *mystr2 = "hello";
	printf("%s\n", paste(mystr, 1));
	printf("%s\n", paste(mystr, 2));
	printf("%s\n", paste_two(mystr, 2));
}
