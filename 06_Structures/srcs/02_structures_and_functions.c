#include <stdio.h>

#define XMAX 32
#define YMAX 64
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))

struct point {
	int				x;
	int				y;
};

struct rect {
	struct point	pt1;
	struct point	pt2;
};

struct point	makepoint(int x, int y)
{
	struct point	temp;

	temp.x	= x;
	temp.y	= y;

	return (temp);
}

struct point	addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;

	return (p1);
}

struct rect		canonrect(struct rect r)
{
	struct rect	temp;
	struct rect *temp_pt;

	temp_pt			= &temp;
	temp.pt1.x		= min(r.pt1.x, r.pt2.x);
	temp.pt1.x		= max(r.pt1.y, r.pt2.y);
	temp_pt->pt1.x	= min(r.pt1.x, r.pt2.x);
	temp_pt->pt2.x	= max(r.pt1.y, r.pt2.y);

	return (temp);
}

int	main(void)
{
	struct rect screen;
	struct rect *screen_pt;
	struct point mid;

	screen.pt1	= makepoint(0, 0);
	screen.pt2	= makepoint(XMAX, YMAX);
	mid			= makepoint((screen.pt1.x + screen.pt2.x) / 2,
							(screen.pt1.y + screen.pt2.y) / 2);
	screen_pt = &screen;
	printf("%d, %d\n", screen_pt->pt1.x, screen.pt2.x);
	
	return (0);
}
