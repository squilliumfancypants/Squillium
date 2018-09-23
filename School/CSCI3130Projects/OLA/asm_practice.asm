/* Assignment: OLA2
 * Class: CSCI3130 - 001
 * Filename: asm_program.asm
 * Author: William Hampton
 * Due: 9/20/18
 * Description - x86_64 assembly program that multiplies a sum and a difference. 
 *		 Of the form (W - X) + (Z + Y)
*/

.global main

.text
main:		
		mov $0, %r8			/* r8 will act as loop control */
		mov $arr, %rbx			/* rbx stores the array address */
		
loop:
		cmp $16, %r8			/* while r8 < 16 */
		je done				
		mov (%rbx), %rdi		/* put 1st of current 4 nums in rdi */
		mov $1, %rax			/* print first paren */
		mov $1, %rdi
		mov $oparen, %rsi
		mov $1, %rdx
		syscall
		mov %rdi, %rsi			/* print first number */
		mov $midint, %rdi
		mov $0, %rax
		call printf
		add $8, %rbx			/* add # bytes to address of arr */
		mov (%rbx), %rsi		/* 2nd of current 4 nums in rsi */
		mov $1, %rax			/* minus sign using a system call */
		mov $1, %rdi
		mov $minus, %rsi
		mov $3, %rdx
		syscall
		add $8, %rbx
		mov (%rbx), %rdx		/* 3rd of current 4 nums in rdx */
		add $8, %rbx
		mov (%rbx), %rcx		/* 4th of current 4 nums in rcx */
		add $8, %rbx
		call function			/* calculate */
		mov %rax, %rsi			/* copy result of function to rsi */
		mov $intf, %rdi			/* formatting for printf */
		mov $0, %rax			
		call printf		
		add $4, %r8
		jmp loop

function:
		sub %rsi, %rdi		/* rsi - rdi */
		add %rdx, %rcx		/* rcx + rdx */
		mov %rcx, %rax		/* mov rcx to rax for multiply */
		mul %rdi		/* result of rsi * result is in rax */
		ret

done:
	ret



.data
count:	.quad	0		/* stores position of array */
oparen: .ascii  "(\0"
cparen: .ascii  ")\0"
plus:   .ascii  " + \0"
minus:  .ascii  " - \0"
times:  .ascii  " * \0"
equals: .ascii  " = \0"
midint: .ascii  "%ld\0"		/* used to print a number without newline*/ 
intf:	.ascii  "%ld\n\0"
arr:	.quad	2, 3, 4, 5, 7, 6, 8, 1, 5, 4, 6, 3, 4, 6, 3, 7		/* declare an array of 16 64-bit integers*/
