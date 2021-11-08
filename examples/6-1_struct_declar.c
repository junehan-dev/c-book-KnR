#include <stdio.h>

int	main(void)
{
	struct pt {
		int x;
		int y;
		int *z;
	};

	struct pt mypt = { 20, 30, NULL };
	mypt.z = &(mypt.x);
	printf("x:%d y:%d, z: %d, size:%ld\n", mypt.x, mypt.y, *(mypt.z), sizeof(mypt));
	mypt.x = 10;
	printf("x:%d y:%d, z: %d, size:%ld\n", mypt.x, mypt.y, *(mypt.z), sizeof(mypt));
	return (0);
}
