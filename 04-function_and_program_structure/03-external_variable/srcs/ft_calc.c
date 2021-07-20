/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:47:59 by junehan           #+#    #+#             */
/*   Updated: 2021/07/20 12:33:55 by junehan          ###   ########.fr       */
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

ssize_t	set_tokens(const char *src)
{
	const char	*number;
	const char	*operator;
	const char	*src_pt;
	ssize_t		ret;

	ret = 0;
	number = ft_gettoken(src);
	add_number(number);
	src_pt = number + get_intlen(number);
	while ((operator = ft_gettoken(src_pt)) && !ft_iseol(*operator)) {
		number = ft_isoperator(*operator) ? ft_gettoken(operator + 1) : 0;
		if (!number)
			return (-1);

		add_operator(operator);
		add_number(number);
		src_pt = number + get_intlen(number);
		ret++;
	}
	
	return (ft_iseol(*operator) ? ret : -1);
}

size_t	store_num(char *dest, const char *num)
{
	size_t	intlen;
	size_t	i;

	intlen = get_intlen(num);
	i = intlen;
	while (i--)
		*(dest + i) = *(num + i);

	return (intlen);
}

size_t	parse_token(char *dest, size_t num_count)
{
	char	*dest_pt;
	size_t	i;
	size_t	y;
	char	*num;

	i = 0;
	while ((i < (num_count - 1)) && !get_operator(i))
		i++;

	y = i + 1;
	while (y < (num_count - 1) && !get_operator(y))
		y++;

	if (i == (num_count - 1))
		return (0);
	
	i = ft_opercmp(get_operator(i), get_operator(y)) ? i : y; 
	dest_pt = dest;
	dest_pt += (num = get_number(i)) ? store_num(dest_pt, num): 0;
	(num) ? unset_number(i) : 0;
	dest_pt += (num = get_number(i + 1)) ? store_num(dest_pt, num): 0;
	(num) ? unset_number(i + 1) : 0;
	*dest_pt++ = get_operator(i);
	unset_operator(i);

	return (dest_pt - dest);
}

int	ft_calc(const char *src)
{
	char		dest[1024];
	size_t		dest_len;
	size_t		len;
	ssize_t		operator_count;

	operator_count = set_tokens(src);
	if (operator_count < 1 || !ft_isdigit(src)) {
		write(STDOUT_FILENO, "MID VALUE ERROR\n", 16);
		return (1);
	} 

	dest_len = 0;
	while ((len = parse_token(dest + dest_len, (operator_count + 1))))
		dest_len += len;

	dest[dest_len++] = '\n';
	write(STDOUT_FILENO, dest, dest_len);

	return (0);
}

int		main(int argc, const char **argv)
{
	const char	*input;
	int			ret;

	input = (argc == 2) ? *(argv + 1) : 0;
	if (input)
		ret = ft_calc(input);
	else
		write(STDOUT_FILENO, "ERROR AT FIRST\n", 16);

	return (ret);
}

