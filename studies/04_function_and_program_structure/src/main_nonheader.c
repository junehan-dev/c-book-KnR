#include <stdio.h>
#define MAXLINE 100

int     main()
{
    double  sum;
    double  ft_atof(const char *);
    char    line[MAXLINE];
    int     get_line(char [], int);

    sum = 0;

    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", sum += ft_atof((const char *)line));

    return (0);
}
