#include "main_test.h"

void		test_ft_strdup_results(char *src, char *example)
{
	char		cat[1000] = "ft_strdup(";
	size_t		r1,r2;
	char		*str1, *str2;

	strcat(cat, example);
	strcat(cat, ")");
	TEST(-40, cat);
	str1 = ft_strdup(src);
	str2 = strdup(src);
	r1 = ft_strlen(str1);
	r2 = ft_strlen(str2);
	printf(YELLOW "%-25d" RESET, (int)r1);
	printf(MAGNETA "%-22d" RESET, (int)r2);

	show_result(r1, r2);
	free(str1);
	free(str2);
	printf("\n");
}

void		test_ft_strdup()
{

	HEADER("FT_STRDUP");
	test_ft_strdup_results("", "\"\"");
	test_ft_strdup_results("\0FIZZ", "\"\\0FIZZ\"");
	test_ft_strdup_results("FIZZ", "\"FIZZ\"");
	test_ft_strdup_results("FIZZ @ BUZZ", "\"FIZZ @ BUZZ\"");
	test_ft_strdup_results("FIZZ \0 BUZZ", "\"FIZZ \\0 BUZZ\"");
	test_ft_strdup_results("FIZZ 0 BUZZ", "\"FIZZ 0 BUZZ\"");
	test_ft_strdup_results("12345054321", "\"12345054321\"");
}
