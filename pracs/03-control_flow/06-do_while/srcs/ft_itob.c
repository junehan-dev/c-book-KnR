/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 12:39:46 by junehan           #+#    #+#             */
/*   Updated: 2021/07/07 10:18:37 by junehan          ###   ########.fr       */
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
	if (base <= 16 && !(base % 2) && !(base % 4) && !(base % 8))
		while ((base >>= 1))
			ret++;

	return (ret);
}

unsigned int	get_next_mask(unsigned int mask, size_t offset)
{
	unsigned int	start;
	unsigned int	ret;

	start = (mask | (mask >> 1)) - mask;
	ret = 0;
	if (start)
		while (offset--)
			ret += (start >> offset);

	return (ret);
}

int		ft_itob(int n, char *dest, int base)
{
	size_t 			offset;
	unsigned int	mask;
	unsigned int	value;
	size_t			lshifts;

	if ((offset = get_offset(base))) { 
		lshifts = (32 % offset) ? (32 - 32 % offset) : 32 - offset;
		mask = (base - 1) << lshifts;
		while (mask) {
			value = mask & n;
			while (value >> offset)
				value >>= offset;
			set_bits(dest++, value);
			mask = get_next_mask(mask, offset);
		}
		*dest = '\0';
		return (base);
	}

	return (0);
}

