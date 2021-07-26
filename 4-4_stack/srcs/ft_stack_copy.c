/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:18:24 by junehan           #+#    #+#             */
/*   Updated: 2021/07/26 15:43:14 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	**ft_stack_copy(char **dest, const char **src, size_t n)
{
	int		i;
	int		len;
	size_t	c;

	i = 0;
	len = 0;

	while (*(src + len)) {
		if (*(dest + len))
			return ((void **)0);
		len++;
	}

	if (*(dest + len))
			return ((void **)0);

	while (i < len) {
		*(dest + i) = malloc(n);
		if (!*(dest + i)) {
			while (i--)
				free(*(dest + i));

			return ((void **)0);
		}

		c = 0;
		while (c < n) {
			*(*(dest + i) + c) =  *(*(src + i) + c);
			c++;
		}

		i++;
	}

	return ((void **)dest);
}

