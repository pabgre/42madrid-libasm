#include "main_test.h"

void		test_ft_strcmp_results(char *s1, char *s2, char *example1, char *example2)
{
	char		cat[1000] = "ft_strcmp(";

	strcat(cat, example1);
	strcat(cat, "\", ");
	strcat(cat, example2);
	strcat(cat, "\")");
	TEST(-38, cat);
	printf(YELLOW "%-25d" RESET, ft_strcmp(s1, s2));
	printf(MAGNETA "%-23d" RESET, strcmp(s1, s2));

	show_result(ft_strcmp(s1, s2),strcmp(s1, s2));
	printf("\n");
}

void		test_ft_strcmp()
{
	HEADER("FT_STRCMP");
	test_ft_strcmp_results("\200", "\0" ,"\\200", "\\0");
	test_ft_strcmp_results("\0", "\200" ,"\\0", "\\200");
	test_ft_strcmp_results("FIZZ", "FIZZ", "FIZZ", "FIZZ");
	test_ft_strcmp_results("FIZZ", "BUZZ", "FIZZ", "BUZZ");
	test_ft_strcmp_results("FIZZ\0BUZZ", "FIZ\0ZBUZZ", "FIZZ\\0BUZZ", "FIZ\\0ZBUZZ");
	test_ft_strcmp_results("\x12\xff", "\x12\xff", "\\x12\\xff", "\\x12\\xff");
	test_ft_strcmp_results("\x12\xff", "\x12\0", "\\x12\\ff", "\\x12\\0");
	test_ft_strcmp_results("\x12\0", "\x12\xff", "\\x12\\0",  "\\x12\\ff");
}
