section .text
	global ft_strcmp

ft_strcmp:
	push rbp
	mov rbp, rsp
	xor rax, rax

comparison:
	mov dl, [rdi]
	mov cl, [rsi]	
	cmp dl, 0
	je end_of_string
	cmp cl, 0
	je end_of_string
	cmp dl, cl
	jg dl_bigger
	jb cl_bigger

loop:
	inc rdi
	inc rsi
	mov dl, [rdi]
	mov cl, [rsi]
	cmp dl, 0
	je end_of_string
	cmp cl, 0
	je end_of_string
	cmp dl, cl
	je loop
	jg dl_bigger
	jb cl_bigger

dl_bigger:
	mov rax, 1
	jmp done

cl_bigger:
	mov rax, -1
	jmp done

equal:
	mov rax, 0
	jmp done

end_of_string:
	cmp dl, cl
	jg dl_bigger
	jb cl_bigger
	je equal

done:
	mov rsp, rbp
	pop rbp
	ret
