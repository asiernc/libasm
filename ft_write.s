section .text
	global _ft_write	
	extern ___error		;

_ft_write:
	mov rax, 0x2000004	;
	syscall
	cmp rax, 0
	jge .done

	mov rdi, rax
	call ___error
	mov [rax], rdi
	mov rax, -1

.done:
	ret
