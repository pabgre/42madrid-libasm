/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:43:01 by psan-gre          #+#    #+#             */
/*   Updated: 2021/03/02 11:14:51 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <string.h>
# include <errno.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char	*dst, const char	*src);
int		ft_strcmp(const char	*s1, const char	*s2);
ssize_t	ft_write(int fildes, const void	*buf, size_t nbytes);
ssize_t	ft_read(int fildes, void *buf, size_t nbytes);
char	*ft_strdup(const char	*s1);
#endif
