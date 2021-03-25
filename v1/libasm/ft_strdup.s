section .text
	extern malloc
	global ft_strdup

ft_strdup:
	push rbp
	mov rbp, rsp
	xor rdx, rdx ; set rdx to 0

count:
	cmp [rdi + rdx], byte 0 ; rdi is the 1st arg = str
	je allocate
	inc rdx
	jmp count

allocate:
	inc rdx
	push rdi ; save str on the stack
	mov rdi, rdx
	call malloc wrt ..plt
	cmp rax, 0 ; verifier retour de malloc non null
	je done
	pop rdi
	xor rcx, rcx
	xor sil, sil

copy:
	cmp [rdi + rcx], byte 0
	je zero
	mov sil, [rdi  + rcx]
	mov [rax + rcx], sil
	inc rcx
	jmp copy

zero:
	mov[rax + rcx], byte 0

done:
	mov rsp, rbp
	pop rbp
	ret
