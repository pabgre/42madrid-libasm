/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:15:33 by psan-gre          #+#    #+#             */
/*   Updated: 2021/03/02 11:52:09 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libasm.h"
#include "test.h"

int		main(int argc, char *argv[])
{
	int		index;

	if (argc > 1)
	{
		index = 1;
		while (index < argc)
		{
			put_test(argv[index]);
			ft_write(1, "\n", 1);
			ft_set_color(NORMAL);
			index++;
		}
	}
	else
	{
		test_strlen();
		test_strcpy();
		test_strdup();
		test_strcmp();
		test_write();
		test_read();
	}
}
