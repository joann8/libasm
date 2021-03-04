global _start

			section .text
_start :	
			mov rax, message
			call _print
			mov rax, message2
			call _print
			
			mov rax, 60
			xor rdi, rdi
			syscall

;input : rax as pointer to string
;output : print string at rax

_print:
			push rax
			mov rbx, 0

_printLoop:
			inc rax
			inc rbx
			mov cl, [rax]
			cmp cl, 0
			jne _printLoop

			mov rax, 1
			mov rdi, 1
			pop rsi
			mov rdx, rbx

			syscall
			ret
		

			section .data
message:	db		"Hello, World", 10, 0
message2:	db		"Hello, You", 10, 0

