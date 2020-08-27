# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pablo <pablo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/27 14:07:45 by pablo             #+#    #+#              #
#    Updated: 2020/08/27 14:07:49 by pablo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

			section	.text
			global	ft_strcpy

; delete RDX, RCX, RAX

ft_strcpy:          ; des = rdi, src = rsi
        mov rdx,0
        mov rcx,0
        cmp rsi, 0
        jz null
        jmp copy

increment:
        inc rdx

copy:
        mov cl, BYTE[rsi + rdx]
        cmp cl, 0
        jz null
        mov BYTE[rdi + rdx], cl
        jmp increment

null:
        mov BYTE [rdi + rax], 0
        mov rax, rdi
        ret
