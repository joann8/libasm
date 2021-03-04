global _start

			section .text
_start :	
			call _question
			call _getname
			call _message
			call _printname

			mov rax, 60
			xor rdi, rdi
			syscall
			
_question:
			mov rax, 1
			mov rdi, 1
			mov rsi, question 
			mov rdx, 19
			syscall
			ret

_getname:
			mov rax, 0
			mov rdi, 0
			mov rsi, name
			mov rdx, 16
			syscall
			ret


_message:
			mov rax, 1
			mov rdi, 1
			mov rsi, message 
			mov rdx, 7 
			syscall
			ret
_printname:
			mov rax, 1
			mov rdi, 1
			mov rsi, name
			mov rdx, 16
			syscall
			ret
	
			section .data
message:	db		"Hello, "
question:	db		"What is your name? "

			section .bss
			name resb 16

