/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <jihhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 04:50:28 by jihhan            #+#    #+#             */
/*   Updated: 2020/06/23 18:48:06 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *ret;
    size_t  i1;
    size_t  i2;
    size_t  i;

    i1 = strlen(s1);
    i2 = strlen(s2);
    i = 0;
    ret = malloc((i1 + i2 + 1) * sizeof(char));
    if (!ret)
        return (NULL);
    while (i < i1)
    {
        *(ret + i) = *(s1 + i);
        i++;
    }
    i2 += i1;
    while (i < i2)
    {
        *(ret + i) = *(s2 + (i - i1));
        i++;
    }
    *(ret + i) = '\0';
    return (ret);
}
