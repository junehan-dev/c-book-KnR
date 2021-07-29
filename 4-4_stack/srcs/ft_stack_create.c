/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:21:00 by junehan           #+#    #+#             */
/*   Updated: 2021/07/23 11:19:17 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	**ft_stack_create(int len)
{
	void	**ret;

	ret = (len > 0) ? (void **)malloc(sizeof(void *) * (len + 1)) : (void **)0;
	if (ret)
		*(ret + len) = (void *)0;

	return (ret);
}

