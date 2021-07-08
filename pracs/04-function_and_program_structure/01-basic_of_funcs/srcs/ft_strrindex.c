/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrindex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:09:13 by junehan           #+#    #+#             */
/*   Updated: 2021/07/08 15:03:36 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strrindex(const char *src, int target)
{
	int		i;
	int		ret_index;

	i = 0;
	ret_index = -1;
	while (*(src + i)) {
		ret_index = ((int)(*(src + i)) == target) ? i : ret_index;
		i++;
	}

	return (ret_index);
}

