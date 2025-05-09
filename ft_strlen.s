section .text
	global ft_strlen ;

ft_strlen:
	test rdi, rdi
	je .pointer_is_null
	xor rax, rax

.loop:
	cmp byte [rdi], 0
	je .done
	inc rax
	inc rdi	
	jmp .loop

.done:
	ret

.pointer_is_null:
	ret