/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:34:46 by junehan           #+#    #+#             */
/*   Updated: 2021/06/25 11:30:32 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ctype.h>

int		is_sametype(const char s1, const char s2)
{
	return ((isdigit(s1) && isdigit(s2)) ? 1 : 
		(islower(s1) && islower(s2)) || (isupper(s1) && isupper(s2)));
}

int		is_expandable(const char *src)
{
	char	start;
	char	end;

	return (
		is_sametype((start = *(src - 1)), (end = *(src + 1))) &&
		(start - end) != 0
	);
}

size_t	set_expand(char *dest, char start, char end)
{
	int		gap;
	size_t	i;

	gap = start < end ?	1 : -1;
	i = 0;
	while (start != end) {
		start += gap;
		*(dest + i) = start;
		i++;
	}

	return (i);
}

void	ft_expand(char *dest, const char *src)
{
	char 		start;
	char		end;
	const char	*src_pt;

	src_pt = src;
	while (*src_pt) {
		*dest = *src_pt++;
	/*
		dest += (
			*dest == '-' && src_pt > src && is_expandable(src_pt - 1)
		) ?	set_expand(dest, *(dest - 1), *src_pt++) : 1;
	}
	*/
		if (*dest == '-' && src_pt > src && is_expandable(src_pt - 1)) {
			start = *(dest - 1);
			end = *src_pt++;
			dest += set_expand(dest, start, end);
		} else {
			dest += 1;
		}
	}
	*dest = 0;
}

