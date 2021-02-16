/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.6_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:20:28 by junehan           #+#    #+#             */
/*   Updated: 2021/02/16 18:42:14 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void    strrmove(char src[], char dest[], size_t len);

void    itoa(int n, char dest[])
{
    int     i, sign;
    char    buf[16];

    i = 0;
    sign = 0;

    if (!n)
    {
        dest[0] = '0';
        dest[1] = 0;
        return;
    }
    
    if (n < 0) {
        n =  1 + (~n);
        sign++;
    }

    do {
        buf[i++] = n % 10 + '0';
        n /= 10;
    } while (n > 0);

    if (sign)
        buf[i++] = '-';

    buf[i] = '\0';
    dest[i] = '\0';
    strrmove(buf, dest, (size_t)(i));
}

void    strrmove(char src[], char dest[], size_t len)
{

    size_t  i;
    size_t  mid;
    char    temp;

    i = 0;
    mid = len / 2;

    while (i <= mid) {
        temp = src[i];
        dest[i] = src[len - i - 1];
        dest[len - i - 1] = temp;
        i++;
    }
}

int     main(void)
{
    int i = -30;
    char ret[20] = {0};
    while (i < 30) {
        itoa(i++, ret);
        printf("%s\n", ret);
    }
    return (0);
}
