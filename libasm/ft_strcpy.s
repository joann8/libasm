section .text
	global ft_strcpy

ft_strcpy:
	push rbp
	mov rbp, rsp
	xor rdx, rdx ; set rdx to 0

copy:
	cmp [rsi + rdx], byte 0 ; rsi is the 2nd arg = src
	je done
	mov cl, [rsi + rdx]
	mov [rdi + rdx], cl ; rdi is the first arg = dest
	inc rdx
	jmp copy

done:	
	mov [rdi + rdx], byte 0
	mov rax, rdi
	mov rsp, rbp
	pop rbp
	ret
