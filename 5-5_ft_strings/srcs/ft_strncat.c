/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:10:33 by junehan           #+#    #+#             */
/*   Updated: 2021/11/06 14:40:38 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *restrict dest, const char *restrict src, size_t n)
{
	char	*dest_pt;

	if (!n || !*src)
		return (dest);

	dest_pt = dest;
	if (*(dest_pt = dest))
		while (*++dest_pt)
			;
	while (n-- && (*dest_pt++ = *src++))
		;

	return (dest);
}
