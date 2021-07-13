/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junehan <junehan.dev@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:20:45 by junehan           #+#    #+#             */
/*   Updated: 2021/07/13 13:27:20 by junehan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isspace(const char ch)
{
	return  (ch == ' ' || ch == '\t');
}

int			ft_iseol(const char ch)
{
	return (ch == '\n' || ch == 0 || ch == -1);
}

int			ft_isoperator(const char ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int			ft_isdigit(const char *src)
{
	const char *src_pt;

	src_pt = (*src == '-') ? src + 1 : src;
	if (*src_pt > '0' && *src_pt <= '9')
		return (1);

	return (0);
}

const char	*ft_gettoken(const char *src)
{
	const char	*src_pt;
	static char need_oper = 0;
	const char	*ret;

	src_pt = src;
	ret = (const char *)0;
	while (ft_isspace(*src_pt))
		src_pt++;

	if (ft_iseol(*src_pt) && !need_oper)
		return (src_pt);

	ret = (!need_oper && ft_isdigit(src_pt)) ? src_pt : ret;
	ret = (need_oper && ft_isoperator(*src_pt)) ? src_pt : ret;
	need_oper = (ret) ? !need_oper : 0;
	return (ret);
}

