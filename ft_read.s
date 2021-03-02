
section   .text
global _ft_read
extern ___error
_ft_read:
        mov			rax, 0x2000003			; system call for read
        syscall								; invoke operating system to do the read
		jz error							; if syscall returns negative value jump to error
		ret

error:
	mov rdx, rax							; copy rax to rdx
	push rdx								; push rdx to the stack
	call ___error							; call ___error
	pop rdx									; obtain rdx from the stack
	mov [rax], rdx							; put rdx value where rax points
	mov rax, -1								; set rax value to -1
	ret
