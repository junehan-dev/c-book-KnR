/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:24:28 by junehan           #+#    #+#             */
/*   Updated: 2021/07/09 17:45:00 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int		ft_isdigit(int c);
int		ft_atoi(const char *src);

double	ft_atof(const char *src)
{
	int		int_v;
	double	float_v;
	int		i;
	double	pow;

	i = 0;
	float_v = 0.0;
	while (isblank(*(src + i)))
		i++;

	int_v = ft_atoi((src + i));
	i = ft_isdigit(*(src + i)) ? i : i + 1;
	while (ft_isdigit(*(src + i)))
		i++;

	pow = 0.1;
	if (*(src + i) == '.') {
		i += 1;
		float_v = (double)ft_atoi((src + i));
		while (isdigit(*(src + i))) {
			float_v *= pow;
			i++;
		}
	}

	float_v = (int_v < 0) ? float_v * -1 : float_v;
	float_v += int_v;
	if ((toupper(*(src + i + 1)) == 'E')) {
		int_v = ft_atoi((src + i + 2));
		pow = (*(src + i) == '-') ? pow : 1.0;
		while (int_v--)
				float_v *= pow;
	}

	return (float_v);
}


int	main(int argc, const char *argv[])
{
	if (argc != 2)
		return (0);
	printf("'%s' ->\n", argv[1]);
	printf("%lf\n", ft_atof(argv[1]));
	return (0);
}
