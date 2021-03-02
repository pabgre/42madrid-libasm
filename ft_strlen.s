segment .text
global _ft_strlen

_ft_strlen:
		mov	rax, 0  			;reset rax value to 0
		jmp	count				;jump to count
count:
		cmp		BYTE [rdi + rax], 0	; check if rdi(s) + rax(indic) = 0
		jz		exit				; if the above contition is true, then jump to exit
		inc 	rax					; increment rax
		jmp 	count				; jump again to count
exit:
		ret
