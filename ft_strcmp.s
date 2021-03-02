
section	.text
global	_ft_strcmp

; delete RDX, RCX, RAX

_ft_strcmp:					; s1 = rdi, s2 = rsi
		mov    rdx, 0		; rdx ~ int i (=0)
		mov    rcx, 0		; rcx ~ char buffer (=0) [we'll use cl]
		cmp rdi, 0			; if (s1 == null)
		jz check			; -> true then go to 'check'
		cmp rsi, 0			; if (s2 == null)
		jz check			; -> true then go to 'check'
		jmp compare			; go to compare [s1 and s2 are okay, let's compare]

increment:
        inc rdx

compare:
        mov cl, BYTE [rdi + rdx]	; copy into cl the byte at position rdx of rdi
        cmp cl, BYTE [rsi + rdx]	; compare cl with the byte of rsi at position rdx
        jnz check					; in case they are not equal, jump to check
        cmp cl, 0					; check if cl is null
        jz check					; jump to check
        mov cl, BYTE [rsi + rdx]	; copy the byte of rsi que are analyzing into cl
        cmp cl, 0					; check if cl is null
        jz check					; jump to check
        jmp increment				; iterate

check:
        movzx	rax, BYTE [rdi + rdx]	; copy a smaller size byte to a bigger, in this case the last byte of rdi checked into rax
		movzx	rbx, BYTE [rsi + rdx]	; same as above instruction but with the last byte of rsi checked copyed into rbx
    	sub		rax, rbx				; substract the value of rbx to rax
		ret
