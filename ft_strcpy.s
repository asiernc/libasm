section .text
	global ft_strcpy ;

ft_strcpy:
	; rdi => dest
	; rsi => src
	test rdi, rdi
	je .done_empty
	test rsi, rsi
	je .done_empty
	mov rax, rdi

.loop:
	mov al, [rsi]
	mov [rdi], al
	inc rdi
	inc rsi
	test al, al
	jmp .loop

.done:
	ret

.done_empty:
	xor rax, rax
	ret
