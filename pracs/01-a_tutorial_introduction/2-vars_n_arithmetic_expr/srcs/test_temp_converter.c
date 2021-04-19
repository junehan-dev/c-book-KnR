#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "dbg.h"
#include "temp_converter.h"
#define	MAXCASES 6

int	test_fahrtocel(void)
{
	int 	i;
	float	fahrs[MAXCASES] = {1.4f, 21.2f, 39.2f, 59.0f, 78.8f, 98.6f};
	float	cels[MAXCASES] = {-17.0f, -6.0f, 4.0f, 15.0f, 26.0f, 37.0f};

	i = 0;
	assert(!i);
	while (i < MAXCASES) {
		debug("fahr %f to cel :%f, expect %f, ret = %f", fahrs[i], fahrtocel(fahrs[i]), cels[i], fabsf(fahrtocel(fahrs[i]) - cels[i]));
		assert(fabsf(fahrtocel(fahrs[i]) - cels[i]) <= 0.00001);
		debug("cel %f to fahr :%f, expect %f, ret = %f", cels[i], celtofahr(cels[i]), fahrs[i], fabsf(celtofahr(cels[i]) - fahrs[i]));
		assert(fabsf(fahrs[i] - celtofahr(cels[i])) <= 0.00001);
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
