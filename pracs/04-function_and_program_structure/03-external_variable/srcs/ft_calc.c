/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:47:59 by junehan           #+#    #+#             */
/*   Updated: 2021/07/13 12:48:44 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_calc.h"

int		main(int argc, const char **argv)
{
	const char	*token_pt;
	
	
	token_pt = (argc == 2) ? ft_gettoken(*(argv + 1)) : (const char *)0;
	while (token_pt) {
		write(STDOUT_FILENO, "START\n", 6);
		write(STDOUT_FILENO, token_pt, 1);
		token_pt = ft_gettoken(token_pt + 1);
	}

	write(STDOUT_FILENO, "\nEXIT\n", 6);
	return (0);
}

