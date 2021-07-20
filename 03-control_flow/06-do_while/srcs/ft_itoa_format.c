/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:19:37 by junehan           #+#    #+#             */
/*   Updated: 2021/07/06 18:32:18 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <assert.h>

size_t	ft_itoa(int n, char *dest);
size_t	ft_itoa_format(int n, char *dest, size_t min_len);

int		main(int argc, const char *argv[])
{
	int 	n;
	size_t	min_len;
	size_t	len;
	char	buf[64];

	if (argc != 3)
		return (0);

	n = atoi(argv[1]);
	min_len = atoi(argv[2]);
	min_len = (min_len > 64) ? 64 : min_len;
	len = ft_itoa_format(n, buf, min_len) - 1; // NULL Remove
	assert((ssize_t)(len) == write(STDOUT_FILENO, buf, len));
	return (0);
}

size_t	ft_itoa_format(int n, char *dest, size_t min_len)
{
	size_t	len;
	int		temp;
	int		i;

	len = (n < 0) ? 1 : 0;
	temp = n;
	while ((temp /= 10))
		len++;

	i = 0;
	if ((len + 1) < min_len)
		while ((1 + len++) < min_len)
			*(dest + i++) = '0';

	*dest = (n < 0) ? '-' : *dest;
	len += (ft_itoa(n, dest + i));
	*(dest + i) = (n < 0 && i) ? '0' : *(dest + i);
	return (len + 1); // NULL ADD
}

