/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:44:16 by junehan           #+#    #+#             */
/*   Updated: 2021/02/24 10:55:08 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

size_t      ft_expand(const char *src, char *dest);
int         is_expandable(char prev, char next);

int         main(void)
{
    const char *src = "-a-b-a\n";
    char *dest;
    size_t ret;

    dest = malloc(sizeof(char) * 30);
    ret = ft_expand(src, dest);
    write(STDOUT_FILENO, src, strlen(src));
    write(STDOUT_FILENO, dest, ret);
    free(dest);
    return (EXIT_SUCCESS);
}

size_t      ft_expand(const char *src, char *dest)
{
    size_t src_i;
    size_t dest_i;
    size_t len;
    char   prev, next;
    
    if (!(*src))
        return (0);

    src_i = 1;
    dest_i = 1;
    *dest = *src;
    while (*(src + src_i) != '\0') {
        if (*(src + src_i) == '-') {
            prev = *(src + src_i - 1);
            next = *(src + src_i + 1);
            if (next >= prev) {
                if ((len = is_expandable(prev, next)) > 0) {
                    while (len)
                    {
                        *(dest + dest_i + len - 1) = prev + len;
                        len--;
                    }
                    dest_i += (next - prev - 1);
                    src_i++;
                } else if (len == 0) {
                    src_i++;
                    continue;
                }
            } else {
                *(dest + dest_i) = *(src + src_i);
            }
        } else {
            *(dest + dest_i) = *(src + src_i);
        }
        dest_i++;
        src_i++;
    }
    *(dest + dest_i) = '\0';

    return (dest_i);
}

int     is_expandable(char prev, char next)
{
    int ret;
    
    ret = -1;

    if (prev == next)
        return (0);
    if (isalpha(prev)) {
        if (isalpha(next)) {
            if (islower(prev) && islower(next))
                ret = next - prev;
            else if (isupper(prev) && isupper(next))
                ret = next - prev;
        }
    } else if (isdigit(prev)) {
        if (isdigit(next))
            ret = next - prev;
    }

    return (ret);
}
