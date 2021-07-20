#include <stdio.h>

int main(void)
{
    short *short_pt;
    int *int_pt;
    float *float_pt;
    long *long_pt;
    double *double_pt;
    long long *longlong_pt;

    printf("short : %ld\n", sizeof(short));
    printf("int : %ld\n", sizeof(int));
    printf("float : %ld\n", sizeof(float));
    printf("long : %ld\n", sizeof(long));
    printf("double : %ld\n", sizeof(double));
    printf("long long: %ld\n", sizeof(long long));
    printf("shortpt : %ld\n", sizeof(short_pt));
    printf("int : %ld\n", sizeof(int_pt));
    printf("float : %ld\n", sizeof(float_pt));
    printf("long : %ld\n", sizeof(long_pt));
    printf("double : %ld\n", sizeof(double_pt));
    printf("ll : %ld\n", sizeof(longlong_pt));

}
