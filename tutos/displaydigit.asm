section .data
	digit db 0,10

global _start

_start :
	add rax, 55 
	call _printRAXdigit
	mov rax,56	
	call _printRAXdigit
	mov rax, 56
	dec rax
	call _printRAXdigit
	
	mov rax, 60
	mov rdi, 0
	syscall

_printRAXdigit:
	mov [digit], al
	mov rax, 1
	mov rdi, 1
	mov rsi, digit
	mov rdx, 2
	syscall
	ret
