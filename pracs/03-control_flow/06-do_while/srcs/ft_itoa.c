/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:46:52 by junehan           #+#    #+#             */
/*   Updated: 2021/07/06 17:42:23 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t ft_itoa(int n, char *dest)
{
	char	ret[32];
	int		i;
	int		sign;

	i = 31;
	ret[i--] = '\0';
	sign = (n < 0) ? -1 : 1;
	if (n)
		while (n) {
			ret[i--] = (n * sign % 10 + '0');
			n /= 10;
		}
	else
		ret[i--] = '0';
	
	ret[i] = (sign < 0) ? '-' : '\0';
	i = (sign > 0) ? (i + 1) : i;
	while (ret[i])
		*dest++ = ret[i++];

	*dest = '\0';
	return (32 - i);
}

