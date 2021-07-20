/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:40:00 by junehan           #+#    #+#             */
/*   Updated: 2021/07/12 14:47:46 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

int		ft_atoi(const char *src)
{
	int	ret;
	int	i;

	ret = 0;
	i = (*src == '-' || *src ==  '+') ? 1 : 0;
	while (ft_isdigit(*(src + i))) {
		ret *= 10;
		ret += *(src + i++) - '0';
	}

	return ((*src == '-') ? ~ret + 1 : ret);
}
