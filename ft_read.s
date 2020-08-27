# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pablo <pablo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/27 12:39:38 by pablo             #+#    #+#              #
#    Updated: 2020/08/27 13:59:21 by pablo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

        global ft_read
        section   .text

ft_read: 
        mov       rax, 0                  ; system call for read
        syscall                           ; invoke operating system to do the read
        cmp rax, -1
        ret
