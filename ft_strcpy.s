section	.text
global	_ft_strcpy

_ft_strcpy:
		mov rdx, 0		;reset value of rdx to 0
		mov rcx, 0		; reset value of rcx to 0
		cmp rsi, 0		; check if rsi is null
		jz null			; if rsi is null, then jump to null
		jmp copy		; else, jump to copy

increment:
		inc rdx

copy:
		mov cl, BYTE[rsi + rdx]		; copy into cl the byte of rsi at index rdx
		cmp cl, 0					; check if cl is null
		jz null						; if cl is null then complete the string with null
		mov BYTE[rdi + rdx], cl		; copy cl into rdi at position rdx
		jmp increment				; iterate

null:
		mov BYTE [rdi + rdx], 0		; set the last byte of rdi as null
		mov rax, rdi				; copy rdi to rax
		ret
