#include "main_test.h"

void		test_ft_strcpy_results(char *src, char *example)
{
	char		dst[100];
	char		cat[1000] = "ft_strcpy(";

	strcat(cat, "dst,\"");
	strcat(cat, example);
	strcat(cat, "\")");
	TEST(-35, cat);
	printf(YELLOW "%-25s" RESET, ft_strcpy(dst, src));
	printf(MAGNETA "%-27s" RESET, strcpy(dst,src));
	show_result(ft_strlen(src),strlen(src));
	printf("\n");
}

void		test_ft_strcpy()
{
	HEADER("FT_STRCPY");
	test_ft_strcpy_results("", "");
	test_ft_strcpy_results("\0FIZZ", "\\0FIZZ");
	test_ft_strcpy_results("FIZZ", "FIZZ");
	test_ft_strcpy_results("FIZZ @ BUZZ", "FIZZ @ BUZZ");
	test_ft_strcpy_results("FIZZ \0 BUZZ", "FIZZ \\0 BUZZ");
	test_ft_strcpy_results("FIZZ 0 BUZZ", "FIZZ 0 BUZZ");
	test_ft_strcpy_results("12345054321", "12345054321");
}
