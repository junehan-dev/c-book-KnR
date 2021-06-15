#include <unistd.h>
#include <stdio.h>

unsigned int ft_invert(unsigned int src, size_t offset, size_t len)
{
	unsigned int offset_start;
	unsigned int len_start;
	unsigned int ret;
	unsigned int len_mask;
	unsigned int inverted_range;

	if (!len || (offset + len) > 32)
		return (src);

	offset_start = 0;
	if (offset)
		offset_start = 1 << (32 - offset);

	len_start = 1 << (32 - offset - len);
	len_mask = (offset_start - 1 - len_start - 1);
	inverted_range = (~(src & len_mask)) & len_mask;
	
	ret = src & (~(offset_start - 1));
	ret += src & (len_start - 1);
	ret += inverted_range;

	return (ret);
}

#include <assert.h>
int main(void)
{
	int ret;
	ret = ft_invert(0, 1, 1);
	printf("ret:%d\n", ret);
	assert(ret == (1 << 31));
	
}
