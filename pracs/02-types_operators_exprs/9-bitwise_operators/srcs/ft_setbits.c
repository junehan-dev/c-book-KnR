/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:14:52 by junehan           #+#    #+#             */
/*   Updated: 2021/06/14 16:27:34 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_setbits(unsigned int src, size_t offset, size_t len, int mask)
{
	unsigned int	ret;
	unsigned int	offset_start;
	unsigned int	len_start;

	if (!len || (offset + len) > 32)
		return (src);

	offset_start = 1 << (32 - offset);
	len_start = 1 << (32 - offset - len);
	ret = 0;
	ret += src & ~(offset_start - 1);
	ret += src & (len_start - 1);
	if (mask)
		ret += (offset_start - 1 - len_start - 1);

	return (ret);
}

