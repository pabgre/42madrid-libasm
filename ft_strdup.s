section	.text
global	_ft_strdup
extern	_malloc
extern _ft_strlen


_ft_strdup:									; rdi = src
			cmp		rdi, 0					; check if rdi is NULL
			jz		error					; if rdi is NULL jump to error
			call	_ft_strlen				; calculate length of src
			mov		rcx, rax				; store length on rcx

allocate_memory:
			inc		rcx						; increment length by 1 in order to put the '0' at the end
			push	rdi						; save src on the stack
			mov		rdi, rcx				; copy lenght into rdi
			call	_malloc					; call malloc to allocate memory in rax [rax = _malloc(length)]
			pop		rdi						; restore src
			cmp		rax, 0					; check if rax is the null pointer
			jz		error					; if malloc returned the null pointer jump to error
copy_start:
			mov		rcx, 0				; i = 0
			mov		rdx, 0				; tmp = 0
			jmp		copy_copy

increment:
			inc		rcx
copy_copy:
			mov		dl, BYTE [rdi + rcx]	; copy the byte of rdi at position rcx to dl
			mov		BYTE [rax + rcx], dl	; copy the content of dl into rax at position rcx
			cmp		dl, 0					; compare if dl was null
			jz		return					; if dl was null, we are done
			jmp		increment				; else, jump to increment and iterate
error:
			mov		rax, 0
return:
			ret
