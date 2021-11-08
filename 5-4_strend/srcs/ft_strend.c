/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:39:23 by junehan           #+#    #+#             */
/*   Updated: 2021/11/02 16:32:33 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_strstr(const char *haystack, const char *needle);
int     		ft_strcmp(const char *s1, const char *s2);
unsigned char	ft_strend(const char *dest, const char *src)
{
	const char	*dest_pt;

	if (!*src)
		return (1);

	dest_pt = dest;
	while ((dest_pt = ft_strstr(dest_pt, src)) && *dest_pt) {
		if (ft_strcmp(dest_pt, src) == 0)
			return (1);
		dest_pt++;
	}

	return (0);
}

