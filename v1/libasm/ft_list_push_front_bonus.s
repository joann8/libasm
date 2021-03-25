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
	push rdi	 ; store *list_start
	push rsi	 ; store *data
	mov rdi, 16
	call malloc wrt ..plt
	pop rsi
	pop rdi
	cmp rax, 0  ; erreur malloc
	je done
	mov rcx, [rsi]
	mov [rax], rcx   ; lst = data
	xor rcx, rcx
	mov rcx, [rdi]
	mov [rax + 8], rcx ; lst->next = list_start
	mov [rdi], rax      ; lst_start = lst
	
done:
	mov rsp, rbp
	pop rbp
	ret
