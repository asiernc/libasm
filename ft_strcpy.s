section .text
	global ft_strcpy ;

ft_strcpy:
	test rdi, rdi
	je .done

	mov rax, rsi

.loop:
	cmp byte [rsi], 0
	je .done
	mov al, [rsi]
	mov [rdi], al
	inc rdi
	inc rsi
	jmp .loop

.done:
	mov byte [rdi], 0
	ret
