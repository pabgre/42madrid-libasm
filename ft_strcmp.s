section	.text
global	ft_strcmp

; delete RDX, RCX, RAX

ft_strcmp:					; s1 = rdi, s2 = rsi
         mov    rdx, 0      ; rdx ~ int i (=0)
         mov    rcx, 0      ; rcx ~ char buffer (=0) [we'll use cl]
         cmp rdi, 0         ; if (s1 == null)       
         jz check           ; -> true then go to 'check'
         cmp rsi, 0         ; if (s2 == null)
         jz check           ; -> true then go to 'check'
         jmp compare        ; go to compare [s1 and s2 are okay, let's compare]

increment:                  ; increment i
        inc rdx

compare:
        mov cl, BYTE [rdi + rdx]
        cmp cl, BYTE [rsi + rdx]
        jnz check
        cmp cl, 0
        jz check
        mov cl, BYTE [rsi + rdx]
        cmp cl, 0
        jz check
        jmp increment

equal:
        mov rax, 0
        ret
inferior:
        mov rax, -1
        ret
greater:
        mov rax, 1
        ret


check:
        cmp rdi, rsi
        jz equal
        jg greater
        jmp inferior