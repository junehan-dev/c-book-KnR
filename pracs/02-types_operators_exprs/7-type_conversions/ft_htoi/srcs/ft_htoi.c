/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:31:12 by junehan           #+#    #+#             */
/*   Updated: 2021/06/04 16:47:23 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tohex(int c)
{
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else if (c >= '0' && c <= '9')
		return (c - '0');
	else
		return (-1);
}

int	ft_htoi(const char *src)
{
	int	ret;
	int	i;
	int	v;

	ret = 0;
	i = 0;

	if (*src == '-' || *src ==  '+')
		i++;

	if (*(src + i) == '0' && *(src + i + 1) == 'x') 
		i += 2;

	while ((v = ft_tohex(*(src + i))) != -1) {
		ret *= 16;
		ret += v;
		i++;
	}

	if (*src == '-')
		ret = ~ret + 1;

	return (ret);
}
/*
#include <stdio.h>
int	main(int argc, const char *argv[])
{
	int	ret;

	if (argc == 2) {
		ret = ft_htoi(argv[1]);
		printf("Input:\t\t%s\n", argv[1]);
		printf("integer:\t%d\n", ret);
		printf("tohex:\t\t%x\n", ret);
		printf("-21 to hex = %x\n", -21);
		printf("33 to hex = %x\n", 33);
		return (0);	
	}

	return (0);
}
*/

