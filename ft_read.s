section .text
	global ft_read
	extern __errno_location

ft_read:
	mov rax, 0
	syscall
	cmp rax, 0
	jl .handle_error

	ret

.handle_error:
	push rax;

	call __errno_location wrt ..plt
	mov rdi, rax
	pop     rax             ; restore syscall result (-errno)
    neg     rax             ; get positive errno value
    mov     [rdi], eax      ; set errno

    mov     rax, -1
    ret
