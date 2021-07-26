#ifndef __FT_STACK_H__
#define __FT_STACK_H__
void	**ft_stack_create(int len);
int		ft_stack_push(void **stack, void *data);
int		ft_stack_len(void **stack);
void	*ft_stack_pop(void **stack);
void	ft_stack_stat(void **stack, size_t bytesiz, char delimiter);
int		ft_stack_swap(void **s1, void **s2);
void	**ft_stack_copy(char **dest, const char **src, size_t n);
/*
*/
#endif
