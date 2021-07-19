/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:47:59 by junehan           #+#    #+#             */
/*   Updated: 2021/07/19 14:19:25 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_calc.h"

ssize_t	get_intlen(const char *src)
{
	size_t ret;

	ret = 0;
	if (ft_isdigit(src)) {
		ret = (*src == '-' || *src == '+') ? 1 : 0;
		while (*(src + ret) >= '0' && *(src + ret) <= '9')
			ret++;
	}

	return (ret);
}

size_t	set_tokens(const char *src)
{
	const char	*number;
	const char	*operator;
	const char	*src_pt;
	size_t		ret;

	ret = 0;
	number = ft_gettoken(src);
	add_number(number);
	src_pt = number + get_intlen(number);

	while ((operator = ft_gettoken(src_pt))) {
		number = ft_gettoken(operator + 1);
		if (!ft_isoperator(*operator) || !ft_isdigit(number))
			return (0);

		add_operator(operator);
		add_number(number);
		src_pt = number + get_intlen(number);
		ret++;
	}

	return (ret);
}

#include <string.h>
#include <stdio.h>
size_t	parse_token(char *dest, size_t num_count)
{
	size_t	oper_count;
	char	*dest_pt;
	int		i;
	size_t	intlen;
	char	*num;

	oper_count = (num_count) ? num_count - 1 : 0;
	printf("operators : %lu\n", oper_count);
	dest_pt = dest;
	// first 2 count must be..
	
	i = 0;
	i = ft_opercmp(get_operator(i), get_operator(i + 1)) ? i : i + 1; 

	num = get_number(i);
	intlen = get_intlen(num);
	memmove(dest_pt, num, intlen);
	dest_pt += intlen;


	num = get_number(i + 1);
	intlen = get_intlen(num);
	memmove(dest_pt, num, intlen);
	dest_pt += intlen;
	*dest_pt++ = get_operator(i);
	*dest_pt = '\0';
	/*
	while (i < oper_count) {
		while (oper = get_operator(i))
			i++;
		next_oper = (i < oper_count - 1) ? get_operator(i + 1) : '\0';
		i = (ft_opercmp(oper, next_oper)) ? i : i + 1;
		oper = get_operator(i);
		push(dest_pt, get_number(i+1), oper);
	}
	*/
	write(STDOUT_FILENO, "parsed_token!\n", 13);
	return (dest_pt - dest);
}

int		main(int argc, const char **argv)
{
	const char	*input;
	size_t		operator_count;

	input = (argc == 2) ? *(argv + 1) : 0;
	if (input) {
		operator_count = ft_isdigit(input) ? set_tokens(input): 0;
		if (operator_count < 1) {
			write(STDOUT_FILENO, "INPUT ERROR\n", 12);
			return (1);
		}
	}
	
	int		i;
	char	*digit;

	i = 0;
	write(STDOUT_FILENO, "numbers: ", 8);
	while ((digit = get_number(i++))) {
		write(STDOUT_FILENO, digit, get_intlen(digit));
		write(STDOUT_FILENO, " ", 1);
	}
	write(STDOUT_FILENO, "\n", 1);

	char	oper;

	write(STDOUT_FILENO, "operators: ", 11);
	i = 0;
	while ((oper = get_operator(i++)))
		write(STDOUT_FILENO, &oper, 1);
	write(STDOUT_FILENO, "\n", 1);

	char		dest[1024];
	size_t		dest_len;

	dest_len = parse_token(dest, (operator_count + 1)) ? : 0;
	dest[dest_len] = '\0';
	write(STDOUT_FILENO, dest, dest_len);
	write(STDOUT_FILENO, "EXIT\n", 5);
	return (0);
}

