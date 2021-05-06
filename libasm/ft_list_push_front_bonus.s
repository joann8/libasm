section .text
	global ft_list_push_front
	extern malloc

ft_list_push_front:   ; rdi = **begin_list , rsi = *data
	push rbp
	mov rbp, rsp
	xor rax, rax

start:
	cmp rdi, 0
	je done
	cmp rsi, 0
	je done
	push rdi	 ; store begin_start
	push rsi	 ; store data
	mov rdi, 16  ; rdi is going to be call by malloc  
	call malloc wrt ..plt
	pop rsi
	pop rdi
	cmp rax, 0  ; erreur malloc
	je done
	mov rcx, [rsi]   ; rcx = *data
	mov [rax], rcx   ; [rax] = lst->data = data
	xor rcx, rcx     
	mov rcx, [rdi]      ; rcx = *begin_list
	mov [rax + 8], rcx  ; lst->next = *begin_list
	mov [rdi], rax      ; *begin_list = rax = lst
	
done:
	mov rsp, rbp
	pop rbp
	ret
