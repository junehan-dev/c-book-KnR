/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_reverse_recursive.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 15:20:53 by junehan           #+#    #+#             */
/*   Updated: 2021/10/02 16:28:14 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <assert.h>

static char	*ft_str_reverse_recursive(const char *src)
{
	static char temp[1024];
	static char	*temp_pt = 0;

	if (*(src + 1) && *(src + 1) != '\n')
		*(ft_str_reverse_recursive(src + 1));
	else {
		temp_pt = temp;
		*temp_pt = *(src + 1);
	}

	assert(temp_pt != 0);
	*(temp_pt + 1) = *temp_pt;
	*temp_pt++ = *src;
	return (temp);
}

int	main(void)
{
	write(STDOUT_FILENO, ft_str_reverse_recursive("hello world!\n"), 13);
	write(STDOUT_FILENO, ft_str_reverse_recursive("my world!"), 9);
	return (0);
}

