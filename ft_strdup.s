# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pablo <pablo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/27 14:09:06 by pablo             #+#    #+#              #
#    Updated: 2020/08/27 21:09:33 by pablo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.text
			global	ft_strdup
			extern	malloc
            extern ft_strlen

; delete RDX, RCX, RAX and everything that malloc destroy

ft_strdup:									; rdi = src
			cmp		rdi, 0
			jz		error					; src is NULL
            call    ft_strlen
            mov     rcx, rax

allocate_memory:
			inc		rcx						; length++
			push	rdi						; save src
			mov		rdi, rcx
			call	malloc					; rax = _malloc(length)
			pop		rdi						; restore src
			cmp		rax, 0
			jz		error					; malloc return NULL
copy_start:
			mov		rcx, 0				; i = 0
			mov		rdx, 0				; tmp = 0
			jmp		copy_copy

increment:
			inc		rcx
copy_copy:
			mov		dl, BYTE [rdi + rcx]
			mov		BYTE [rax + rcx], dl
			cmp		dl, 0
			jz		return
			jmp		increment
error:
			xor		rax, rax
return:
			ret