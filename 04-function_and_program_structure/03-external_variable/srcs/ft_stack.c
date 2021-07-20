#include <unistd.h>

static char	*_G_numbers[1024];
static char	_G_operators[1024];
int		unset_number(size_t index);

size_t	add_operator(const char *operator)
{
	static size_t	cur = 0;

	_G_operators[cur++] = *operator;
	_G_operators[cur] = 0;

	return (cur);
}

size_t	add_number(const char *number)
{
	static size_t	cur = 0;

	_G_numbers[cur++] = (char *)number;
	_G_numbers[cur] = (char *)0;

	return (cur);
}

char	*get_number(size_t index)
{
	char	*ret;

	ret = _G_numbers[index];
	return (ret);
}

char	get_operator(size_t index)
{
	return (_G_operators[index]);
}

char	unset_operator(size_t index)
{
	char	ret;

	ret = _G_operators[index];
	_G_operators[index] = 0;

	return (ret);
}

int		unset_number(size_t index)
{
	if (_G_numbers[index]) {
		_G_numbers[index] = (char *)0;
		return (1);
	}

	return (0);
}

