#ifndef __FT_BITS_H__
#define __FT_BITS_H__
#include <unistd.h>
unsigned int	ft_setbits(unsigned int src, size_t offset, size_t len, int mask);
unsigned int	ft_invert(unsigned int src, size_t offset, size_t len, size_t maxlen);
int				ft_rightrot(int src, size_t cnt);
#endif

