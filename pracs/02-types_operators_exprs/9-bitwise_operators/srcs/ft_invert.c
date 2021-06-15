/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:09:51 by junehan           #+#    #+#             */
/*   Updated: 2021/06/15 12:13:49 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int ft_invert(unsigned int src, size_t offset, size_t len, size_t maxlen)
{
	unsigned int left_end;
	unsigned int mid_end;
	unsigned int ret;
	unsigned int mid_mask;
	unsigned int mid_inverted;

	if (!len || (offset + len) > maxlen)
		return (src);

	left_end = 0;
	if (offset)
		left_end = 1 << (maxlen - offset);
	mid_end = 1 << (maxlen - offset - len);
	mid_mask = ~(mid_end - 1) - ~(left_end - 1);
	mid_inverted = mid_mask & (~(src & mid_mask));

	ret = src & (~mid_mask);
	ret += mid_inverted;
	return (ret);
}

