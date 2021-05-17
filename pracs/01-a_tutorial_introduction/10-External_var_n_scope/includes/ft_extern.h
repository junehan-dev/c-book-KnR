#ifndef	_FT_EXTERN_H_
#define	_FT_EXTERN_H_
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#define MAXLINE 2048
char	line[MAXLINE];
int		copy(char *dest, const char *src);
int		get_line(void);
size_t	fstring(char *src, int v[]);
#endif
