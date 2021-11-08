/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:17:55 by junehan           #+#    #+#             */
/*   Updated: 2021/11/06 15:22:58 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *restrict dest, const char *restrict src, size_t n)
{
	char *dest_pt;

	if (!n)
		return (dest);

	dest_pt = dest;
	while (n-- && (*dest_pt++ = *src++))
		;

	*dest_pt = (!n) ? '\0' : *dest_pt;
	return (dest);
}
