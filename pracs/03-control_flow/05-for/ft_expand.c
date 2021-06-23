/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:34:46 by junehan           #+#    #+#             */
/*   Updated: 2021/06/23 11:59:54 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ctype.h>

int		is_sametype(const char s1, const char s2)
{
	return ((isdigit(s1) && isdigit(s2)) || (isalpha(s1) && isalpha(s2)));
}


int		is_expandable(const char *src_pt, const char *src)
{
	return ((src_pt > src) && is_sametype(*(src_pt - 1), *(src_pt + 1)))
}


size_t	ft_expand(char *dest, const char *src)
{
	char 		start;
	char		end;
	const char	*src_pt;

	src_pt = src;
	while (*src_pt) {
		*dest = *src_pt++;
		if (*dest == '-' && *src_pt != '-' && is_exapndable(src_pt, src)) {
			start = *(dest - 1);
			end = *src_pt;
			while (start++ == end)
				*dest++ = start;
			dest = end;
		} // need function to get gap between 2 chars.
	}
}
