/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:10:54 by psan-gre          #+#    #+#             */
/*   Updated: 2021/03/02 16:57:49 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libasm.h"
#include "test.h"

void	ft_set_color(enum color hue)
{
	if (hue == RED)
		ft_printf("\033[1;31m");
	else if (hue == GREEN)
		ft_printf("\033[1;32m");
	else if (hue == BLUE)
		ft_printf("\033[1;34m");
	else if (hue == NORMAL)
		ft_printf("\033[0m");
}

void	test_strlen(void)
{

	ft_set_color(GREEN);
	ft_printf("%20s", "//STR_LEN//\n");
	ft_set_color(NORMAL);
	ft_printf("MY LEN : %d\n", ft_strlen("Cansado de lucharCansado de lucharCansado de lucharCansado de lucharCansado de lucharCansado de lucharCansado de luchar"));
	ft_printf("SY LEN : %d\n", strlen("Cansado de lucharCansado de lucharCansado de lucharCansado de lucharCansado de lucharCansado de lucharCansado de luchar"));
	ft_printf("MY LEN : %d\n", ft_strlen("0123456789"));
	ft_printf("SY LEN : %d\n", strlen("0123456789"));
	ft_printf("MY LEN : %d\n", ft_strlen(""));
	ft_printf("SY LEN : %d\n", strlen(""));
}

void	test_strcmp(void)
{
	char *str = "uno";
	char *str2 = "dos";

	ft_set_color(GREEN);
	ft_printf("%20s", "//STR_CMP//\n");
	ft_set_color(NORMAL);
	ft_printf("MY CMP : %d\n", ft_strcmp("", ""));
	ft_printf("SY CMP : %d\n", strcmp("", ""));
	ft_printf("MY CMP : %d\n", ft_strcmp(str, str2));
	ft_printf("SY CMP : %d\n", strcmp(str, str2));
	ft_printf("MY CMP : %d\n", ft_strcmp(str, ""));
	ft_printf("SY CMP : %d\n", strcmp(str, ""));
	ft_printf("MY CMP : %d\n", ft_strcmp(str, "1234567"));
	ft_printf("SY CMP : %d\n", strcmp(str, "1234567"));
}

void	test_strdup(void)
{
	char *dup;

	ft_set_color(GREEN);
	ft_printf("%20s", "//STR_DUP//\n");
	ft_set_color(NORMAL);
	dup = ft_strdup("DUPLICATE THIS fam");
	ft_printf("MY DUP : %s\n", dup);
	free(dup);
	dup = strdup("DUPLICATE THIS fam");
	ft_printf("SY DUP : %s\n", dup);
	free(dup);
	dup = ft_strdup("");
	ft_printf("MY DUP : %s\n", dup);
	free(dup);
	dup = strdup("");
	ft_printf("SY DUP : %s\n", dup);
	free(dup);
}

void	test_strcpy(void)
{
	char dest[42];

	ft_set_color(GREEN);
	ft_printf("%20s","//STR_CPY//\n");
	ft_set_color(NORMAL);
	ft_printf("MY CPY : %s\n", ft_strcpy(dest, "Cansado de sufrir"));
	memset(dest, 0, 42);
	ft_printf("SY CPY : %s\n", strcpy(dest, "Cansado de sufrir"));
	memset(dest, 0, 42);
	ft_printf("MY CPY : %s\n", ft_strcpy(dest, ""));
	memset(dest, 0, 42);
	ft_printf("SY CPY : %s\n", strcpy(dest, ""));
	memset(dest, 0, 42);
}

void	test_write(void)
{
    int fd;
	int	write_errno;

    fd = open("./write.txt", O_TRUNC | O_RDWR | O_CREAT, 0777);
	ft_set_color(GREEN);
	ft_printf("%20s","//FT_WRITE//\n");
	ft_set_color(NORMAL);
	ft_write(1, "MY WRITE : THIS\n", 16);
	write(1, "SY WRITE : THIS\n", 16);
	ft_write(fd, "Written by FT :D", 16);
	write_errno = ft_write(2, ":,(", -1);
	printf("Error check : %d Error code : %d\n", write_errno, errno);
	write_errno = ft_write(-3, ":,(", -1);
	printf("Error check : %d Error code : %d\n", write_errno, errno);
    close(fd);
}

void	test_read(void)
{
	char 	buf[42];
	char	big_buf[19295];
    int		fd;

	fd = open("./read.txt", O_RDONLY);
	ft_set_color(GREEN);
	ft_printf("%20s","//FT_READ//\n");
	memset(buf, 0, 42);
	ft_set_color(BLUE);
	ft_printf("Write something! : ");
	ft_set_color(NORMAL);
	if (ft_read(0, buf, 42))
		ft_printf("\nMy READ : %s\n", buf);
	memset(buf, 0, 42);
	ft_set_color(BLUE);
	ft_printf("Write something! : ");
	ft_set_color(NORMAL);
	if (read(0, buf, 42))
		ft_printf("\nSy READ : %s\n", buf);
	if (ft_read(fd, big_buf, 19295))
		ft_printf("Reading from file :\n%s", big_buf);
	close(fd);
}

void	put_test(char *arg)
{
	if (!strcmp("--len", arg))
		test_strlen();
	else if (!strcmp("--write", arg))
		test_write();
	else if (!strcmp("--dup", arg))
		test_strdup();
	else if (!strcmp("--cpy", arg))
		test_strcpy();
	else if (!strcmp("--cmp", arg))
		test_strcmp();
	else if (!strcmp("--read", arg))
		test_read();
	else
	{
		ft_set_color(RED);
		ft_printf("Invalid argument : %s\n", arg);
		return ;
	}
}
