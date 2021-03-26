section .text
	global ft_list_size

ft_list_size: ; rdi = begin_list
	push rbp
	mov rbp, rsp
	xor rax, rax
	cmp rdi, 0
	je done

loop:
	inc rax
	mov rdi, [rdi + 8] ; begin = begin.next
	cmp rdi, 0
	jne loop

done:
	mov rsp, rbp
	pop rbp
	ret
