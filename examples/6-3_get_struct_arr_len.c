#include <stdio.h>
int	main(void)
{
	struct point {
		int x;
		int y;
	} points[] = {
		{1, 2},
		{3, 4},
		{4, 5}
	};

	printf("size of point is :%ld and arr size is :%ld, so length is :%ld\n", sizeof(struct point), sizeof(points), sizeof(points)/sizeof(struct point));
}
