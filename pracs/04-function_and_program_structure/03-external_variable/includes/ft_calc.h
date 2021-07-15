#ifndef __FT_CALC_H__
#define __FT_CALC_H__
// ft_token
int			ft_isspace(const char ch);
int			ft_iseol(const char ch);
int			ft_isoperator(const char ch);
int			ft_isdigit(const char *src);
int			ft_opercmp(char dest, char src);
const char	*ft_gettoken(const char *src);
// ft_atoi
int			ft_atoi(const char *src);
// ft_stack
size_t		add_operator(const char *operator);
size_t		add_number(const char *number);
char		*get_number(size_t index);
char		get_operator(size_t index);
#endif
