#include "main_test.h"

int			total(int do_add)
{
	static int	counter;

	if (!counter)
		counter = 0;
	if (do_add)
		counter++;
	return (counter);
}

int			correct(int do_add)
{
	static int	counter;

	if (!counter)
		counter = 0;
	if (do_add)
		counter++;
	return (counter);
}

void		show_result(int r1, int r2)
{
	total(1);
	if (r1 == r2)
	{
		correct(1);
		GOOD;
	}
	else
		BAD;
}
