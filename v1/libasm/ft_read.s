section .text
	extern __errno_location
	global ft_read

ft_read:
	push rbp
	mov rbp, rsp

read:
	mov rax, 0
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
