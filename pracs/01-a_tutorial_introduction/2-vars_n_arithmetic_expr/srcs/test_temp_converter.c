#include <assert.h>
#include <stdlib.h>
#include "dbg.h"
#include "temp_converter.h"
#define	MAXCASES 6

int	test_fahrtocel(void)
{
	int 	i;
	float	fahrs[MAXCASES] = {0.0, 20.0, 40.0, 60.0, 80.0, 100.0};
	float	cels[MAXCASES] = {-17.0, -6.0, 4.0, 15.0, 26.0, 37.0};

	i = 0;
	assert(!i);
	while (i < MAXCASES) {
		debug("fahr %f to cel :%f, expect %f", fahrs[i], fahrtocel(fahrs[i]), cels[i]);
		assert((fahrtocel(fahrs[i]) - cels[i] < 2));
		debug("cel %f to fahr :%f, expect %f\n", cels[i], celtofahr(cels[i]), fahrs[i]);
		assert((celtofahr(cels[i]) - fahrs[i]) < 2);
		i++;
	}
	return (i);
}

int main(void)
{
	int	ret_t_ftc;

	ret_t_ftc = test_fahrtocel();
	assert(ret_t_ftc == MAXCASES);
	debug("test passed for MAXCASE:%d ret:%d\n", MAXCASES, ret_t_ftc);
	return (EXIT_SUCCESS);
}
