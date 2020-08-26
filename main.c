/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:10:29 by pablo             #+#    #+#             */
/*   Updated: 2020/08/26 17:11:23 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int ft_strlen(char *str);

int ft_strcmp(char *src, char *dest);

char *ft_strcpy(char *dest, const char *src);

int main(){

    printf("\n'%s' tiene una logitud de %d caracteres\n\n", "hola", ft_strlen("hola"));
    
    printf("\n %i \n", ft_strcmp("hola", "juenas"));

    char	buffer[100];

    int i = 0;
	while (i < 100)
		buffer[i++] = 0;

    printf("`%s` (`totorito`)\n", ft_strcpy(buffer, "totorito"));

    printf("`%s`:`%s` = %d\n", "TOTO", NULL, ft_strcmp("TOTO", NULL));
	printf("`%s`:`%s` = %d\n", NULL, "TOTO", ft_strcmp(NULL, "TOTO"));
	printf("`%s`:`%s` = %d\n", NULL, NULL, ft_strcmp(NULL, NULL));


    return (0);
}