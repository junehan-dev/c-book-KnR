/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:47:59 by junehan           #+#    #+#             */
/*   Updated: 2021/07/14 11:58:43 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include "ft_calc.h"

ssize_t	intlen(const char *src)
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
	size_t	ret;

	ret = 0;
	operator = 0;
	number = ft_gettoken(src);
	add_number(number);
	write(STDOUT_FILENO, number, intlen(number));
	src_pt = number + intlen(number);
	
	while ((operator = ft_gettoken(src_pt))) {
		assert(ft_isoperator(*operator));
		add_operator(operator);
		if (!ft_isoperator(*operator))
			return (0);

		write(STDOUT_FILENO, operator, 1);
		number = ft_gettoken(operator + 1);
		if (!ft_isdigit(number))
			return (0);

		write(STDOUT_FILENO, number, intlen(number));
		assert(ft_isdigit(number));
		add_number(number);
		src_pt = number + intlen(number);
		ret++;
	}

	if (operator)
		ret = 0;

	return (ret);
}

int		main(int argc, const char **argv)
{
	const char	*input;
	int			operator_count;

	input = (argc == 2) ? *(argv + 1) : 0;
	if (input) {
		operator_count = ft_isdigit(input) ? set_tokens(input): 0;
		if (operator_count < 1) {
			write(STDOUT_FILENO, "INPUT ERROR\n", 12);
			return (EXIT_FAILURE);
		}
	}
	int		i;
	char	oper;
	i = 0;
	write(STDOUT_FILENO, "operators: ", 11);
	while ((oper = get_operator(i++)))
		write(STDOUT_FILENO, &oper, 1);
	write(STDOUT_FILENO, "\nEXIT\n", 6);
	return (EXIT_SUCCESS);
}

