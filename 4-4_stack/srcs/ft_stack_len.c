/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:15:59 by junehan           #+#    #+#             */
/*   Updated: 2021/07/23 12:22:10 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_stack_len(void **stack)
{
	void **stack_pt;

	stack_pt = stack;
	while (*stack_pt)
		stack_pt++;

	return (stack_pt - stack);
}
