section .text
	global ft_strcmp ;

ft_strcmp:
	xor rax, rax	

.loop:
	mov al, [rdi]	; rdi es un puntero (64bits) a s1[0], contiene una direccion de memoria, lo que hacemos al mover el contenido de rdi ([rdi]) a al (que es un valor de rax (64bits) al es su menor tamano (8bits) perfecto para el char)
	mov dl, [rsi]	
	cmp al, dl		
	jne .done		; if not equal (son diferentes valores => terminamos)
	test al, al		; miramos si al (s1[i]) = '\0' porque habra terminado
	je 	.done 		; hemos terminado
	inc rdi			;
	inc	rsi			;
	jmp	.loop		;		


.done:
	sub al, dl		; al - dl in al ==> s1 - s2 resultado en s1
	movsx rax, al	; reconvertimos al (8bits) a rax (64bits)
	ret				
