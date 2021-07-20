/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:02:51 by junehan           #+#    #+#             */
/*   Updated: 2021/06/16 12:02:54 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_bitcount(int src)
{
	size_t			ret;
	unsigned int	v;

	ret = 0;
	v = (unsigned int)(src);
	while (v) {
		v &= (v - 1);
		ret++;
	}

	return (ret);
}

