#include <stdio.h>
#include <stdlib.h>
void	shellsort(int v[], int n);
void	shellsort_while(int v[], int n);
/* sort stack based array into increasing order */

int		main(void)
{
	int i, n;
	int	v[] = {5, 6, 2, 4, 1};
	n = 5;

	i = 0;
	while (i < n)
	{
		printf("v[%d] : %d\n", i, *(v+i));
		i++;
	}
	shellsort_while(v, n);
	i = 0;
	while (i < n)
	{
		printf("v[%d] : %d\n", i, *(v+i));
		i++;
	}
	return (EXIT_SUCCESS);
}

void    shellsort(int v[], int n)
{
    int gap;
    int i, j;
    int temp;

    for (gap = (n / 2); gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = (i - gap); ((j >= 0) &&
                    (v[j] > v[j+gap])); j-=gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
                j = j - gap;
            }
}


void    shellsort_while(int v[], int n)
{
    int gap;
    int i;
    int j;
    int temp;

    gap = n / 2;

    while (gap > 0) { // n is mid of v
        i = gap;
        while (i < n) { // i gap to n
            j = i - gap;
            while (j >= 0) {
				if (v[j] > v[j + gap])
					break;
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
                j = j - gap;
            }
            i++;
        }
        gap /= 2;
    }
}

