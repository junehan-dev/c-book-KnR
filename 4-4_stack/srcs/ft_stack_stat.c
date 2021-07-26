/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_stat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:33:16 by junehan           #+#    #+#             */
/*   Updated: 2021/07/26 10:58:53 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void		print_str(char *src)
{
	printf("%s\n", src);
}

void		print_int(int *src)
{
	printf("%d\n", *src);
}

void		print_long(long int *src)
{
	printf("%ld\n", *src);
}

void		ft_stack_stat(void **stack, size_t bytesiz)
{
	void		**stack_pt;

	stack_pt	= stack;
	while (*stack_pt) {
		(bytesiz == 1) ? print_str(*stack_pt) : 0;
		(bytesiz == 4) ? print_int(*stack_pt) : 0;
		(bytesiz == 8) ? print_long(*stack_pt) : 0;
		stack_pt++;
	}
}
