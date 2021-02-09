#include <ctype.h>

int     atoi(char s[])
{
    int     i, n, sign;

    sign = 1;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;

    if (s[i] == '+' || s[i] == '-')
        sign = (s[i++] == '-') ? -1 : 1;

    for (n = 0; isdigit(s[i]); i++)
        n = n * 10 + (s[i] - '0');

    return (sign * n);
}
