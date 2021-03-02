#ifndef MAIN_TEST_H
# define MAIN_TEST_H
# include "../libasm.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[0;33m"
# define BLUE_BOLD "\e[1;34m"
# define BLUE "\e[0;34m"
# define MAGNETA "\e[1;35m"
# define GRAY "\e[1;30m"
# define RESET "\e[0m"
# define PADD0	RED	 "########################"RESET
# define PADD1	BLUE_BOLD"----- TEST -----\t\t"RESET
# define PADD2	YELLOW"----- YOURS -----\t"RESET
# define PADD3	MAGNETA"----- EXPECTED -----\t"RESET
# define PADD4	GREEN"----- RESULT -----\t"RESET
# define TEST(x, y) printf(BLUE "%*s" RESET, x, y);
# define HEADER(x) printf("\n\n\t"PADD0 RED "\t%s\t" PADD0 "\n\n" PADD1 PADD2 PADD3 PADD4"\n\n", x);
# define GOOD printf(GREEN"[ √ ]"RESET)
# define BAD printf(RED"[ X ]"RESET)
# define RESULT(x, y) printf(": %d of %d\n", x, y)

void			show_result(int r1, int r2);
int				total(int do_add);
int				correct(int do_add);
void			test_ft_strlen(void);
void			test_ft_strcpy(void);
void			test_ft_strcmp(void);
void			test_ft_write(void);
void			test_ft_read(void);
void			test_ft_strdup(void);

# endif
