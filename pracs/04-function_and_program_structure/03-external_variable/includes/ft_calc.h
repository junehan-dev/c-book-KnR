#ifndef __FT_CALC_H__
#define __FT_CALC_H__
int			ft_isspace(const char ch);
int			ft_iseol(const char ch);
int			ft_isoperator(const char ch);
int			ft_isdigit(const char *src);
const char	*ft_gettoken(const char *src);
int			ft_atoi(const char *src);
#endif
