section .text
	extern __errno_location
	global ft_write

ft_write:
	push rbp
	mov rbp, rsp

write:
	mov rax, 1 ; 1 is SYS_WRITE
	syscall
	cmp rax, 0
	jge done

errors:
	push rbx
	mov rbx, rax
	call __errno_location wrt ..plt
	neg rbx
	mov [rax], rbx
	pop rbx
	mov rax, -1

done:
	mov rsp, rbp
	pop rbp
	ret
