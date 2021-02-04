#include <stdio.h>
#define MAXLINE 1000

int     max;
char    line[MAXLINE];
char    longest[MAXLINE];

int     get_line(void);
void    copy(void);

int     main(void)
{
    int         len;
    extern int  max;
    extern char longest[];

    max = 0;
    while ((len = get_line()) > 0) {
        if (len > max) {
            max = len;
            copy();
        }
    }

    if (max > 0)
        printf("%s", longest);
    return (0);
}


int     get_line(void)
{
    int         c, i;
    extern char line[];

    i = 0;
    while (((c = getchar()) != EOF) && (i < MAXLINE - 1))
    {
        line[i++] = c;
        if (c == '\n')
            break;
    }

    line[i] = '\0';
    return (i);
}

void    copy(void)
{
    int         i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        i++;

    return;
}
