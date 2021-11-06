#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	single_test(const char *s1, const char *s2, size_t n)
{
	assert(ft_strncmp(s1, s2, n) ==	strncmp(s1, s2, n));
}

void	test_strncmp(void)
{
	int i;

	i = 0;
	while (i < 20)
		single_test("", "", i++);

	i = 0;
	while (i < 20)
		single_test("asdf", "asd ", i++);

	i = 0;
	while (i < 20)
		single_test("long enough lines for me to test", "long enough lines for me to testwo", i++);
}

int	main(void)
{
	test_strncmp();
	return (0);
}

