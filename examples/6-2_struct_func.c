#include <stdio.h>
struct	point {
	int	x;
	int	y;
};
struct rect {
	struct point	pt1;
	struct point	pt2;
};
struct point makepoint(int x, int y);

int	main(void) {
	struct point pt;
	pt = makepoint(20, 30);
	printf("%d, %d\n", pt.x, pt.y);

	struct rect	display;
	display.pt1 = pt;
	display.pt2 = makepoint(40, 50);
	printf("1(%d, %d), 2(%d, %d)\n", display.pt1.x, display.pt1.y, display.pt2.x, display.pt2.y);
	return (0);
}

struct point makepoint(int x, int y)
{
	struct point ret;

	ret.x = x;
	ret.y = y;

	return (ret);
}
