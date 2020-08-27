# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pablo <pablo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/27 12:39:38 by pablo             #+#    #+#              #
#    Updated: 2020/08/27 13:39:08 by pablo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

        global ft_write
        section   .text

ft_write: 
        mov       rax, 1                  ; system call for write
        syscall                           ; invoke operating system to do the write
        ret
