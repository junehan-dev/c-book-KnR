/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_stat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:33:16 by junehan           #+#    #+#             */
/*   Updated: 2021/07/26 11:56:24 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void		print_str(char **src, char delimiter)
{
	while (*src)
		printf("%s%c", *src++, delimiter);
}

void		print_int(int **src, char delimiter)
{
	while (*src)
		printf("%d%c", **src++, delimiter);
}

void		print_long(long int **src, char delimiter)
{
	while (*src)
		printf("%ld%c", **src++, delimiter);
}

void		ft_stack_stat(void **stack, size_t bytesiz, char delimiter)
{
	void		**stack_pt;

	stack_pt	= stack;
	(bytesiz == 1) ? print_str((char **)stack_pt, delimiter) : 0;
	(bytesiz == 4) ? print_int((int **)stack_pt, delimiter) : 0;
	(bytesiz == 8) ? print_long((long int **)stack_pt, delimiter) : 0;
}
