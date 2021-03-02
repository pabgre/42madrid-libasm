#include "main_test.h"

void		test_ft_write_results(int fd, char *src, int len, char *example)
{
	char		cat[1000] = "ft_write(";
	int			r1, r2;



	r1 = ft_write(fd, src, len);
	printf("--->ft_write\n--->write");
	r2 = write(fd, src, len);

	printf("\n");
	strcat(cat, example);
	TEST(-50, cat);
	printf(YELLOW "%-15d" RESET, r1);
	printf(MAGNETA "%-22d" RESET, r2);

	show_result(r1, r2);
	printf("\n");

}

void		test_ft_write()
{
	char	*buff;

	HEADER("FT_WRITE");

	buff = "FIZZ";
	test_ft_write_results(1, buff, ft_strlen(buff), "1, \"FIZZ\", ft_strlen(\"FIZZ\"))");
	buff = "FIZZ\0&BUZZ";
	test_ft_write_results(1, buff, ft_strlen(buff), "1, \"FIZZ\\0&BUZZ\",ft_strlen(\"FIZZ\\0&BUZZ\"))");
	buff = "FIZZ\0&BUZZ";
	test_ft_write_results(1, buff, 7, "1, \"FIZZ\\0&BUZZ\", 7))");
	buff = "FIZZ";
	test_ft_write_results(-1, buff, ft_strlen(buff), "-1, \"FIZZ\", ft_strlen(\"FIZZ\"))");
	test_ft_write_results(1, NULL, ft_strlen(buff), "1, NULL, ft_strlen(\"FIZZ\"))");
	test_ft_write_results(1, buff, -1, "1, \"FIZZ\", -1)");
	test_ft_write_results(-1, NULL, -1, "1, NULL, -1)");
}
