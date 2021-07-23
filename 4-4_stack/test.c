#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ft_stack.h"

int		main(void)
{
	int MAXLEN = 16;
	int	**stack;

	stack = (int **)ft_stack_create(MAXLEN);
	*(stack + MAXLEN) = 0;
	/* created test */
	assert(*(stack + MAXLEN) == 0);
	assert(*(stack + MAXLEN + 1));

	int	i;
	int	*num;
	int	is_push_error;

	i = 0;
	assert(i != MAXLEN);
	assert(!ft_stack_len((void **)stack));

	while (i < MAXLEN) {
		num = malloc(sizeof(int));
		*num = i + 42;
		printf("i is %d\n", i);
		/* push test */
		is_push_error = ft_stack_push((void**)(stack + i), (void *)num);

		assert(is_push_error == 0);
		assert(*(stack + i) == num);
		i++;

		/* len test */
		assert(ft_stack_len((void **)stack) == i);
	}

	assert(i == MAXLEN);
	assert(*(stack + i) == (void *)0);

	/* pop test */
	i--;
	num = ft_stack_pop((void **)stack);
	assert(*(stack + i) == NULL);
	assert(*num == (i + 42));
	free(num);

	while (i--)
		free(*(stack + i));

	free(stack);
	
	return 0;
}
