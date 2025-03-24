section .text
	global ft_read
	extern __errno_location

ft_read:
	mov rax, 0
	syscall
	cmp rax, 0
	jns .done ; jump not signe(pos)

	neg rax ;abs value
	mov rdi, rax
	call __errno_location
	mov [rax], rdi ;save err code in __errno
	mov rax, -1

.done:
	ret
