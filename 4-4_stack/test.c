#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ft_stack.h"

int		main(void)
{
	int MAXLEN = 6;
	int	**stack;

	stack = (int **)ft_stack_create(MAXLEN);
	/* created test */
	assert(*(stack + MAXLEN) == 0);
	assert(ft_stack_len((void **)stack) == 0);

	int	i;
	int	*num;
	int	is_push_error;

	i = 0;
	while (i < MAXLEN) {
		num = malloc(sizeof(int));
		*num = i + 42;
		/* push test */
		is_push_error = ft_stack_push((void **)(stack + i), (void *)num);
		assert(is_push_error == 0);
		assert(*(stack + i) == num);
		i++;
		/* len test */
		assert(ft_stack_len((void **)stack) == i);
	}
	/* swap test */
	assert(**(stack + 0) == 42);
	assert(**(stack + 1) == 43);
	assert(ft_stack_swap((void **)(stack + 0), (void **)(stack + 1)));
	assert(**(stack + 0) == 43);
	assert(**(stack + 1) == 42);

	/* negative swap test */
	assert(!ft_stack_swap((void **)(stack + 0), (void **)(stack + MAXLEN)));
	assert(**(stack + 0) == 43);
	assert(ft_stack_len((void **)stack) == i);
	assert(!*(stack + MAXLEN));
	ft_stack_stat((void **)stack, 4, '\n');

	/* copy test */
	int **copy;
	copy = (int **)ft_stack_create(ft_stack_len((void **)stack));
	assert((void **)copy == ft_stack_copy((char **)copy, (const char **)stack, sizeof(int)));
	ft_stack_stat((void **)copy, 4 , '\n');
	assert(ft_stack_len((void **)copy) == MAXLEN);
	i = 0;
	while (i < MAXLEN) {
		assert(**(copy + i) == **(stack + i));
		free(*(copy + i));
		i++;
	}
	free(copy);

	/* pop test */
	i--;
	num = ft_stack_pop((void **)stack);
	assert(*num == (i + 42));
	free(num);
	assert(*(stack + i + 1) == NULL);
	assert(*(stack + i) == NULL);
	assert(**(stack + (i - 1)) == ((i - 1) + 42));
	while (i--)
		free(*(stack + i));

	free(stack);
	return (0);
}
