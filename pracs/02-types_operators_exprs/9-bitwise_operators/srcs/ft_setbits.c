/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:14:52 by junehan           #+#    #+#             */
/*   Updated: 2021/06/15 16:39:22 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_setbits(unsigned int src, size_t offset, size_t len, int mask)
{
	unsigned int	ret;
	unsigned int	offset_end;
	unsigned int	mid_end;

	if (!len || (offset + len) > 32)
		return (src);

	offset_end = 0;
	if (offset)
		offset_end += 1 << (32 - offset);
	
	mid_end = 1 << (32 - offset - len);
	ret = src & ~(offset_end - 1);
	ret += src & (mid_end - 1);
	if (mask)
		ret += ~(mid_end - 1) - ~(offset_end - 1);

	return (ret);
}

