section .text
	global ft_strdup
	extern malloc
	extern __errno_location

ft_strdup:
	cmp rdi, 0
	je .error

	mov rsi, rdi
	xor rcx, rcx

.len_loop:
	cmp byte [rsi + rcx], 0
	je .allocate
	inc rcx
	jmp .len_loop

.allocate:
	inc rcx ; +1 '\0'
	mov rdi, rcx
	call malloc
	test rax, rax ; if malloc returns error
	je .error
	
	mov rdi, rax ; char * dest

	xor rcx, rcx ; rcx (i) == 0

.copy_loop:
	mov al, [rsi + rcx]
	mov [rdi + rcx], al
	inc rcx
	test al, al
	jne .copy_loop

	ret

.error:
	call __errno_location
	test rax, rax
	je .return_null
	mov dword [rax], 12

.return_null:
	xor rax, rax
	ret
