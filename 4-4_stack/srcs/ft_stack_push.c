/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 11:49:16 by junehan           #+#    #+#             */
/*   Updated: 2021/07/26 15:51:10 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_stack_push(void **stack, void *data)
{
	if (!data)
		return (-1);

	*stack = (!*(stack) && !*(stack + 1)) ? data : *stack;
	return ((*stack == data) ? 0 : 1);
}

