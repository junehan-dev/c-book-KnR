/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:14:35 by junehan           #+#    #+#             */
/*   Updated: 2021/02/17 15:12:45 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

double  ft_atof(const char *src)
{
    double  val;
    double  power;
    int     i;
    int     sign;

    i = 0;
    val = 0.0;
    power = 0.1;

    while (isspace(*(src + i)) || !isdigit(*(src + i)))
        i++;

    sign = ((*(src + i - 1)) == '-') ? -1 : 1;

    val += *(src + i++) - '0';
    while (isdigit(*(src + i))) {
        val *= 10;
        val += *(src + i) - '0';
        i++;
    }

    if (*(src + i++) == '.')
        while (isdigit(*(src + i))) {
            val += (*(src + i)  - '0') * power;
            power *= 0.1;
            i++;
        }

    return (val * sign);
}
