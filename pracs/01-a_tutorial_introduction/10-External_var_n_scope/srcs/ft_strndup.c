/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihhan <junehan.dev@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 16:23:54 by jihhan            #+#    #+#             */
/*   Updated: 2020/09/04 16:23:55 by jihhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char    *ft_strndup(const char *s, size_t len)
{
    size_t  i;
    char    *pt;

    pt = malloc((len + 1) * sizeof(char));
    if (!pt)
        return (NULL);
    i = 0;
    while (i < len)
    {
        *(pt + i) = *(s + i);
        i++;
    }

    *(pt + i) = '\0';
    return (pt);
}
