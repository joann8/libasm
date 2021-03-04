section .text
	global ft_strlen

ft_strlen:
	push rbp    ;rbp = frame pointer, saved on the stack to remember last position before function call
	mov rbp, rsp    ;rsp = stack pointer, last position before entering function
	xor rax, rax   ; 0 the register (computes the bitwise of rax an rax hence 0 everywhere)
	cmp [rdi], byte 0   ;cmp value at rdi with byte 0
	je done
		
loop:
	inc rax
	inc rdi
	cmp [rdi], byte 0
	jne loop

done:
	mov rsp, rbp ; rbp = frame pointer, last position before calling anyother function
	pop rbp ;go back to the pointer saved on the stack before function call
	ret
