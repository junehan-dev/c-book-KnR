#include <stdio.h>
#include <assert.h>

int	main(void)
{
	int	arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *arr_pt;

	arr_pt = &arr[0];

	printf("arr : %p\n", arr);
	printf("arr[0] : %d, arr[0] pt : %p\n", arr[0], arr + 0);
	printf("arr_pt val : %d, arr_pt : %p\n", *arr_pt, arr_pt);
	assert(arr_pt[1] == arr[1]);
	assert(*(arr_pt + 0) == arr[0]);
	assert((arr_pt + 0) == &arr[0]);

	arr_pt += 3;
	printf("arr_pt val : %d, arr_pt : %p\n", *arr_pt, arr_pt);
	assert(arr_pt[-3] == arr[0]);
	

	return (0);
}
