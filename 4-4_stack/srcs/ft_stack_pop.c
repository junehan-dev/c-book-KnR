/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 13:29:51 by junehan           #+#    #+#             */
/*   Updated: 2021/07/23 13:31:57 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_stack_pop(void **stack)
{
	void	*ret;

	while (*(stack + 1))
		stack++;

	ret = (*stack) ? *stack : (void *)0;
	*stack = (void *)0;
	return (ret);
}
