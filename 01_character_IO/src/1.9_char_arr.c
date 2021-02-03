#include <stdio.h>
#define MAXLINE 1000

int     get_line(char dest[], int lim);
void    copy(char dest[], char src[]);

int     main(void)
{
    int     cur_len;
    int     old_len;
    char    line[MAXLINE], longest[MAXLINE];

    old_len = 0;
    while ((cur_len = get_line(line, MAXLINE)) > 0) { // 1. get input
        if (cur_len > old_len) { // 2. if len is over limit?
            old_len = cur_len;
            copy(longest, line);
        }
    }

    if (old_len > 0)
        printf("%s\n", longest);

    return (0);
}


int     get_line(char dest[], int lim)
{
    int     c, i;

    i = 0;
    while ((i < lim) && ((c = getchar()) != EOF))
    {
        dest[i++] = c;
        if (c == '\n')
            break;
    }

    dest[i] = '\0';
    return (i);
}

void    copy(char dest[], char src[])
{
    int     i;

    i = -1;
    while (src[++i])
        dest[i] = src[i];
    return;
}
