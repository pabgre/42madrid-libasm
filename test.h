#ifndef TEST_H
# define TEST_H
# include "libftprintf.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
enum color{
	RED, GREEN, BLUE, NORMAL
};

void	ft_set_color(enum color hue);
void	test_strlen();
void	test_strcmp();
void	test_strdup();
void	test_strcpy();
void	test_write();
void	test_read();
void	put_test(char *arg);



#endif
