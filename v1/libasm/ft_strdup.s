section .text
	extern malloc
	global ft_strdup

ft_strdup:
	push rbp
	mov rbp, rsp
	xor rdx, rdx

count:
	cmp [rdi + rdx], byte 0
	je allocate
	inc rdx
	jmp count

allocate:
	inc rdx
	push rdi
	mov rdi, rdx
	call malloc wrt ..plt
	cmp rax, 0
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
