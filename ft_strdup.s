section .text
	global ft_strdup
	extern malloc
	extern __errno_location

ft_strdup:
	push rbx
	cmp rdi, 0
	je .error
		
	mov rbx, rdi ; rdx original src
	xor rcx, rcx;

.len_loop:
	cmp byte [rbx + rcx], 0
	je .allocate
	inc rcx
	jmp .len_loop

.allocate:
	inc rcx
	mov rdi, rcx
	call malloc wrt ..plt
	test rax, rax ;
	je .error
	
	mov rdi, rax ; char * dest
	mov rsi, rbx ; 
	
	xor rcx, rcx ;

.copy_loop:
	mov al, [rsi + rcx]
	mov [rdi + rcx], al
	inc rcx
	cmp al, 0
	jne .copy_loop

	mov rax, rdi
	pop rbx
	ret

.error:
	call __errno_location wrt ..plt
	mov dword [rax], 12
	xor rax, rax
	pop rbx

	ret


