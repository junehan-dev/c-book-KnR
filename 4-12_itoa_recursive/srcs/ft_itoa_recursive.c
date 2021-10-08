/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_recursive.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:40:17 by junehan           #+#    #+#             */
/*   Updated: 2021/10/01 17:53:44 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_itoa_recursive(int n, char *dest)
{
	size_t	offset;

	if (n < 0) {
		*dest = '-';
		n = -n;
		return (1 + ft_itoa_recursive(n, dest + 1));
	} 

	offset = (n / 10) ? ft_itoa_recursive(n / 10, dest) : 0;
	*(dest + offset) = n % 10 + '0';
	return (offset + 1);
}

int	main(void)
{
	char	src[32] = {0};
	int		n;
	size_t	len;

	n = 0; 
	len = ft_itoa_recursive(n, src);
	write(STDOUT_FILENO, src, len);
	write(STDOUT_FILENO, "\n", 1);

	n = -0; 
	len = ft_itoa_recursive(n, src);
	write(STDOUT_FILENO, src, len);
	write(STDOUT_FILENO, "\n", 1);

	n = -1; 
	len = ft_itoa_recursive(n, src);
	write(STDOUT_FILENO, src, len);
	write(STDOUT_FILENO, "\n", 1);

	n = 32; 
	len = ft_itoa_recursive(n, src);
	write(STDOUT_FILENO, src, len);
	write(STDOUT_FILENO, "\n", 1);

	n = -42080; 
	len = ft_itoa_recursive(n, src);
	write(STDOUT_FILENO, src, len);
	write(STDOUT_FILENO, "\n", 1);

	n = 104250; 
	len = ft_itoa_recursive(n, src);
	write(STDOUT_FILENO, src, len);
	write(STDOUT_FILENO, "\n", 1);

	return (0);
}
