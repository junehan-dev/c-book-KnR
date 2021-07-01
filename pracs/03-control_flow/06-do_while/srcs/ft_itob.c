/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:39:46 by junehan           #+#    #+#             */
/*   Updated: 2021/07/01 14:48:46 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	set_base(char *dest, int base)
{
	size_t		len;
	const char	keys[]	= "0123456789abcdef";
	char		key;

	key = (base < 0) ? keys[(~base)-1] : '\0';
	base = (base < 0) ? ~base : base;

/* //MORE
	len = ((key == '1') || (key == '7')) ? 32 : 8;
	len = (key == '7') ? 16 : len;
	
	*(dest + len) = '\0';

	ret = len;
	while (len--) {
		*(dest + len) = key;
	}
*/
	return (ret);
}

size_t	get_offset(int base)
{
	size_t	ret;

	ret		= 0;
	while ((base >>= 1))
		ret++;

	return (ret);
}

void	ft_itob(int n, char *dest, int base)
{
	size_t 		offset;
	size_t		len;

	offset = get_offset(base);
	if (offset) {
		len = (n < 0) ? set_base(dest, ~base) : set_base(dest, base);
		//MORE
	}
}
