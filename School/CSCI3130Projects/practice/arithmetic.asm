/* Practice with x86_64 Intel Assembly (GAS syntax) */

.global main

.data
intf:	.ascii "%ld\n\0"
x:	.quad 5
y:	.quad 10
incr:  .quad 1

.text

main:
	mov (x), %rax
	mov (incr), %rbx
	mov (y), %rcx
	
loop:
	cmp %rcx, %rax
	je done
	add %rbx, %rax
	push %rax
	push %rbx
	push %rcx
	mov %rax, %rsi
	mov $intf, %rdi
	mov $0, %rax
	call printf
	pop %rcx
	pop %rbx
	pop %rax
	jmp loop

done:
	mov %rax, %rsi
	mov $intf, %rdi
	mov $0, %rax
	call printf
	ret
	
