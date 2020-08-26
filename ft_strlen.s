# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pablo <pablo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 12:09:31 by pablo             #+#    #+#              #
#    Updated: 2020/08/26 12:10:13 by pablo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

segment .text
global ft_strlen

ft_strlen:
		mov	rax, 0  			;ret value (move 0 into rax register)
		jmp	count
count:
		cmp		BYTE [rdi + rax], 0	; if rdi(s) + rax(indic) = 0
		jz		exit				; end, if not increase de ret value
		inc 	rax
		jmp 	count
exit:
		ret