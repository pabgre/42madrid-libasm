#include "main_test.h"

int		main()
{
	int		tot;
	int		corr;
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
	test_ft_write();
	test_ft_read();
	test_ft_strdup();
	tot = total(0);
	corr = correct(0);
	printf(MAGNETA"\nMAIN TEST COMPEATED!!! RESULT ---> " RESET);
	tot == corr ? printf(GREEN "OK") : printf(RED "FAIL");
	RESULT(corr, tot);
	printf(RESET);
	return (0);
}
