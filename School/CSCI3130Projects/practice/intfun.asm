/* Practice with ints */

.text
.global main

main:
		mov	$1, %rax
		mov	$1, %rdi
		mov	$x, %rsi
		mov	$4, %rdx
		syscall

		mov	$60, %rax
		mov	$0, %rdi
		syscall

.data
x:	.byte 5
