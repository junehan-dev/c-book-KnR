/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:11:38 by junehan           #+#    #+#             */
/*   Updated: 2021/05/10 17:57:26 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

ssize_t	ft_str_reverse(char *dest, const char *src)
{
	ssize_t		start;
	ssize_t		end;

	end = 0;
	start = 0;
	if (*src) {
		while (*(src + end))
			end++;

		*(dest + end--) = '\0';
		while (end >= start) {
			*(dest + end) = *(src + start);
			*(dest + start++) = *(src + end--);
		}
	}
	return (start + end + 1);
}

