#include <stdio.h>

int main(void)
{
    float   f;
    int     i;
    double  d;

    i = 567891;
    f = 12.34567;
    d = 12.34567891;
    
    printf("float: %f, int: %d\n", f, i);
    printf("float to int: %d, int: %f\n", (int)f, (float)i);
    printf("float: %f, double: %lf\n", f, d);
    printf("float to double: %lf, d to f: %f\n", (double)f, (float)d);
}
