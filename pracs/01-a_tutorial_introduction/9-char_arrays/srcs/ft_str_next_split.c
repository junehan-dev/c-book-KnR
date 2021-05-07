/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_next_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:19:11 by junehan           #+#    #+#             */
/*   Updated: 2021/05/07 17:43:26 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#define BUFSIZ	4096

char		*ft_str_next_split(const char *src, int c)
{
	static const char	*src_pt;
	char				*ret;

	if (!src || !c) {
		src_pt = NULL;
		return (NULL);
	}

	if (!src_pt)
		src_pt = src;

	ret = (char *)src_pt;

	while (*src_pt == c)
		src_pt++;

	while (*src_pt != c && *src_pt)
		src_pt++;

	ret = strndup(ret, (char *)src_pt - ret);
	return (ret);
}


ssize_t		ft_readlines(char **dest, int fileno)
{
	char		buf[BUFSIZ];
	char		*str;
	ssize_t		rb;
	ssize_t		ret;

	ret = 0;

	while ((rb = read(fileno, buf, BUFSIZ - 1)) == (BUFSIZ - 1)) {
		buf[BUFSIZ] = '\0';
		str = ft_str_next_split((const char *) buf, '\n');
		while (str != NULL) {
			*(dest + ret++) = str;
			str = ft_str_next_split((const char *) buf, '\n');
		}

		ft_str_next_split(NULL, 0);
	}

	buf[rb + 1] = '\0';
	str = ft_str_next_split((const char *) buf, '\n');
	while (str != NULL) {
		*(dest + ret++) = str;
		str = ft_str_next_split((const char *) buf, '\n');
	}

	ft_str_next_split(NULL, 0);
	return (ret);
}

