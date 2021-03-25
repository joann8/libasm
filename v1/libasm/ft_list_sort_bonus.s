section .text
	global ft_list_sort

ft_list_sort:   ; rdi = **begin_list , rsi = int(*cmp)()
	push rbp
	mov rbp, rsp
	push rdi
	push rsi

start:
	cmp rdi, 0
	je done
	cmp rsi, 0
	je done
	mov r13, [rdi]   ; r13 = *begin_list
	mov rdi, [rdi]   ; rdi = *begin list
	cmp rdi, 0
	je done
	

loop:	
	mov	r10, [rdi + 8]    ; r10 = lst->next
	cmp r10, 0				
	je done				  ; lst->next == nULL
	push rdi
	push rsi
	mov rcx, rsi          ; store cmp
	mov rsi, [rdi + 8]    ; rsi = lst->next
	mov rsi, [rsi]		  ; rsi = lst->next->data
	mov rdi, [rdi]	      ; rdi = lst->data
	call rcx              ; avec rdi et rsi
	pop rsi
	pop rdi
	cmp rax, 0
	jg unsorted ;rdi >rsi
	jmp sorted	;rdi <= rsi

unsorted:
	mov r11, [r10]       ; r11 = lst->next->data
	mov r12, [rdi]		 ; r12 = lst->data
	mov [rdi], r11 		 ; lst->data = lst->next->data
	mov [r10], r12 		 ; lst->next->data = lst->data
	mov rdi, r13          ; return to beginning of the list
	jmp loop

sorted:
	mov rdi,[rdi + 8] ; move to next element
	jmp loop

done:
	pop rsi
	pop rdi
	mov rsp, rbp
	pop rbp
	ret
