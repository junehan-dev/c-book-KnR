/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:47:59 by junehan           #+#    #+#             */
/*   Updated: 2021/07/20 10:55:00 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "ft_calc.h"
#include <stdio.h>

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

size_t	parse_token(char *dest, size_t num_count)
{
	char	*dest_pt;
	size_t	i;
	size_t	y;
	size_t	len;
	char	*num;

	i = 0;
	while (!get_operator(i) && (i < (num_count - 1)))
		i++;

	if (i == (num_count - 1))
		return (0);

	
	y = i + 1;
	while (!get_operator(y))
		y++;
	i = ft_opercmp(get_operator(i), get_operator(y)) ? i : y; 
	dest_pt = dest;
	num = get_number(i);
	if (num) {
		len = get_intlen(num);
		memmove(dest_pt, num, len); 
		unset_number(i);
		dest_pt += len;
	}
	if ((i < (num_count - 1)) && (num = get_number(i + 1))) {
		len = get_intlen(num);
		memmove(dest_pt, num, len); 
		unset_number(i + 1);
		dest_pt += len;
	}
	*dest_pt++ = get_operator(i);
	unset_operator(i);
	*dest_pt = 0;
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
	size_t		len;

	dest_len = 0;
	while ((len = parse_token(dest + dest_len, (operator_count + 1))))
		dest_len += len;
	printf("fin: '%s'\n", dest);
	write(STDOUT_FILENO, "EXIT\n", 5);
	return (0);
}

