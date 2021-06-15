/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rightrot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:25:46 by junehan           #+#    #+#             */
/*   Updated: 2021/06/15 16:27:07 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_rightrot(int src, size_t cnt)
{
	unsigned int	r_shifted;
	int				mov_start;
	int				mov_mask;
	size_t			i;

	cnt %= (sizeof(int) * 8);
	if (!cnt)
		return (src);
	
	r_shifted = (unsigned int)src;
	i = 0;
	mov_mask = 1;
	while (i++ < cnt) {
		mov_mask <<= 1;
		r_shifted >>= 1;
	}

	mov_mask -= 1;
	mov_start = src & mov_mask;
	mov_start <<= (32 - cnt);
	return ((int)(r_shifted | mov_start));
}

