#include "main_test.h"

void		test_ft_read_results(int fd, int fd2, char *buff, size_t nbyte, char *example)
{
	ssize_t		r1, r2;
	char		cat[1000] = "ft_read(";
	char		*msg;
	strcat(cat, example);
	TEST(-40, cat);
	if (fd >= 0 && fd <= 2)
	{
		msg = "[ft_write] : Type something and press enter...\n";
		ft_write(1, msg, ft_strlen(msg));
	}
	r1 = ft_read(fd2, buff, nbyte);
	if (fd2 >= 0 && fd2 <= 2)
	{
		msg = "[write] : Repeat it and press enter...\n";
		ft_write(1, msg, ft_strlen(msg));
	}
	r2 = ft_read(fd, buff, nbyte);

	printf(YELLOW "%-25d" RESET, (int)r1);
	printf(MAGNETA "%-22d" RESET, (int)r2);

	show_result(r1, r2);
	printf("\n");
}

void		test_ft_read()
{
	size_t	nbyte = 4096;
	char	buff[nbyte];
	int		fd, fd2;
	char	*msg;
	char	*fname = "./tests/main/text.txt";

	HEADER("FT_READ ");
	msg = "---- Reading from standart input [stdin 0]----\n";
	ft_write(1, msg, ft_strlen(msg));
	test_ft_read_results(0, 0, buff, nbyte, "0, buff, 4096)");
	msg = "---- Reading from standart output [stdout 1]----\n";
	ft_write(1, msg, ft_strlen(msg));
	test_ft_read_results(1, 1, buff, nbyte, "1, buff, 4096)");
	msg = "---- Reading from standart error [stderr 2]----\n";
	ft_write(1, msg, ft_strlen(msg));
	test_ft_read_results(2, 2, buff, nbyte, "2, buff, 4096)");
	msg = "---- Reading from file ----\n";
	fd = open(fname, O_RDONLY);
	fd2 = open(fname, O_RDONLY);
	ft_write(1, msg, ft_strlen(msg));
	test_ft_read_results(fd, fd2, buff, nbyte, "fd, buff, 4096)");
	test_ft_read_results(-1, -1, buff, nbyte, "-1, buff, 4096)");
	fd = open(fname, O_RDONLY);
	fd2 = open(fname, O_RDONLY);
	test_ft_read_results(fd, fd2, NULL, nbyte, "fd, NULL, 4096)");
	close(fd); close(fd2);
	fd = open(fname, O_RDONLY);
	fd2 = open(fname, O_RDONLY);
	test_ft_read_results(fd, fd2, buff, 0, "fd, NULL, 0)");
	close(fd); close(fd2);
	fd = open(fname, O_RDONLY);
	fd2 = open(fname, O_RDONLY);
	test_ft_read_results(fd, fd2, buff, -1, "fd, NULL, -1)");
	close(fd); close(fd2);
}
