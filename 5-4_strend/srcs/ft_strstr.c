/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:28:42 by junehan           #+#    #+#             */
/*   Updated: 2021/05/13 14:50:43 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	n_len;

	i = 0;
	while (*(haystack + i)) {
		if (*(haystack + i) == *needle) {
			n_len = 1;
			while (*(needle + n_len) == *(haystack + i + n_len) && *(needle + n_len))
				n_len++;

			if (*(needle + n_len) == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}

