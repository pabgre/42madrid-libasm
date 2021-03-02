#include "main_test.h"

void		test_ft_strlen_results(char *src, char *example)
{
	char		cat[1000] = "ft_strlen(\"";

	strcat(cat, example);
	strcat(cat, "\")");
	TEST(-40, cat);
	printf(YELLOW "%-25d" RESET, (int)ft_strlen(src));
	printf(MAGNETA "%-22d" RESET, (int)strlen(src));

	show_result(ft_strlen(src),strlen(src));
	printf("\n");
}

void		test_ft_strlen()
{
	HEADER("FT_STRLEN");
	test_ft_strlen_results("", "");
	test_ft_strlen_results("\0FIZZ", "\\0FIZZ");
	test_ft_strlen_results("FIZZ", "FIZZ");
	test_ft_strlen_results("FIZZ @ BUZZ", "FIZZ @ BUZZ");
	test_ft_strlen_results("FIZZ \0 BUZZ", "FIZZ \\0 BUZZ");
	test_ft_strlen_results("FIZZ 0 BUZZ", "FIZZ 0 BUZZ");
	test_ft_strlen_results("12345054321", "12345054321");
}

