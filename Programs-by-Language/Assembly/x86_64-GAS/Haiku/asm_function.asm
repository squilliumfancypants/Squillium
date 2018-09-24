/*Assignment: OLA1
 *Class: CSCI3130 - 001
 *Filename: asm_function.asm
 *Author: William Hampton
 *Date: 9/4/18
 *Description: x86_64 assembly function that prints a message to stdout. called by a C program
*/

.global asm_function
.text

asm_function:
			mov %rdi, %rbx
			mov $0, %r12			# holds string length
			ret
/*

loop:
			mov (%rdi), %rax		# copy current char into rax
			cmp $0, %rdi			# look for end of string char 
			je loop_exit		
			inc %r12			# increment char count 
			inc %rdi			# increment the adderess of array of chars 
			jmp loop

loop_exit:
			mov %r12, %rdx			# copy # of bytes into rdx
			mov %rbx, %rsi			# copy the contents of rdi (the haiku) into rsi
			mov $1, %rax			# syscall 1 is write 
			mov $1, %rdi			# file handle 1 is stdout
			syscall				# invoke the os to print to stdout
			ret				# return control to the calling function
*/
