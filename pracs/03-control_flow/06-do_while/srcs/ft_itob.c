/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:39:46 by junehan           #+#    #+#             */
/*   Updated: 2021/07/02 12:39:54 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int		ft_itob(int n, char *dest, int base);

int		main(int argc, const char *argv[])
{
	int		n;
	int		base;
	char	origin[33];
	int		ret;

	base = (argc == 2) ? 2 : 0;
	base = (argc == 3) ? atoi(argv[2]): base;
	n = (base) ? atoi(argv[1]) : 0;
	ret = (base && base == ft_itob(n, origin, base)) ? 0 : 1;
	if (!ret)
		printf("%d to %d is %s\n", n, base, origin);
	return (ret);
}

char	set_bits(char *dest, int value)
{
	const char	keys[]	= "0123456789abcdef";
	char		key;

	key = keys[value];
	*dest = key;
	return (key);
}

size_t	get_offset(int base)
{
	size_t	ret;

	ret	= 0;
	if (base <= 16)
		while ((base >>= 1))
			ret++;

	return (ret);
}

int		ft_itob(int n, char *dest, int base)
{
	size_t 			len;
	unsigned int	mask;
	unsigned int	value;
	
	len	= get_offset(base); // 1,2,3,4
	if (len) {
		mask = (base - 1) << (32 - len);
		while (mask) {
			value = mask & n;
			if (value)
				while (value >> len)
					value >>= len;
			set_bits(dest++, value);
			mask >>= len;
		}
		*dest = '\0';
		return (base);
	}
	return (0);
}

