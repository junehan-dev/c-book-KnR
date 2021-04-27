#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef __FT_ADDITIONALS__H
# define __FT_ADDITIONALS__H
char        *ft_substr(char const *s, unsigned int start, size_t len);
char        *ft_strjoin(char const *s1, char const *s2);
char        *ft_strtrim(char const *s1, char const *set);
char        **ft_split(char const *s, char c);
char        *ft_itoa(int n);
char        *ft_ltox(long n);
char        *ft_itox(int n);
char        *ft_utoa(unsigned long n);
char        *ft_strmapi(char const *s, char (*f)(unsigned int, char));
char        ft_putchar_fd(char c, int fd);
char        ft_putstr_fd(char *s, int fd);
char        ft_putendl_fd(char *s, int fd);
char        ft_putnbr_fd(int n, int fd);
int         **ft_intmapi(int **arr, int (*f)(unsigned int, int));
void        *ft_realloc(void *ptr, size_t size);
#endif


